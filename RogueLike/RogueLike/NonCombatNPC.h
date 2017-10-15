#pragma once
#include "FSMSprite.h"
#include "Constants.h"

/*
This class creates an instance of an enemy sprite that will avoid the player. It will not attack it will just try and run away or sleep. This class
inherites from FSMSprite and uses a FSM.
*/


ref class NonCombatNPC :
	public FSMSprite
{

private:

	array<Bitmap^>^ sleepSpriteSheet; //Need new spriteSheet for sleep animation
	int nSleepFrames;

public:
	
	NonCombatNPC(Graphics ^ startCanvas, Random ^ startRGen, array<Bitmap^>^ startSpriteSheet, int startNFrames, TileMap ^ startTileMap, int startScoreValue,array<Bitmap^>^ sleepSpriteSheet, int startNSleepFrames, int startMaxHealth, int startAttackDamage);

	virtual void UpdateState(FSMSprite^ player) override; //overiding Update state and perfrom, parent method is abstract.
	virtual void PerformAction(FSMSprite^ player) override;

	void OrientX(FSMSprite^ player);
	void OrientY(FSMSprite^ player);
};

