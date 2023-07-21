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

void make_move(Board& board, int i)
{
	switch (i)
	{
	case 0: board.move_up(); break;
	case 1: board.move_down(); break;
	case 2: board.move_left(); break;
	case 3: board.move_right(); break;
	}
}
