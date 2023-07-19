#include "Board.hpp"
#include "Screen.hpp"
#include "Other.hpp"
#include <Windows.h>
#include <iostream>

int main()
{
    srand(time(0));
    RenderWindow window(VideoMode(900, 1020), L"2048", Style::Close);
    Board real_board;
    real_board.new_step();
    real_board.new_step();
    Screen screen;
    screen.set_screen(real_board.tiles, real_board.score);
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

        if (choose_move_for_actual_board(real_board))
        {
            go = true;
            screen.set_screen(real_board.tiles, real_board.score);
            screen.game_over(&window);
            screen.display(&window);
            continue;
        }

        window.clear(Color(187, 173, 160));
        screen.set_screen(real_board.tiles, real_board.score);
        screen.display(&window);
    }
    return 0;
}