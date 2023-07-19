#include "Other.hpp"

Color color_picker(int i)
{
	switch (i)
	{
	case 0: return Color(204, 192, 179); break;
	case 2: return Color(238, 228, 218); break;
	case 4: return Color(237, 224, 200); break;
	case 8: return Color(242, 177, 121); break;
	case 16: return Color(245, 149, 99); break;
	case 32: return Color(246, 124, 95); break;
	case 64: return Color(246, 94, 59); break;
	case 128: return Color(237, 207, 114); break;
	case 256: return Color(237, 204, 97); break;
	case 512: return Color(237, 200, 80); break;
	case 1024: return Color(237, 197, 63); break;
	case 2048: return Color(237, 194, 46); break;
	default: return Color(0, 0, 0); break;
	}
}

vector<vector<int>> rotate(vector<vector<int>> matrix, int angle)
{
	vector<vector<int>> temp(4, vector<int>(4));
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (angle == -90)
			{
				temp[i][j] = matrix[3 - j][i];
			}
			else if (angle == 90)
			{
				temp[3 - j][i] = matrix[i][j];
			}
		}
	}
	return temp;
}

void compress(vector<vector<int>>& matrix)
{
	for (int i = 0; i < 4; i++)
	{
		for (int n = 0; n < 4; n++)
		{
			for (int j = 3; j > 0; j--)
			{
				if (matrix[i][j] == 0)
				{
					matrix[i][j] = matrix[i][j-1];
					matrix[i][j-1] = 0;
				}
			}
		}
	}
}

void merge(vector<vector<int>>& matrix, int& score)
{
	for (int i = 0; i < 4; i++)
	{
		for (int n = 0; n < 4; n++)
		{
			for (int j = 3 - n; j > 0; j--)
			{
				if (matrix[i][j] == matrix[i][j - 1])
				{
					matrix[i][j - 1] = 0;
					matrix[i][j] *= 2;
					score += matrix[i][j];
				}
			}
		}
	}
}

void sort_vec(vector<float>& vec)
{
	float temp;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (vec[j] < vec[j + 1])
			{
				temp = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = temp;
			}
		}
	}
}

bool choose_move_for_calculus(vector<float> res, Board& board, int& first_dir)
{
	vector<vector<int>> t;
	vector<float> sorted_res = res;
	sort_vec(sorted_res);

	for (int n = 0; n < 4; n++)
	{
		int index = 0;
		for (int i = 0; i < 4; i++)
		{
			if (res[i] == sorted_res[n])
			{
				index = i;
			}
		}
		t = board.tiles;
		switch (index)
		{
		case 0: board.move_up(); break;
		case 1: board.move_down(); break;
		case 2: board.move_left(); break;
		case 3: board.move_right(); break;
		}
		if (t != board.tiles)
		{
			board.new_step();
			if (first_dir == -1)
			{
				first_dir = index;
			}	
			return false;
		}
		else if (n == 3 && board.num_of_empty == 0)
		{
			first_dir = rand() % 4;
			return true;
		}
		else if (n == 3 && board.num_of_empty != 0)
		{
			index = rand() % 4;
			switch (index)
			{
			case 0: board.move_up(); break;
			case 1: board.move_down(); break;
			case 2: board.move_left(); break;
			case 3: board.move_right(); break;
			}
			board.new_step();
		}
	}
	return false;
}

bool choose_move_for_actual_board(Board& real_board)
{
	Board board = real_board;
	bool go = false;
	vector<vector<int>> t;
	vector<float> prior(4);
	int i = 0;
	int first_dir = -1;
	vector<int> tot_score(4, 0);
	vector<int> dir_count(4, 0);
	vector<float> res(4);

	for (int x = 0; x < 1000; x++)
	{
		for (int k = 0; k < 10 && !go; k++)
		{
			for (int j = 0; j < 4; j++)
			{
				prior[j] = rand() % 1000;
			}
			if (choose_move_for_calculus(prior, board, first_dir))
			{
				go = true;
			}
		}
		int temp = board.score;
		board = real_board;
		tot_score[first_dir] += temp - real_board.score;
		dir_count[first_dir]++;
		first_dir = -1;
		go = 0;
	}
	for (int j = 0; j < 4; j++)
	{
		res[j] = tot_score[j] / (float)dir_count[j];
	}

	if (choose_move_for_calculus(res, real_board, i))
	{
		return true;
	}
	else return false;
}
