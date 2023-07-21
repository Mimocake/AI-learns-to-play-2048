#include "Minimax.hpp"

int monotonicy(vector<vector<int>>& board)
{
	int ratio = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j < 3; j++)
		{
			if (board[i][j] < board[i][j + 1] && board[i][j] < board[i][j-1]) ratio++;
		}
	}
	return ratio;
}

float max_monotonicy(Board board)
{
	int ratio = -1;
	for (int i = 0; i < 4; i++)
	{
		int t = monotonicy(board.tiles);
		if (ratio < t) ratio = t;
		board.tiles = rotate(board.tiles, 90);
	}
	return ratio * mono;
}

float smoothness(vector<vector<int>>& board)
{
	int ratio = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == board[i][j + 1]) ratio++;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (board[i][j] == board[i + 1][j]) ratio++;
		}
	}
	return ratio * smooth;
}

float noe_and_max(vector<vector<int>>& board)
{
	int noe = 0, max = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (board[i][j] == 0) noe++;
			else if (board[i][j] > max) max = board[i][j];
		}
	}
	return noe * ept + (int)(log(max) / log(2)) * max_tile;
}

float evaluation(Board board)
{
	return max_monotonicy(board) + smoothness(board.tiles) + noe_and_max(board.tiles);
}

float minimax(Board& board, int depth, float alpha, float beta, bool isMove, int& dir)
{
	Board temp = board;
	int emt = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (temp.tiles[i][j] == 0) emt++;
		}
	}
	if (emt == 0)
	{
		cout << "\n\n\n" << temp.tiles[0][0] << " " << temp.tiles[0][1] << " " << temp.tiles[0][1] << " " << temp.tiles[0][3] << " " << endl <<
				temp.tiles[1][0] << " " << temp.tiles[1][1] << " " << temp.tiles[1][1] << " " << temp.tiles[1][3] << " " << endl <<
				temp.tiles[2][0] << " " << temp.tiles[2][1] << " " << temp.tiles[2][1] << " " << temp.tiles[2][3] << " " << endl <<
				temp.tiles[3][0] << " " << temp.tiles[3][1] << " " << temp.tiles[3][1] << " " << temp.tiles[3][3] << " \n\n\n\n";
		temp.move_down();
		temp.move_up();
		temp.move_left();
		temp.move_right();
		if (temp.tiles == board.tiles)
		{
			cout << "\nYEs\n\n";
			return 0;
		}
	}
	if (depth == 0) return evaluation(board);

	if (!isMove)
	{
		float minEval = 2e6;
		int emt = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (temp.tiles[i][j] == 0) emt++;
			}
		}
		if (emt == 0) return minimax(board, depth-1, alpha, beta, true, dir);
		uv vec(0, 0);
		for (int x = 0; x < emt; x++)
		{
			for (int i = vec.x; i < 4; i++)
			{
				for (int j = vec.y; j < 4; j++)
				{
					if (board.tiles[i][j] == 0 && vec.x * 4 + vec.y < i * 4 + j)
					{
						temp = board;
						vec = uv(i, j);
						temp.tiles[i][j] = 2;
						float eval = minimax(temp, depth - 1, alpha, beta, true, dir);
						minEval = max(minEval, eval);
						alpha = max(alpha, eval);
						if (beta <= alpha) break;
						temp.tiles[i][j] = 4;
						eval = minimax(temp, depth - 1, alpha, beta, true, dir);
						minEval = min(minEval, eval);
					}
				}
			}
		}
		return minEval;
	}
	else
	{
		float maxEval = -2e6;
		for (int i = 0; i < 4; i++)
		{
			temp = board;
			make_move(temp, i);
			float eval = minimax(temp, depth - 1, alpha, beta, false, dir);
			if (eval > maxEval)
			{
				dir = i; 
				maxEval = eval;
			}
		}
		return maxEval;
	}
}
