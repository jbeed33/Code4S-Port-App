#ifndef BASECLASS_H
#define BASECLASS_H

using namespace std;
#include "node.hpp"
#include "helper.hpp"
#include <vector>


class Base{
	public:
		unsigned long expandedNodeCount;
		unsigned int maxQueueSize;
		vector<Node> closed;

		int cost(Node current);
		Node search(vector<vector<Container>> ship, int craneRow, int craneCol, int craneZone, int numToLoad, vector<string> toUnload);

		vector<Node> frontier;
		void nodeExpand(Node current);
		void baseSetup(vector<vector<Container>> ship, int craneRow, int craneCol, int craneZone);
		virtual void setup() = 0;
		virtual bool stateExists() = 0;
		virtual double heuristic() = 0;
};

#endif