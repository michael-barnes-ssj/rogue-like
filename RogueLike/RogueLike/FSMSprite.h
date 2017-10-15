#pragma once
#include "Sprite.h"

/*
	This class is inherited from sprite. It extends the sprite functionality to have an FSM controlling it. It is abstract and is never created,
	but it creates methods and data that other classes will use. It adds movement, health and attack damage	to the sprite. There are many extra 
	properties needed for this functionality such as extra sprite sheets, velocities, and lots of states that drive
	the FSM.
*/

//Declaring enums

public enum EBoundAction { BOUNCE, WANDER, DIE, STOP }; //Used to determine bounds action
public enum EActionState { PATROL, SLEEP, APPROACH, AVOID, ATTACK};  //Used to drive FSM

ref class FSMSprite abstract : public Sprite
{
	//Data Properties
protected:	

	array<Point>^ velocityDirections;
	int xVel;
	int yVel;
	int speed; // used to compute xVel and yVel with trigonometry
	int lastDirection;
	int healthBarWidth;
	int healthBarHeight;
	array<Bitmap^>^ movementSpriteSheet;
	int nWalkFrames;

	//Public properties
public:
	property int BoundState;
	property int ActionState;
	property int SleepingTicks;
	property int PatrolTicks;
	property int RandomChangeState;
	property int Health;
	property int MaxHealth;
	property int AttackDamage;
	
public:
	
	//Constructor
	FSMSprite(Graphics ^ startCanvas, Random ^ startRGen, array<Bitmap^>^ startSpriteSheet, int startNFrames, TileMap ^ startTileMap, int startScoreValue, int startMaxHealth, int startAttackDamage);

	//Virtual Methods - Can be implemeted polymorphically
	virtual void UpdateState(FSMSprite^ player) override;
	virtual void PerformAction(FSMSprite^ player) override;
	virtual void Draw(int xLocation, int yLocation) override;
	virtual void Move();
	void drawHealthBar(int xLocation, int yLocation);
	virtual void SetVelocity();

	//Public Methods
	array<Point>^ SetVelocityDirections();
	bool FindOutIfNextTileIsWalkable();
	void ImplementOutOfBoundsAction();
	double ComputeAngleToTarget(FSMSprite^ player);	
	void ChangeDirection();
	void Patrol();

private:
	//Private Methods
	void updateSearchZone();
};

