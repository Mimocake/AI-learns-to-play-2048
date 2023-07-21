#include <vector>
#include <math.h>
#include "Board.hpp"
#include "Other.hpp"
using namespace std;

const float mono = 1;
const float smooth = 0.1;
const float ept = 2.7;
const float max_tile = 1;

int monotonicy(vector<vector<int>>&);

float max_monotonicy(Board);

float smoothness(Board);

float noe_and_max(Board);

float evaluation(Board);

float minimax(Board&, int, float, float, bool, int&);