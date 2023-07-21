#include "Board.hpp"
#include "Screen.hpp"
#include "Other.hpp"
#include "Minimax.hpp"
#include <Windows.h>
#include <iostream>

int main()
{
    srand(time(0));
    RenderWindow window(VideoMode(900, 1020), L"2048", Style::Close);
    Board board;
    board.new_step();
    board.new_step();
    Screen screen;
    screen.set_screen(board.tiles, board.score);
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

        if (go) continue;

        int dir;

        float minimax_res = minimax(board, 4, -2e6, 2e6, true, dir);
        cout << minimax_res << endl;
        for (int i = 0; i < 4; i++)
        {
            if (dir == i)
            {
                make_move(board, i);
                board.new_step();
            }
        }

        window.clear(Color(187, 173, 160));
        screen.set_screen(board.tiles, board.score);
        screen.display(&window);
    }
    return 0;
}