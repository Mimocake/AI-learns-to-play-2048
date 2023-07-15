#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Screen
{
private:
	Font font;
	vector<vector<RectangleShape>> rect;
	vector<vector<Text>> txt;
	RectangleShape score_rect;
	Text SCORE;
	Text actual_score;
	RectangleShape best_in_gen_rect;
	Text BEST_IN_GEN;
	Text actual_best_in_gen;
	Text gameover;
	RectangleShape gen_rect;
	Text GEN;
	Text actual_gen;
	RectangleShape bot_rect;
	Text BOT;
	Text actual_bot;
	RectangleShape game_rect;
	Text GAME;
	Text actual_game;
public:
	Screen();
	void set_screen(const vector<vector<int>>&, int score);
	void set_bot_and_gen(int, int, int, int);
	void display(RenderWindow*);
	void game_over(RenderWindow*);
};