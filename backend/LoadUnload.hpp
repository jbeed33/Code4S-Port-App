#ifndef LOADUNLOAD_H
#define LOADUNLOAD_H

#include "BaseClass.hpp"
#include "node.hpp"

class LoadUnload : public Base{
	void setup(Node&, vector<string>);
	bool stateExists(Node);
	double heuristic(Node);
};

#endif