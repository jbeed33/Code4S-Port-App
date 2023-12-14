#ifndef BALANCE_H
#define BALANCE_H
#include "BaseClass.hpp"

class Balance : public Base{
	void setup();
	bool stateExists();
	double heuristic();
};



#endif