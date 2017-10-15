#pragma once
#include "TileMap.h"
#include "Room.h"
#include "Constants.h"

/*
This class creates the base class for all sprites. It holds everything that is common for all sprites. It handles the drawing and updating frames,
storing location, sizes, images, and everything a sprite needs.
*/

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;

public enum EDirection { NORTH, EAST, SOUTH, WEST}; 

ref class Sprite
{

protected:
	Graphics^ canvas;
	Random^ rGen;
	TileMap^ tileMap;
	array<Bitmap^>^ spriteSheet;	

	int nFrames;
	int currentFrame;
	

public:

	//For linked list to access
	Sprite^ Next;

	property int DirectionState;
	property int FrameWidth;
	property int FrameHeight;
	property int XPos;
	property int YPos;
	property bool IsAlive;
	property Rectangle CollisionBox;
	property int ScoreValue;
	property Rectangle SearchZone;

public:
	
	Sprite(Graphics^ startCanvas, Random^ startRGen, array<Bitmap^>^ startSpriteSheet,int startNFrames,  TileMap^ startTileMap, int startScoreValue);
	void UpdateFrame();
	void SetSpriteSheet(array<Bitmap^>^ newSpriteSheet,int startNFrames);
	virtual void Draw(int xLocation, int yLocation);
	virtual void SpawnInRoom(List<Room^>^ rooms);
	bool SpritesHaveCollided(Sprite ^ otherGuy);
	

protected:
	void updateCollisonBox();
};

