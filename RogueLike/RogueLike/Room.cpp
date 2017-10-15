#include "Room.h"

///////////////////////////////////////////////////////////////////////////////////////////////
// Initialises Global Variables
///////////////////////////////////////////////////////////////////////////////////////////////

Room::Room(int startMapColLocation, int startMapRowLocation, int startNCols, int startNRows)
{
	MapColumnLocation = startMapColLocation;
	MapRowLocation = startMapRowLocation;
	NCols = startNCols;
	NRows = startNRows;
	tileSide = Constants::TILESIDE;
	HasPortal = false;
}
Rectangle Room::getWorldLocation()
{
	//Adding 3 and 5 accounts for padding and wall. 

	int worldX = (MapColumnLocation+2)*tileSide;
	int worldY = (MapRowLocation+2)*tileSide;
	int worldWidth = (NCols-3)*tileSide;
	int worldHeight = (NRows-3)*tileSide;

	Rectangle worldLocation = Rectangle(worldX, worldY, worldWidth, worldHeight);
	return worldLocation;
}
//End Constructor
