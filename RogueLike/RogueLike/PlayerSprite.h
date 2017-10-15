#pragma once

///////////////////////////////////////////////////////////////////////////////////////////////
// Draws the entire dungeon in a smaller form so the player can keep track of their progress
// of the uncovered map much easier
///////////////////////////////////////////////////////////////////////////////////////////////

#include "FSMSprite.h"

ref class PlayerSprite : public FSMSprite
{
private:

	//Fields
	bool isGoingFast;
	array<Bitmap^>^fightSpriteSheet;

public:

	//Gets and Sets
	property int IncreaseSpeedTicks;
	property int attackTicks;

public:

	//Constructor
	PlayerSprite(Graphics ^ startCanvas, Random ^ startRGen, array<Bitmap^>^ startSpriteSheet, int startNFrames, TileMap ^ startTileMap, int startScoreValue, array<Bitmap^>^ startFightSpriteSheet, int startMaxHealth, int startAttackDamage);

	//Methods that can be called globally
	void UpdateState();
	void PerformAction();
	virtual void SetVelocity() override;
	void IncreaseHealth();
	void IncreaseSpeed();
	void IncreaseMaxHealth();
	virtual void SpawnInRoom(List<Room^>^ rooms) override;
};