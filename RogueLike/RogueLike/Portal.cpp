#include "Portal.h"

///////////////////////////////////////////////////////////////////////////////////////////////
// Constructor. Initialises Variables
///////////////////////////////////////////////////////////////////////////////////////////////

Portal::Portal(Graphics ^ startCanvas, Random ^ startRGen, array<Bitmap^>^ startSpriteSheet, int startNFrames, TileMap ^ startTileMap, int startScoreValue, Score^ score) :
	Sprite(startCanvas, startRGen, startSpriteSheet, startNFrames, startTileMap, startScoreValue)
{
	playerScore = score; //stores score
}
///////////////////////////////////////////////////////////////////////////////////////////////
// Overriden draw method. Calculates its x and y minus viewport x and y so it draws on the scree.
///////////////////////////////////////////////////////////////////////////////////////////////

void Portal::Draw(int viewportX, int viewportY, array<bool, 2>^ map)
{
	int spriteViewportLocX = XPos - viewportX; //calculate draw location
	int spriteViewportLocY = YPos - viewportY;

	Bitmap^ currentBitmap = spriteSheet[DirectionState];
	int startX = currentFrame* FrameWidth;
	Rectangle rectangle = Rectangle(startX, 0, FrameWidth, FrameHeight);

	int row = (YPos / Constants::TILESIDE); //use world position to calculate what tile they are on
	int col = (XPos / Constants::TILESIDE);

	if (map[row, col]) //ash visible map if that tile is visible
	{
		//draw if not in fog
		canvas->DrawImage(currentBitmap, spriteViewportLocX, spriteViewportLocY, rectangle, GraphicsUnit::Pixel);
	}
	UpdateFrame();	
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Special Spawn in room method. The portal can' spawn in the same room as the player. Sets the room
// it spawns in property to true so the player won't spawn in there.
///////////////////////////////////////////////////////////////////////////////////////////////

void Portal::SpawnInRoom(List<Room^>^ rooms)
{
	int randomRoom = rGen->Next(rooms->Count); //Randomly chooses a room the sprite will spawn in

	Rectangle spawnRoom = rooms[randomRoom]->getWorldLocation();//Gets the rooms inner bounds excluding walls from the list of rooms

	rooms[randomRoom]->HasPortal = true;
																//Randomly chooses a location in the room
	XPos = rGen->Next(spawnRoom.Left, spawnRoom.Right - FrameWidth);
	YPos = rGen->Next(spawnRoom.Top, spawnRoom.Bottom - FrameHeight);

	updateCollisonBox(); //Creates collison rectangle
}

///////////////////////////////////////////////////////////////////////////////////////////////
// increases player score by portal score value
///////////////////////////////////////////////////////////////////////////////////////////////

void Portal::ScoreForLevelCompletion()
{
	playerScore->CurrentScore += ScoreValue;
}

