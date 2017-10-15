#pragma once

///////////////////////////////////////////////////////////////////////////////////////////////
// This class is used to hold a 2Darray of integers that represents a level within the game.
// It exposes methods to retrieve information about tiles at specific array index locations
// It also holds a 2Darray of booleans the same size as the integer array that acts as the games 
// fog of war
///////////////////////////////////////////////////////////////////////////////////////////////

#include"TileSet.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;

ref class TileMap
{

private:

	//Fields
	TileSet^ tileSet;
	array<int, 2>^ tileMap;

public:

	//Gets and Sets
	property int NCols;
	property int NRows;
	property array<bool, 2>^ VisibleMap;

public:

	//Constructor
	TileMap(TileSet^ startTileSet, int startNRows, int startNCols);

	//Methods that can be called globally
	void SetMapEntry(int row, int col, int tileIndex);
	int GetMapEntry(int row, int col);
	Bitmap^ GetTileBitmap(int row, int col);
	bool GetWalkableState(int row, int col);
	void SetTileMap(array<int, 2>^ newMap);
	void ResetFog();
};
