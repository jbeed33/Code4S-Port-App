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
		int numToLoad = 0;
		vector<Node> closed;
		vector<Node> frontier;

		Node search(vector<vector<Container>> ship, int craneRow, int craneCol, int craneZone, int numToLoad, vector<string> toUnload);
		int cost(Node current);
		void nodeExpand(Node);
		void baseSetup(vector<vector<Container>> ship, int craneRow, int craneCol, int craneZone);
		void addToFrontier(Node toAdd);

		virtual void setup() = 0;
		virtual bool stateExists(Node) = 0;
		virtual double heuristic(Node) = 0;
};

#endif