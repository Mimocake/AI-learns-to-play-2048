#include "Board.hpp"
#include "Other.hpp"

Board::Board() : score(0)
{
	for (int i = 0; i < 4; i++)
	{
		tiles.emplace_back(vector<int>());
		for (int j = 0; j < 4; j++)
		{
			tiles[i].emplace_back(0);
		}
	}
}

void Board::new_step()
{
	vector<uv> empty(0);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (tiles[i][j] == 0)
			{
				empty.push_back(uv(i, j));
			}
		}
	}
	num_of_empty = empty.size() - 1;
	if (empty.size())
	{
		int ran = rand() % empty.size();
		tiles[empty[ran].x][empty[ran].y] = (int)rand() % 10 == 0 ? 4 : 2;
	}
}

void Board::move_down()
{
	compress(tiles);
	merge(tiles, score);
	compress(tiles);
}

void Board::move_up()
{
	tiles = rotate(tiles, 90);
	tiles = rotate(tiles, 90);
	compress(tiles);
	merge(tiles, score);
	compress(tiles);
	tiles = rotate(tiles, 90);
	tiles = rotate(tiles, 90);
}

void Board::move_left()
{
	tiles = rotate(tiles, -90);
	compress(tiles);
	merge(tiles, score);
	compress(tiles);
	tiles = rotate(tiles, 90);
}

void Board::move_right()
{
	tiles = rotate(tiles, 90);
	compress(tiles);
	merge(tiles, score);
	compress(tiles);
	tiles = rotate(tiles, -90);
}
