#include "Board.hpp"
#include "Other.hpp"

Board::Board()
{
	for (int i = 0; i < 4; i++)
	{
		tiles.emplace_back(vector<int>());
		for (int j = 0; j < 4; j++)
		{
			tiles[i].emplace_back(0);
		}
	}
	tiles[2][1] = 128;
	tiles[1][3] = 2048;
	tiles[0][0] = 4096;
	tiles[2][2] = 512;
	tiles[3][0] = 4;
	tiles[0][2] = 2;
}
