#pragma once
#include "Constants.h"

using namespace System::Drawing;

//////////////////////////////////////////////////////////////////////
//This class holds its location in the world as well its dimensions
//////////////////////////////////////////////////////////////////////

ref class Room
{
private:
	
	int tileSide;

public:

	//Gets and Sets
	property int MapColumnLocation;
	property int MapRowLocation;
	property int NCols;
	property int NRows;
	property bool HasPortal;

	//Constructor
	Room(int startMapColLocation, int startMapRowLocation, int startNCols, int startNRows);
	Rectangle getWorldLocation();

};

