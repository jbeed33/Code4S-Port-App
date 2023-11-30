#ifndef LOADUNLOAD_H
#define LOADUNLOAD_H

#include "BaseClass.h"

class LoadUnload : public Base{
	void setup();
	bool stateExists();
	double heuristic();
};

#endif