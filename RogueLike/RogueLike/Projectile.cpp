
#include "Projectile.h"

///////////////////////////////////////////////////////////////////////////////////////////////
// Constructor. Initialises Variables
///////////////////////////////////////////////////////////////////////////////////////////////

Projectile::Projectile(Graphics ^ startCanvas, Random ^ startRGen, array<Bitmap^>^ startSpriteSheet, int startNFrames, TileMap ^ startTileMap, int startScoreValue, int startHealth, int startAttackDamage,
					int startXpos, int startYpos, int startPower, int startGravity, FSMSprite^ player) :
	FSMSprite(startCanvas, startRGen, startSpriteSheet, startNFrames, startTileMap, startScoreValue,startHealth,startAttackDamage)
{
	ActionState = ATTACK;
	XPos = startXpos;
	YPos = startYpos;
	power = startPower;
	gravity = startGravity;
	updateCollisonBox();
	CalculateTrajectory(player);
	lifeTicks = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////
// This method updates the state of the sprite. If certian events happen then the sprite 
// will change to a new state, which will change the action performed in perform action.
///////////////////////////////////////////////////////////////////////////////////////////////

void Projectile::UpdateState(FSMSprite ^ player)
{
	switch (ActionState)
	{
		case ATTACK:
			if (SpritesHaveCollided(player)) //if collided with sprite die
			{
				IsAlive = false;
				player->Health -= AttackDamage;
			}
			else if (lifeTicks == Constants::MAX_PROJECTILE_LIFE) //if life ticks run out die
			{
				IsAlive = false;
			}
			break;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
// This method performs actions depending on the state the sprite is in
///////////////////////////////////////////////////////////////////////////////////////////////

void Projectile::PerformAction(FSMSprite ^ player)
{
	switch (ActionState)
	{
		case ATTACK:
			if (SpritesHaveCollided(player)) //if collided with sprite damage the player
			{				
				player->Health -= AttackDamage;
			}
			if (FindOutIfNextTileIsWalkable()) //if next tile is walkabel then move
			{
				Move();
				lifeTicks++;
			}
			else //if not walkable then die
			{
				IsAlive = false;
			}
			break;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
// Special move method that moves without direction state. Basic movement is simpler.
// Gravity is applied to make it more complex.
///////////////////////////////////////////////////////////////////////////////////////////////

void Projectile::Move()
{
	XPos += xVel; // simple move
	YPos += yVel;

	// if xVel is between -5 and 5 don't implement gravity and throw straight

	//if player is left or right or sprite then implement gravity

	if (xVel > Constants::PROJECTILE_MAX_DISTANCE) // if to the right of player implement gravity to right
	{
		xVel += gravity;
	}

	else if (xVel < Constants::PROJECTILE_MIN_DISTANCE ) //else, if to left, angle towards left
	{
		xVel -= gravity;
	}

	UpdateFrame();
	updateCollisonBox();
}
///////////////////////////////////////////////////////////////////////////////////////////////
// Special draw method that doesn't draw health bar
///////////////////////////////////////////////////////////////////////////////////////////////
void Projectile::Draw(int xLocation, int yLocation) //overloaded draw method which draws to centre of screen
{
	Bitmap^ currentBitmap = spriteSheet[DirectionState];
	int startX = currentFrame* FrameWidth;
	Rectangle rectangle = Rectangle(startX, 0, FrameWidth, FrameHeight);
	canvas->DrawImage(currentBitmap, xLocation, yLocation, rectangle, GraphicsUnit::Pixel);	
}

///////////////////////////////////////////////////////////////////////////////////////////////
// Calculates x and Y vels towards the player. Has a random y offset to account for gravity
// and make it seems for realistic.
///////////////////////////////////////////////////////////////////////////////////////////////

void Projectile::CalculateTrajectory(FSMSprite^ player)
{
	double angle = ComputeAngleToTarget(player);

	xVel = (int)(Math::Cos(angle) * power);

	yVel = (int)(Math::Sin(angle) * power);

	double randomYOffset = rGen->NextDouble()+1; //calculates random y offset. So the projectile doesn't hit every time.

	yVel *= randomYOffset; //changing yVel because gravity makes it change
}