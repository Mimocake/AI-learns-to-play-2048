#include "Board.hpp"
#include "Screen.hpp"
#include <iostream>

int main()
{
    RenderWindow window(VideoMode(900, 900), L"2048", Style::Close);
    Font font;
    Text txt("2", font, 80);
    txt.setPosition(200, 200);
    txt.setStyle(Text::Bold);
    if (!font.loadFromFile("ClearSans-Bold.ttf"))
    {
        cout << "font error";
    }
    Board board;
    Screen screen;
    screen.set_screen(board.tiles);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear(Color(187, 173, 160));
        screen.display(&window);
        window.display();
    }
    return 0;
}