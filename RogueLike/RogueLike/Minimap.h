#pragma once

/*
This class is used to display the currently uncovered portion of the map to the player in a smaller form factor
so they can more easily keep track of the layout of the dungeon
*/

#include "TileMap.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;

ref class Minimap
{

private:

	//Fields
	Graphics^ canvas;
	TileMap^ map;
	int miniMapTileSizeWidth;
	int miniMapTileSizeHeight;
	int mapDrawXLocation;
	int mapDrawYLocation;
	int width;
	int height;
	int mapDrawRowStart;
	int mapDrawColStart;
	int NRows;
	int NCols;

public:

	//Constructor
	Minimap(Graphics^ canvas, TileMap^ startMap, Size^ canvasSize, int halfViewportXOffset, int halfViewportYOffset);

	//Methods that can be called globally
	void DrawMiniMap(int xpos, int ypos);
	void CalculateTileSize(Size^ canvasSize);
};

