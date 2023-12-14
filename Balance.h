#ifndef BALANCE_H
#define BALANCE_H
#include "BaseClass.h"

class Balance : public Base{
	void setup();
	bool stateExists();
	double heuristic();
	int balanceGoalTest();
};



#endif