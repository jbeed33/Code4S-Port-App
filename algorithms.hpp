#ifndef ALGORITHMS_H
#define ALGORITHMS_H

using namespace std;
#include "node.hpp";
#include "helper.hpp";
#include <vector>

/*
*	takes the node we are expanding from, the start and end columns, the start and end zones,
*	and if the crane is carrying a container for the current move
*/
int cost(Node current, int startCol, int endCol, int startZone, int endZone, bool justCrane){
	int cost = 0;
	int startTop;
	int endTop;
	int startZoneHeight;
	int endZoneHeight;

	if(0 == startZone){	//Starts on ship
		startTop = findTopShip(current.ship, startCol);
		startZoneHeight = SHIPHEIGHT - 1;
	}
	else if(2 == startZone){	//starts in buffer
		startTop = findTopBuffer(current.buffer, startCol);
		startZoneHeight = BUFFERHEIGHT - 1;
	}
	else{	//Starts on truck
		startTop = 0;
		startZoneHeight = 0;
	}

	if(0 == endZone){	//Ends on ship
		endTop = 1 + findTopShip(current.ship, endCol);
		endZoneHeight = SHIPHEIGHT - 1;
	}
	else if(2 == endZone){	//Ends in buffer
		endTop = 1 + findTopShip(current.buffer, endCol);
		endZoneHeight = BUFFERHEIGHT - 1;
	}
	else{	//Ends on truck
		endTop = 0;
		endZoneHeight = 0;
	}

	if(true == justCrane && 0 == current.prev[2][0]){	//Dropped off a container to start move
		cost += current.craneRow - (startTop + 1);
	}
	else if(false == justCrane && 1 == current.prev[2][0]) {	//Picked up a container to start move
		cost += current.craneRow - startTop;
	}
	else{	//Maintain position to start move
		startTop = current.craneRow;
	}

	if(startZone != endZone){	//move between zones
		cost += PORTALTIME;
		cost += startZoneHeight - startTop;	//move up to portal
	}
	else{
		cost += SINGLEMOVETIME;
		if(endTop > startTop){	//have to move up to get over containers
			cost += endTop - startTop;
		}
	}
	return cost;
}

#endif