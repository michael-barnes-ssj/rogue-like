#pragma once
#include "Room.h"
#include "Constants.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;

//Enumeration for the different types of tiles
public enum TileType { SURROUNDINGTERRAIN, SURROUNDINGTERRAIN2, WALL, FLOOR, CORRIDOR, PADDING, DOOR };

ref class Dungeon
{
private:

	//Fields
	array<int, 2>^ map;
	Random^ rGen;
	int nRows;
	int nCols;
	int xOffset;
	int yOffset;

	//Methods only called within the class
	void createRooms(int numberOfRooms);
	void addRoomToMap(Room^ newRoom);
	Room^ createNewRoom();
	bool checkOverlaps(Room^ newRoom);
	void createCorridors();
	void addNewCorridor(Room^ roomA, Room^ roomB);
	void addCorridorToMap(int row, int col);
	void resetMap();


public:

	//Gets and Sets
	property List<Room^>^ Rooms;

public:

	//Constructor
	Dungeon(Random^ randomGenerator,
		int startNRows, int startNCols,
		int halfViewportXOffset,
		int halfViewportYOffset);

	//Methods that can be called globally
	array<int, 2>^ GenerateMap();
};

