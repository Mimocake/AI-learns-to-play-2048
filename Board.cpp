#include "Board.hpp"
#include "Other.hpp"

Board::Board()
{
	srand(time(NULL));
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
	struct uv
	{
		int x, y;
		uv() {}
		uv(int xx, int yy) : x(xx), y(yy) {}
	};
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
	if (empty.size())
	{
		int ran = rand() % empty.size();
		tiles[empty[ran].x][empty[ran].y] = (int)rand() % 10 == 0 ? 4 : 2;
	}
}

void Board::move_down()
{
	compress(tiles);
	merge(tiles);
	compress(tiles);
}

void Board::move_up()
{
	tiles = rotate(tiles, 90);
	tiles = rotate(tiles, 90);
	compress(tiles);
	merge(tiles);
	compress(tiles);
	tiles = rotate(tiles, 90);
	tiles = rotate(tiles, 90);
}

void Board::move_left()
{
	tiles = rotate(tiles, -90);
	compress(tiles);
	merge(tiles);
	compress(tiles);
	tiles = rotate(tiles, 90);
}

void Board::move_right()
{
	tiles = rotate(tiles, 90);
	compress(tiles);
	merge(tiles);
	compress(tiles);
	tiles = rotate(tiles, -90);
}
