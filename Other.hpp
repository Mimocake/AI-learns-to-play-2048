#include <SFML/Graphics.hpp>
#include <vector>
#include "Board.hpp"
#include "Screen.hpp"
using namespace std;
using namespace sf;

Color color_picker(int);

vector<vector<int>> rotate(vector<vector<int>>, int);

void compress(vector<vector<int>>&);

void merge(vector<vector<int>>&, int&);

void sort_vec(vector<float>&);

bool choose_move_for_calculus(vector<float>, Board&, int&);

bool choose_move_for_actual_board(Board&);