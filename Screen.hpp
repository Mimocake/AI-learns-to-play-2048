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
	Text gameover;
public:
	Screen();
	void set_screen(const vector<vector<int>>&, int score);
	void display(RenderWindow*);
	void game_over(RenderWindow*);
};