#pragma once
#include "FSMSprite.h"

/*
This class creates a sprite that is a projectile. It is created at another sprites location and moves through the air applying gravity.
This class inherits from FSMSprite. The projectile moves in any direction unllike any other sprite
*/

ref class Projectile : public FSMSprite
{

private: 

	int power;
	int gravity;
	int lifeTicks;

public:

	Projectile(Graphics ^ startCanvas, Random ^ startRGen, array<Bitmap^>^ startSpriteSheet, int startNFrames, TileMap ^ startTileMap, int startScoreValue, int startHealth, int startAttackDamage,
				int startXpos, int startYpos, int startPower, int startGravity, FSMSprite^ player);

	virtual void UpdateState(FSMSprite^ player) override;

	virtual void PerformAction(FSMSprite^ player) override;

	virtual void Move() override; //special move method. Projectile does not move by specfic direction

	virtual void Draw(int xLocation, int yLocation) override;

private:

	void CalculateTrajectory(FSMSprite^ player);
};