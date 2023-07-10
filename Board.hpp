#pragma once
#include <vector>
#include <ctime>
using namespace std;

class Board
{
public:	
	vector<vector<int>> tiles;
	Board();
	void new_step();
	void move_up();
	void move_down();
	void move_left();
	void move_right();
};