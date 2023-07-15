#include "Network.hpp"
#include "Other.hpp"
#include "Board.hpp"
#include "Screen.hpp"
#include <vector>

class Generation
{
public:
	vector<Network> networks;
	vector<float> score;
	float best_in_gen;
	int gen;
	int bot;
	int game;
	Generation(vector<int>, bool);
	void selection();
};