#pragma once

#include "TileMap.h"
#include "Constants.h"
#include "PlayerSprite.h"

/*
This class draws the tiles that are located in the viewport to the screen. It takes a 2d map of ints and gets the tile from it, and uses its position
in the map to determine where to dra it on the screen. This class also draws the fog of war.
*/


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class ViewPort

{

private:

	TileMap^ backgroundMap;

	Graphics^ canvas;

	int tileSide;

public:

	property int ViewportWorldX;

	property int ViewportWorldY;

	property int ViewPortPixelWidth;

	property int ViewPortPixelHeight;

	property int ViewportTilesWide;

	property int ViewportTilesHigh;

public:

	ViewPort(Size^ canvasSize, TileMap^ startBackgroundMap, Graphics^ startCanvas);

	void ViewportDraw();

	void CentreViewPortAroundSprite(PlayerSprite ^ sprite);
};

