#ifndef BALANCE_H
#define BALANCE_H
#include "BaseClass.hpp"
#include <iostream>
using namespace std;

class Balance : public Base{
	void setup();
	bool stateExists(Node currentState);
	double heuristic();
  bool requireSift(Node initialState);
  int balanceGoalTest();
};



#endif