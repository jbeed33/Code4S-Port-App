#ifndef LOADUNLOAD_H
#define LOADUNLOAD_H

#include "BaseClass.hpp"
#include "node.hpp"

class LoadUnload : public Base{
	void setup();
	bool stateExists(Node n);
	double heuristic(Node n);
};

#endif