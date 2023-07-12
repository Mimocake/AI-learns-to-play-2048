#include "Board.hpp"
#include "Screen.hpp"
#include "Network.hpp"

int main()
{
    RenderWindow window(VideoMode(900, 1020), L"2048", Style::Close);
    Board board;
    board.new_step();
    board.new_step();
    Screen screen;
    screen.set_screen(board.tiles, board.score);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) 
            {
            case Event::Closed: window.close(); break;
            case Event::KeyPressed:
                if (event.key.code == Keyboard::W)
                {
                    vector<vector<int>> t = board.tiles;
                    board.move_up();
                    if (t != board.tiles)
                    {
                        uv xy = board.new_step();
                        screen.set_screen(board.tiles, board.score);
                    }
                    if (board.num_of_empty <= 0)
                    {
                        Board temp = board;
                        temp.move_down();
                        temp.move_left();
                        temp.move_right();
                        temp.move_up();
                        if (board.tiles == temp.tiles)
                        {
                            screen.game_over(&window);
                        }
                    }
                }
                else if (event.key.code == Keyboard::S)
                {
                    vector<vector<int>> t = board.tiles;
                    board.move_down();
                    if (t != board.tiles)
                    {
                        uv xy = board.new_step();
                        screen.set_screen(board.tiles, board.score);
                    }
                    if (board.num_of_empty <= 0)
                    {
                        Board temp = board;
                        temp.move_down();
                        temp.move_left();
                        temp.move_right();
                        temp.move_up();
                        if (board.tiles == temp.tiles)
                        {
                            screen.game_over(&window);
                        }
                    }
                }
                else if (event.key.code == Keyboard::A)
                {
                    vector<vector<int>> t = board.tiles;
                    board.move_left();
                    if (t != board.tiles)
                    {
                        uv xy = board.new_step();
                        screen.set_screen(board.tiles, board.score);
                    }
                    if (board.num_of_empty <= 0)
                    {
                        Board temp = board;
                        temp.move_down();
                        temp.move_left();
                        temp.move_right();
                        temp.move_up();
                        if (board.tiles == temp.tiles)
                        {
                            screen.game_over(&window);
                        }
                    }
                }
                else if (event.key.code == Keyboard::D)
                {
                    vector<vector<int>> t = board.tiles;
                    board.move_right();
                    if (t != board.tiles)
                    {
                        uv xy = board.new_step();
                        screen.set_screen(board.tiles, board.score);
                    }
                    if (board.num_of_empty <= 0)
                    {
                        Board temp = board;
                        temp.move_down();
                        temp.move_left();
                        temp.move_right();
                        temp.move_up();
                        if (board.tiles == temp.tiles)
                        {
                            screen.game_over(&window);
                        }
                    }
                }
                break;
            }
        }
        window.clear(Color(187, 173, 160));
        screen.display(&window);
    }
    return 0;
}