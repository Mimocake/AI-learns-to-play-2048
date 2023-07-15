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

    best_in_gen_rect.setFillColor(Color(204, 192, 179));
    best_in_gen_rect.setSize(Vector2f(200, 100));
    best_in_gen_rect.setPosition(240, 900);
    BEST_IN_GEN.setFont(font);
    BEST_IN_GEN.setCharacterSize(30);
    BEST_IN_GEN.setString("BEST IN GEN");
    BEST_IN_GEN.setFillColor(Color(238, 228, 218));
    FloatRect textRect4 = BEST_IN_GEN.getLocalBounds();
    BEST_IN_GEN.setOrigin(textRect4.left + textRect4.width / 2.0f,
        textRect4.top + textRect4.height / 2.0f);
    BEST_IN_GEN.setPosition(340, 920);
    actual_best_in_gen.setFont(font);
    actual_best_in_gen.setCharacterSize(45);
    actual_best_in_gen.setString("0");
    actual_best_in_gen.setFillColor(Color(255, 255, 255));
    FloatRect textRect5 = actual_best_in_gen.getLocalBounds();
    actual_best_in_gen.setOrigin(textRect5.left + textRect5.width / 2.0f,
        textRect5.top + textRect5.height / 2.0f);
    actual_best_in_gen.setPosition(340, 960);

    gen_rect.setFillColor(Color(204, 192, 179));
    gen_rect.setSize(Vector2f(200, 100));
    gen_rect.setPosition(460, 900);
    GEN.setFont(font);
    GEN.setCharacterSize(30);
    GEN.setString("GEN");
    GEN.setFillColor(Color(238, 228, 218));
    FloatRect textRect6 = GEN.getLocalBounds();
    GEN.setOrigin(textRect6.left + textRect6.width / 2.0f,
        textRect6.top + textRect6.height / 2.0f);
    GEN.setPosition(560, 920);
    actual_gen.setFont(font);
    actual_gen.setCharacterSize(45);
    actual_gen.setString("0");
    actual_gen.setFillColor(Color(255, 255, 255));
    FloatRect textRect7 = actual_gen.getLocalBounds();
    actual_gen.setOrigin(textRect7.left + textRect7.width / 2.0f,
        textRect7.top + textRect7.height / 2.0f);
    actual_gen.setPosition(560, 960);

    bot_rect.setFillColor(Color(204, 192, 179));
    bot_rect.setSize(Vector2f(70, 100));
    bot_rect.setPosition(680, 900);
    BOT.setFont(font);
    BOT.setCharacterSize(30);
    BOT.setString("BOT");
    BOT.setFillColor(Color(238, 228, 218));
    FloatRect textRect8 = BOT.getLocalBounds();
    BOT.setOrigin(textRect8.left + textRect8.width / 2.0f,
        textRect8.top + textRect8.height / 2.0f);
    BOT.setPosition(715, 920);
    actual_bot.setFont(font);
    actual_bot.setCharacterSize(45);
    actual_bot.setString("1");
    actual_bot.setFillColor(Color(255, 255, 255));
    FloatRect textRect9 = actual_bot.getLocalBounds();
    actual_bot.setOrigin(textRect9.left + textRect9.width / 2.0f,
        textRect9.top + textRect9.height / 2.0f);
    actual_bot.setPosition(715, 960);

    game_rect.setFillColor(Color(204, 192, 179));
    game_rect.setSize(Vector2f(110, 100));
    game_rect.setPosition(770, 900);
    GAME.setFont(font);
    GAME.setCharacterSize(30);
    GAME.setString("GAME");
    GAME.setFillColor(Color(238, 228, 218));
    FloatRect textRect10 = GAME.getLocalBounds();
    GAME.setOrigin(textRect10.left + textRect10.width / 2.0f,
        textRect10.top + textRect10.height / 2.0f);
    GAME.setPosition(825, 920);
    actual_game.setFont(font);
    actual_game.setCharacterSize(45);
    actual_game.setString("1");
    actual_game.setFillColor(Color(255, 255, 255));
    FloatRect textRect11 = actual_game.getLocalBounds();
    actual_game.setOrigin(textRect11.left + textRect11.width / 2.0f,
        textRect11.top + textRect11.height / 2.0f);
    actual_game.setPosition(825, 960);
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
    actual_score.setString(to_string(score));
    FloatRect textRect2 = actual_score.getLocalBounds();
    actual_score.setOrigin(textRect2.left + textRect2.width / 2.0f,
        textRect2.top + textRect2.height / 2.0f);
}

void Screen::set_bot_and_gen(int best, int gen_, int bot_, int game)
{
    actual_best_in_gen.setString(to_string(best));
    FloatRect textRect5 = actual_best_in_gen.getLocalBounds();
    actual_best_in_gen.setOrigin(textRect5.left + textRect5.width / 2.0f,
        textRect5.top + textRect5.height / 2.0f);

    actual_gen.setString(to_string(gen_));
    FloatRect textRect7 = actual_gen.getLocalBounds();
    actual_gen.setOrigin(textRect7.left + textRect7.width / 2.0f,
        textRect7.top + textRect7.height / 2.0f);

    actual_bot.setString(to_string(bot_+1));
    FloatRect textRect9 = actual_bot.getLocalBounds();
    actual_bot.setOrigin(textRect9.left + textRect9.width / 2.0f,
        textRect9.top + textRect9.height / 2.0f);

    actual_game.setString(to_string(game));
    FloatRect textRect11 = actual_bot.getLocalBounds();
    actual_game.setOrigin(textRect11.left + textRect11.width / 2.0f,
        textRect11.top + textRect11.height / 2.0f);
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
    window->draw(best_in_gen_rect);
    window->draw(BEST_IN_GEN);
    window->draw(actual_best_in_gen);
    window->draw(gen_rect);
    window->draw(GEN);
    window->draw(actual_gen);
    window->draw(bot_rect);
    window->draw(BOT);
    window->draw(actual_bot);
    window->draw(game_rect);
    window->draw(GAME);
    window->draw(actual_game);
    window->display();
}

void Screen::game_over(RenderWindow* window)
{
    gameover.setFillColor(Color(119, 110, 101));
    gameover.setOutlineColor(Color(0, 0, 0));
    window->draw(gameover);
    window->display();
}
