#include "Sprite.h"

///////////////////////////////////////////////////////////////////////////////////////////////
// Constructor
///////////////////////////////////////////////////////////////////////////////////////////////

Sprite::Sprite(Graphics ^ startCanvas, Random ^ startRGen, array<Bitmap^>^ startSpriteSheet, int startNFrames, TileMap ^ startTileMap, int startScoreValue)
{
	canvas = startCanvas;
	rGen = startRGen;
	DirectionState = NORTH;	
	SetSpriteSheet(startSpriteSheet,startNFrames);		
	tileMap = startTileMap;
	IsAlive = true;	
	ScoreValue = startScoreValue;
}

///////////////////////////////////////////////////////////////////////////////////////////////
// Changes to the next frame in spritesheet
///////////////////////////////////////////////////////////////////////////////////////////////

void Sprite::UpdateFrame()
{
	currentFrame = (currentFrame + 1) % nFrames;
}

///////////////////////////////////////////////////////////////////////////////////////////////
// Takes in a array of bitmams and int, makes the bitmaps background transparent, and sets frame
// width and height according to the passed in images
///////////////////////////////////////////////////////////////////////////////////////////////

void Sprite::SetSpriteSheet(array<Bitmap^>^ newSpriteSheet, int startNFrames)
{
	nFrames = startNFrames;
	spriteSheet = newSpriteSheet;

	for (int i = 0; i < spriteSheet->Length; i++)
	{
		spriteSheet[i]->MakeTransparent(spriteSheet[i]->GetPixel(0, 0));
	}
	
	FrameWidth = spriteSheet[DirectionState]->Width / nFrames;
	FrameHeight = spriteSheet[DirectionState]->Height;
	currentFrame = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////
// Draws the current frame to the passed in location
///////////////////////////////////////////////////////////////////////////////////////////////
void Sprite::Draw(int xLocation, int yLocation) //overloaded draw method which draws to centre of screen
{
	Bitmap^ currentBitmap = spriteSheet[DirectionState];
	int startX = currentFrame* FrameWidth;
	Rectangle rectangle = Rectangle(startX, 0, FrameWidth, FrameHeight);
	canvas->DrawImage(currentBitmap, xLocation, yLocation, rectangle, GraphicsUnit::Pixel);	
}

///////////////////////////////////////////////////////////////////////////////////////////////
// Generates a random X and y pos insie a room.
///////////////////////////////////////////////////////////////////////////////////////////////
void Sprite::SpawnInRoom(List<Room^>^ rooms)
{			
	int randomRoom = rGen->Next(rooms->Count); //Randomly chooses a room the sprite will spawn in

	Rectangle spawnRoom = rooms[randomRoom]->getWorldLocation();//Gets the rooms inner bounds excluding walls from the list of rooms

	//Randomly chooses a location in the room
	XPos = rGen->Next(spawnRoom.Left, spawnRoom.Right - FrameWidth);
	YPos = rGen->Next(spawnRoom.Top, spawnRoom.Bottom - FrameHeight);
	
	updateCollisonBox(); //Creates collison rectangle
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Checks if this sprite has collided with another
///////////////////////////////////////////////////////////////////////////////////////////////

bool Sprite::SpritesHaveCollided(Sprite ^ otherGuy)
{
	bool collision = true; //starts as true

	if (CollisionBox.Right < otherGuy->CollisionBox.Left)
	{
		collision = false;
	}
	else if (CollisionBox.Left > otherGuy->CollisionBox.Right)
	{
		collision = false;
	}
	else if (CollisionBox.Top > otherGuy->CollisionBox.Bottom)
	{
		collision = false;
	}
	else if (CollisionBox.Bottom < otherGuy->CollisionBox.Top)
	{
		collision = false;
	}
	
	return collision;
}

///////////////////////////////////////////////////////////////////////////////////////////////
// Creates a collision box based on offset amounts
///////////////////////////////////////////////////////////////////////////////////////////////

void Sprite::updateCollisonBox()
{
	int xOffset = Convert::ToInt16(FrameWidth*Constants::COLLISION_BOX_OFFSET);
	int yOffset = Convert::ToInt16(FrameHeight*Constants::COLLISION_BOX_OFFSET);	

	CollisionBox = Rectangle(
		XPos + xOffset,
		YPos + yOffset,
		FrameWidth - (xOffset*2),
		FrameHeight - (yOffset*2)
	);
}
