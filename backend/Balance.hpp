#ifndef BALANCE_H
#define BALANCE_H
#include "BaseClass.hpp"
#include <iostream>
using namespace std;

class Balance : public Base{
	public: 
	void setup();
	bool stateExists(Node currentState);
	double heuristic(Node);
  	bool requireSift(Node initialState);
    bool balanceGoalTest(Node);
};



#endif