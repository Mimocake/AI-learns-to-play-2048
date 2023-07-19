#include "Screen.hpp"
#include "Other.hpp"
#include "windows.h"
#include <math.h>

Screen::Screen()
{
    if (!font.loadFromFile("ClearSans-Bold.ttf"))
    {
        cout << "font error";
    }
    for (int i = 0; i < 4; i++)
    {
        rect.push_back(vector<RectangleShape>(4, RectangleShape(Vector2f(200, 200))));
        txt.push_back(vector<Text>(4, Text("", font, 100)));
        for (int j = 0; j < 4; j++)
        {
            rect[i][j].setFillColor(Color(204, 192, 179));
            rect[i][j].setOutlineColor(Color(187, 173, 160));
            rect[i][j].setOutlineThickness(10);
            rect[i][j].setOrigin(100, 100);
            txt[i][j].setFillColor(Color(119, 110, 101));
            rect[i][j].setPosition(120 + 220 * i, 120 + 220 * j);
        }
    }

    score_rect.setFillColor(Color(204, 192, 179));
    score_rect.setSize(Vector2f(200, 100));
    score_rect.setPosition(20, 900);
    SCORE.setFont(font);
    SCORE.setCharacterSize(30);
    SCORE.setString("SCORE");
    SCORE.setFillColor(Color(238, 228, 218));
    FloatRect textRect = SCORE.getLocalBounds();
    SCORE.setOrigin(textRect.left + textRect.width / 2.0f,
        textRect.top + textRect.height / 2.0f);
    SCORE.setPosition(120, 920);
    actual_score.setFont(font);
    actual_score.setCharacterSize(45);
    actual_score.setString("0");
    actual_score.setFillColor(Color(255, 255, 255));
    FloatRect textRect2 = actual_score.getLocalBounds();
    actual_score.setOrigin(textRect2.left + textRect2.width / 2.0f,
        textRect2.top + textRect2.height / 2.0f);
    actual_score.setPosition(120, 960);
    gameover.setFont(font);
    gameover.setString("Game over!");
    gameover.setCharacterSize(100);
    gameover.setFillColor(Color::Transparent);
    gameover.setOutlineColor(Color::Transparent);
    gameover.setOutlineThickness(10);
    FloatRect textRect3 = gameover.getLocalBounds();
    gameover.setOrigin(textRect3.left + textRect3.width / 2.0f,
        textRect3.top + textRect3.height / 2.0f);
    gameover.setPosition(450, 450);
}

void Screen::set_screen(const vector<vector<int>>& board, int score)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            txt[i][j].setFillColor(board[i][j] > 4 ? Color(249, 246, 242) : Color(119, 110, 101));
            txt[i][j].setString(board[i][j] ? to_string(board[i][j]) : "");
            txt[i][j].setCharacterSize(board[i][j] < 128 ? 100 : (board[i][j] < 1024 ? 80 : 60));
            txt[i][j].setOrigin(txt[i][j].getLocalBounds().width / 2 + 20, 
                txt[i][j].getLocalBounds().height / 2 + 20);
            txt[i][j].setPosition(100 + 220 * i, 100 + 220 * j);
            FloatRect textRect = txt[i][j].getLocalBounds();
            txt[i][j].setOrigin(textRect.left + textRect.width / 2.0f,
                textRect.top + textRect.height / 2.0f);
            txt[i][j].setPosition(sf::Vector2f(120 + 220 * i, 120 + 220 * j));
            rect[i][j].setFillColor(color_picker(board[i][j]));
        }
    }
    gameover.setFillColor(Color::Transparent);
    gameover.setOutlineColor(Color::Transparent);
    actual_score.setString(to_string(score));
    FloatRect textRect2 = actual_score.getLocalBounds();
    actual_score.setOrigin(textRect2.left + textRect2.width / 2.0f,
        textRect2.top + textRect2.height / 2.0f);
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
    window->draw(score_rect);
    window->draw(SCORE);
    window->draw(actual_score);
    window->draw(gameover);
    window->display();
}

void Screen::game_over(RenderWindow* window)
{
    gameover.setFillColor(Color(119, 110, 101));
    gameover.setOutlineColor(Color(0, 0, 0));
    window->draw(gameover);
    window->display();
}
