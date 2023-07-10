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
public:
	Screen();
	void set_screen(const vector<vector<int>>&);
	void display(RenderWindow*);
};