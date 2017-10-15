#pragma once
#include "Sprite.h"
#include "Score.h"

/*
This class contains everything to do with the portal. The portal takes you to a new level (random dungeon). This class inherits from sprite but has a special draw method,
and also needs score to increase the players score.
*/

ref class Portal : public Sprite
{
public:	Score^ playerScore;

public:

	Portal(Graphics ^ startCanvas, Random ^ startRGen, array<Bitmap^>^ startSpriteSheet, int startNFrames, TileMap ^ startTileMap, int startScoreValue, Score^ score);	

	virtual void SpawnInRoom(List<Room^>^ rooms) override; //special spawn method. Portal can't spawn in same room as player
	
	virtual void Draw(int ViewPortX, int ViewPortY, array<bool, 2>^ map) override; //special draw method. Portal is not held in linked list so draws differently

	void ScoreForLevelCompletion();
	
};


