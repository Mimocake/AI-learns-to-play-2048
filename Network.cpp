#include "Network.hpp"

void Neuron::activation() { value = 1 / (1 + pow(e, -value)); }

float Neuron::der() { return value * (1 - value); }

Network::Network(vector<int> layers, bool b) : neurons(layers.size()), connections(layers.size() - 1), bias(b), architecture(layers)
{
	NoL = layers.size();
	for (int i = 0; i < layers.size(); i++)
	{
		neurons[i] = vector<Neuron>(layers[i]);
		for (int j = 0; j < layers[i]; j++)
		{
			neurons[i][j] = Neuron();
		}
	}
	for (int n = 0; n < NoL - 1; n++)
	{
		for (int i = 0; i < layers[n]; i++)
		{
			connections[n].emplace_back(vector<float>());
			for (int j = 0; j < layers[n + 1]; j++)
			{
				connections[n][i].push_back(rand() / 16384.0 - 1);
			}
		}
	}
	if (bias)
	{
		for (int n = 0; n < NoL - 1; n++)
		{
			neurons[n].emplace_back(Neuron());
			neurons[n][neurons[n].size() - 1].value = 1;
			connections[n].emplace_back(vector<float>());
			for (int i = 0; i < neurons[n + 1].size(); i++)
			{
				connections[n][neurons[n].size() - 1].push_back(rand() / 16384.0 - 1);
			}
		}
	}
}

vector<float> Network::signal_passing(vector<float> in)
{
	for (int i = 0; i < neurons[0].size() - bias; i++)
	{ 
		neurons[0][i].value = in[i]; 
	}
	for (int n = 1; n < NoL; n++)
	{
		int d = (n == (NoL - 1)) ? neurons[n].size() : neurons[n].size() - bias;
		for (int i = 0; i < d; i++)
		{
			neurons[n][i].value = 0;
			for (int j = 0; j < neurons[n-1].size(); j++)
			{
				neurons[n][i].value += neurons[n-1][j].value * connections[n-1][j][i];
			}
			neurons[n][i].activation();
		}
	}
	vector<float> res(neurons[NoL-1].size());
	for (int i = 0; i < neurons[NoL - 1].size(); i++) { res[i] = neurons[NoL - 1][i].value; }
	return res;
}

void Network::mutation()
{
	for (int n = 0; n < connections.size(); n++)
	{
		for (int i = 0; i < connections[n].size(); i++)
		{
			for (int j = 0; j < connections[n][i].size(); j++)
			{
				if (rand() % 100 >= mut_rate)
				{
					float randf = (rand() % (mut_rate * 2) - mut_rate) / 100.0 + 1;
					connections[n][i][j] *= randf;
				}
			}
		}
	}
}

Network crossing(Network& n1, Network& n2)
{
	Network temp(n1.architecture, 1);
	for (int n = 0; n < n1.connections.size(); n++)
	{
		for (int i = 0; i < n1.connections[n].size(); i++)
		{
			for (int j = 0; j < n1.connections[n][i].size(); j++)
			{
				if (rand() % 2) temp.connections[n][i][j] = n1.connections[n][i][j];
				else temp.connections[n][i][j] = n2.connections[n][i][j];
			}
		}
	}
	return temp;
}

void Network::store()
{
	ofstream ofile("network.dat", ios::binary | ios::trunc);
	ofile.write((char*)&bias, sizeof(bias));
	ofile.write((char*)&NoL, sizeof(NoL));
	for (int i = 0; i < NoL; i++)
	{
		int n = (i == (NoL - 1)) ? neurons[i].size() : neurons[i].size() - bias;
		ofile.write((char*)&n, sizeof(n));
	}
	for (int n = 0; n < NoL - 1; n++)
		for (int i = 0; i < connections[n].size(); i++)
			for (int j = 0; j < connections[n][i].size(); j++)
				ofile.write((char*)&connections[n][i][j], sizeof(float));
}

void Network::load()
{
	ifstream infile("network.dat", ios::binary);
	bool b;	infile.read((char*)&b, sizeof(b));
	int x; infile.read((char*)&x, sizeof(x));
	vector<int> layers(x);
	for (int i = 0; i < x; i++)
	{
		infile.read((char*)&layers[i], sizeof(int));
	}
	*this = Network(layers, b);
	for (int n = 0; n < NoL - 1; n++)
		for (int i = 0; i < connections[n].size(); i++)
			for (int j = 0; j < connections[n][i].size(); j++)
				infile.read((char*)&connections[n][i][j], sizeof(float));
}
