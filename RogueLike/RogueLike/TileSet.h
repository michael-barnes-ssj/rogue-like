#pragma once

#include"Tile.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class TileSet
{

private:

	//Fields
	array<Tile^>^ tileArray;
	int nTiles;

public:

	TileSet(int startNTiles); //Constructor

	//Methods
	Bitmap^ GetTileBitmap(int tileIndex);
	bool GetTileWalkableState(int tileIndex);
	void SetTileArrayEntry(int tileIndex, String^ fileName, bool isWalkable);

};

