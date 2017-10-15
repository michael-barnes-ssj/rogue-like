#include "Dungeon.h"

///////////////////////////////////////////////////////////////////////////////////////////////
// Initialises Global Variables
///////////////////////////////////////////////////////////////////////////////////////////////

Dungeon::Dungeon(Random^ randomGenerator,
	int startNRows, int startNCols,
	int halfViewportXOffset,
	int halfViewportYOffset)
{
	xOffset = halfViewportXOffset / 2;
	yOffset = halfViewportYOffset / 2;

	nRows = startNRows;
	nCols = startNCols;

	rGen = randomGenerator;
	map = gcnew array<int, 2>(nRows, nCols);
	Rooms = gcnew List<Room^>();
}//End Constructor


 ///////////////////////////////////////////////////////////////////////////////////////////////////
 // Randomly selects a number of rooms
 // Creates each of those rooms by calling the createRooms method and stores them in a list
 // Creates connectors to each of the rooms in the form of corridors using the above mentioned list
 // Returns completed 2Darray of integers to be used as the current level
 ///////////////////////////////////////////////////////////////////////////////////////////////////

array<int, 2>^ Dungeon::GenerateMap()
{
	resetMap();

	int numRooms = rGen->Next(Constants::MIN_NUM_ROOMS, Constants::MAX_NUM_ROOMS); //Randomly choose how many rooms the level will have.

	createRooms(numRooms);

	createCorridors();

	return map;
}//End GenerateMap


 //////////////////////////////////////////////////////////////////////////////////////////////////
 // Creates new rooms until they do not collide with other rooms on the map and then
 // adds them to the map
 ///////////////////////////////////////////////////////////////////////////////////////////////////

void Dungeon::createRooms(int numberOfRooms)
{
	Room^ newRoom = createNewRoom(); //Creates first room cause it wont overlap
	Rooms->Add(newRoom); //Adds it to the list of rooms
	addRoomToMap(newRoom);  //Adds the room to the map

	for (int i = 1; i < numberOfRooms; i++)
	{
		newRoom = createNewRoom(); //Creates a new room
		bool hasOverlapped = checkOverlaps(newRoom); //Checks if it overlaps

		while (hasOverlapped) //If it has continuously makes new rooms till one doesnt overlap
		{
			newRoom = createNewRoom();
			hasOverlapped = checkOverlaps(newRoom);
		}

		Rooms->Add(newRoom); //Adds new room to the list
		addRoomToMap(newRoom); //Adds new room to the map
	}

}//End createRooms


 //////////////////////////////////////////////////////////////////////////////////////////////////
 // Creates and returns a new instance of the room class with a random column and row start location
 // and a random width and height.
 ///////////////////////////////////////////////////////////////////////////////////////////////////

Room ^ Dungeon::createNewRoom()
{
	int roomNCols = rGen->Next(Constants::MIN_ROOM_SIZE, Constants::MAX_ROOM_SIZE);
	int roomNRows = rGen->Next(Constants::MIN_ROOM_SIZE, Constants::MAX_ROOM_SIZE);
	int roomStartCol = rGen->Next(xOffset, nCols - (2 * xOffset) - roomNCols); //Starts at half the viewports width and height in and 
	int roomStartRow = rGen->Next(yOffset, nRows - (2 * yOffset) - roomNRows); //ends at the NRows and NCols -  2 * viewports width and height

	return gcnew Room(roomStartCol, roomStartRow, roomNCols, roomNRows);

}//End createOneRoom


 //////////////////////////////////////////////////////////////////////////////////////////////////
 // Starts at the rooms startCol and StartRow location and loops through to the endRow and endCol
 // of the room and adds each of their row and col locations to the map as specific tiles 
 // according to the conditions met within the loop
 ///////////////////////////////////////////////////////////////////////////////////////////////////

void Dungeon::addRoomToMap(Room ^ newRoom)
{
	int startRow = newRoom->MapRowLocation;
	int endRow = startRow + newRoom->NRows;
	int startCol = newRoom->MapColumnLocation;
	int endCol = startCol + newRoom->NCols;


	for (int r = startRow; r < endRow + 1; r++)
	{
		for (int c = startCol; c < endCol + 1; c++)
		{
			if (r == startRow || c == startCol || r == endRow || c == endCol) //1 tile outside the wall is padding walls dont rub shoulders with other rooms
			{
				map[r, c] = PADDING;
			}
			else if (r == startRow + 1 || c == startCol + 1 || r == endRow - 1 || c == endCol - 1) // walls surround the floor tiles
			{
				map[r, c] = WALL;
			}
			else //Remaining tiles will be floor tiles
			{
				map[r, c] = FLOOR;
			}
		}
	}

}


//////////////////////////////////////////////////////////////////////////////////////////////////
// Looks at each map coordinate of the room and checks if any of them are already tiles used by rooms
///////////////////////////////////////////////////////////////////////////////////////////////////

bool Dungeon::checkOverlaps(Room ^ newRoom)
{
	bool overlap = false;

	int startRow = newRoom->MapRowLocation;
	int endRow = startRow + newRoom->NRows;
	int startCol = newRoom->MapColumnLocation;
	int endCol = startCol + newRoom->NCols;


	for (int r = startRow; r < endRow + 1; r++)
	{
		for (int c = startCol; c < endCol + 1; c++)
		{
			if (map[r, c] == WALL)
			{
				overlap = true;
			}
			else if (map[r, c] == PADDING)
			{
				overlap = true;
			}
			else if (map[r, c] == FLOOR)
			{
				overlap = true;
			}
		}
	}

	return overlap;

}//End checkOverlaps


 //////////////////////////////////////////////////////////////////////////////////////////////////
 // Goes through each of the rooms and links them to the next room in the list
 ///////////////////////////////////////////////////////////////////////////////////////////////////

void Dungeon::createCorridors()
{
	for (int i = 0; i < Rooms->Count; i++)
	{
		if (i + 1 == Rooms->Count) //If the last room, links it to the first room in the list
		{
			addNewCorridor(Rooms[i], Rooms[0]);
		}
		else   //Links the current room to the next room in the list
		{
			addNewCorridor(Rooms[i], Rooms[i + 1]);
		}
	}
}


//////////////////////////////////////////////////////////////////////////////////////////////////
// Calculates what the room on the left is and starts at its middle and draws a corridor along the 
// X axis until it reachs the middle of the right room on that axis. Then  calculates which room is
// on top proceeds downward on the Y axis to that rooms center.
///////////////////////////////////////////////////////////////////////////////////////////////////

void Dungeon::addNewCorridor(Room ^ roomA, Room ^ roomB)
{
	Room^ lowerRoom; //Lower room or left room.
	Room^ higherRoom; //Higher or right room

	if (roomA->MapColumnLocation < roomB->MapColumnLocation) //If room A is on the left
	{
		lowerRoom = roomA;
		higherRoom = roomB;
	}
	else //If room B is on the left
	{
		lowerRoom = roomB;
		higherRoom = roomA;
	}

	int leftCenterCol = lowerRoom->MapColumnLocation + (lowerRoom->NCols / 2);
	int leftCenterRow = lowerRoom->MapRowLocation + (lowerRoom->NRows / 2);
	int rightCenterCol = higherRoom->MapColumnLocation + (higherRoom->NCols / 2);

	for (int i = leftCenterCol; i <= rightCenterCol; i++)
	{
		addCorridorToMap(leftCenterRow - 1, i - 1); //Draws the corridor with +1/-1 each size to make them wider
		addCorridorToMap(leftCenterRow, i);
		addCorridorToMap(leftCenterRow + 1, i + 1);
	}


	if (roomA->MapRowLocation < roomB->MapRowLocation) //If room A is on the top
	{
		lowerRoom = roomA;
		higherRoom = roomB;
	}
	else //If room B is on the top
	{
		lowerRoom = roomB;
		higherRoom = roomA;
	}

	int bottomCenterRow = lowerRoom->MapRowLocation + (lowerRoom->NRows / 2);
	int topCenterCol = higherRoom->MapColumnLocation + (higherRoom->NCols / 2);
	int topCenterRow = higherRoom->MapRowLocation + (higherRoom->NRows / 2);

	for (int i = bottomCenterRow; i <= topCenterRow; i++)
	{
		addCorridorToMap(i - 1, rightCenterCol - 1); //Draws the corridor with +1/-1 each size to make them wider
		addCorridorToMap(i, rightCenterCol);
		addCorridorToMap(i + 1, rightCenterCol + 1);
	}

}//End addNewCorridor


 //////////////////////////////////////////////////////////////////////////////////////////////////
 // Adds the coordinates that from the methods argument list and places them on the map according
 // to the conditions met 
 ///////////////////////////////////////////////////////////////////////////////////////////////////

void Dungeon::addCorridorToMap(int row, int col)
{
	if ((map[row, col] == SURROUNDINGTERRAIN) || (map[row, col] == SURROUNDINGTERRAIN2) || (map[row, col] == PADDING))
	{
		map[row, col] = CORRIDOR;
	}
	else if (map[row, col] == WALL)
	{
		map[row, col] = DOOR;
	}
}//End addRoomsToMap


 //////////////////////////////////////////////////////////////////////////////////////////////////
 // Resets the list of rooms and the map back to default values, ready to create a new dungeon
 ///////////////////////////////////////////////////////////////////////////////////////////////////

void Dungeon::resetMap()
{
	Rooms = gcnew List<Room^>();

	for (int r = 0; r < nRows; r++)
	{
		for (int c = 0; c < nCols; c++)
		{
			map[r, c] = rGen->Next(2); //creates random background. Might add a third tile. Need to add constant for 2
		}
	}
}//End resetMap

