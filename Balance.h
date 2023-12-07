#ifndef BALANCE_H
#define BALANCE_H
#include "BaseClass.h"
#include <iostream>
using namespace std;

class Balance : public Base{
	void setup();
	bool stateExists(Node currentState);
	double heuristic();
	bool requireSift(Node initialState);
};



#endif