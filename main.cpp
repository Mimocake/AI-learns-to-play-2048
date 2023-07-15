#include "Board.hpp"
#include "Screen.hpp"
#include "Network.hpp"
#include "Other.hpp"
#include "Generation.hpp"
#include <Windows.h>

int main()
{
    srand(time(0));
    RenderWindow window(VideoMode(900, 1020), L"2048", Style::Close);
    Board board;
    board.new_step();
    board.new_step();
    Screen screen;
    screen.set_screen(board.tiles, board.score);
    vector<int> layers = { 16, 16, 16, 4 };
    Generation generation(layers, 1);
    vector<vector<int>> t;
    vector<int> scores(5, 0);
    bool go = false;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::Closed: window.close(); break;
            }
        }
        if (go) 
        { 
            scores[generation.game - 1] = board.score;
            if (generation.game == 5)
            {
                generation.game = 1;
                int tot_score = 0;
                for (int i = 0; i < 5; i++) tot_score += scores[i];
                generation.score[generation.bot] = tot_score / 5;
                if (generation.best_in_gen < tot_score / 5) generation.best_in_gen = tot_score / 5;
                if (generation.bot == 15)
                {
                    generation.gen++;
                    generation.selection();
                    generation.bot = 0;
                    generation.best_in_gen = 0;
                }
                else generation.bot++;
            }
            else generation.game++;
            go = false;
            board = Board();
            board.new_step();
            board.new_step();
            screen.set_screen(board.tiles, board.score);
            screen.set_bot_and_gen(generation.best_in_gen, generation.gen, generation.bot, generation.game);
            screen.display(&window);
            continue; 
        }
        vector<float> input(16);
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                input[i * 4 + j] = board.tiles[i][j] == 0 ? 0 : (log(board.tiles[i][j]) / log(2)) / 10;
            }
        }
        vector<float> res = generation.networks[generation.bot].signal_passing(input);
        
        if (choose_move(res, board, screen))
        {
            go = true;
            window.clear(Color(187, 173, 160));
            screen.display(&window);
            Sleep(500);
        }

        window.clear(Color(187, 173, 160));
        screen.display(&window);
    }
    return 0;
}