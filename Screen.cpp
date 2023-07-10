#include "Screen.hpp"
#include "Other.hpp"

Screen::Screen()
{
    if (!font.loadFromFile("ClearSans-Bold.ttf"))
    {
        cout << "font error";
    }
    for (int i = 0; i < 4; i++)
    {
        rect.push_back(vector<RectangleShape>(4, RectangleShape(Vector2f(200, 200))));
        txt.push_back(vector<Text>(4, Text("", font, 80)));
        for (int j = 0; j < 4; j++)
        {
            rect[i][j].setFillColor(Color(204, 192, 179));
            rect[i][j].setOutlineColor(Color(187, 173, 160));
            rect[i][j].setOutlineThickness(10);
            txt[i][j].setFillColor(Color(119, 110, 101));
            rect[i][j].setPosition(20 + 220 * i, 20 + 220 * j);
        }
    }
}

void Screen::set_screen(const vector<vector<int>>& board)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            txt[i][j].setFillColor(board[i][j] > 4 ? Color(249, 246, 242) : Color(119, 110, 101));
            txt[i][j].setString(board[i][j] ? to_string(board[i][j]) : "");
            txt[i][j].setOrigin(txt[i][j].getLocalBounds().width / 2, txt[i][j].getLocalBounds().height / 2);
            txt[i][j].setPosition(110 + 220 * i, 100 + 220 * j);
            rect[i][j].setFillColor(color_picker(board[i][j]));
        }
    }
}

void Screen::display(RenderWindow* window)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            window->draw(rect[i][j]);
            window->draw(txt[i][j]);
        }
    }
}