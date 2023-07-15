#pragma once
#include <vector>
#include <ctime>
using namespace std;

struct uv
{
	int x, y;
	uv() {}
	uv(int xx, int yy) : x(xx), y(yy) {}
};

class Board
{
public:	
	vector<vector<int>> tiles;
	int num_of_empty;
	int score;
	Board();
	void new_step();
	void move_up();
	void move_down();
	void move_left();
	void move_right();
};