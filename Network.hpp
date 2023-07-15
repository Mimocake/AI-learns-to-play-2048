#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
using namespace std;

const float e = 2.72;
const float r = 0.3;
const int mut_rate = 20;

class Neuron
{
private:
	float value;
	float error;
public:
	Neuron() : value(0), error(0) {}
	void activation();
	float der();
	friend class Network;
};

class Network
{
private:
	bool bias;
	int NoL;
	vector<int> architecture;
	vector<vector<Neuron>> neurons;
	vector<vector<vector<float>>> connections;
public:
	Network(vector<int>, bool);
	vector<float> signal_passing(vector<float>);
	void mutation();
	friend Network crossing(Network&, Network&);
	void store();
	void load();
	friend Neuron;
};