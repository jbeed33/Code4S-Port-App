#ifndef BALANCE_H
#define BALANCE_H
#include "BaseClass.hpp"
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

class Balance : public Base{
	public: 
	vector<vector<int>> siftGoal;
	void setSiftGoal(vector<int>);
	void setup(Node&, vector<string>);
	bool stateExists(Node currentState);
	double heuristic(Node);
	double siftHeuristic(Node);
	bool siftGoalTest(Node);
  	bool requireSift(Node initialState);
    bool balanceGoalTest(Node);
};



#endif