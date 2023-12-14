#ifndef BASECLASS_H
#define BASECLASS_H

using namespace std;

// #include "helper.hpp"
#include "node.hpp"
#include <vector>


class Base{
	public:
		unsigned long expandedNodeCount;
		unsigned int maxQueueSize;
		vector<Node> closed;

		int cost(Node current);
		Node search(vector<vector<Container>> ship, int craneRow, int craneCol, int craneZone, int numToLoad, vector<string> toUnload);

		vector<Node> frontier;
		void nodeExpand(Node);
		void baseSetup(vector<vector<Container>> ship, int craneRow, int craneCol, int craneZone);
		virtual void setup() = 0;
		virtual bool stateExists(Node) = 0;
		virtual double heuristic(Node) = 0;
};

#endif