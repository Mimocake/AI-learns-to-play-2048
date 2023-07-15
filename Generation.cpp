#include "Generation.hpp"

Generation::Generation(vector<int> layers, bool b) : best_in_gen(0), gen(1), bot(0), game(1)
{
	networks = vector<Network>(16, Network(layers, b));
	for (int i = 0; i < networks.size(); i++) networks[i] = Network(layers, b);
	score = vector<float>(networks.size(), 0);
}

void Generation::selection()
{
	float max = 0; int index = 0;
	for (int i = 0; i < networks.size(); i++)
	{
		if (score[i] > max) { max = score[i]; index = i; }
	}
	Network temp = networks[index];
	for (int i = 0; i < networks.size(); i++)
	{
		networks[i] = temp;
		networks[i].mutation();
	}
}