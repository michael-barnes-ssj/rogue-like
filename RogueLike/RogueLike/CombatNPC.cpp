#include "CombatNPC.h"

CombatNPC::CombatNPC(Graphics ^ startCanvas,
	Random ^ startRGen,
	array<Bitmap^>^ startSpriteSheet,
	int startNFrames,
	TileMap ^ startTileMap,
	int startScoreValue,
	int startMaxHealth,
	int startAttackDamage,
	ProjectileLinkedList^ startProjectiles,
	array<Bitmap^>^ startProjectileSpriteSheet) : FSMSprite(startCanvas, startRGen, startSpriteSheet, startNFrames, startTileMap, startScoreValue, startMaxHealth, startAttackDamage)
{

	//Initialising variables
	ActionState = PATROL;
	SetVelocity();
	projectileSpriteSheet = startProjectileSpriteSheet;
	projectiles = startProjectiles;
	throwProjectile = 0;
	startXVel = xVel;
	startYVel = yVel;

}//End constructor


 ///////////////////////////////////////////////////////////////////////////////////////////////
 // Accesses the sprites current state and updates its state and fields according to conditions
 // that are present within each case statement
 ///////////////////////////////////////////////////////////////////////////////////////////////

void CombatNPC::UpdateState(FSMSprite^ player)
{
	RandomChangeState = rGen->Next(Constants::RANDOM_CHANGE_STATE_RANGE); //Used to probablistically change the state

	switch (ActionState)
	{
	case PATROL: //Wanders aimlessly

		xVel = startXVel; //Setting Speed to default speed
		yVel = startYVel;

		if (SearchZone.IntersectsWith(player->CollisionBox)) // If within search range
		{
			ActionState = APPROACH;
		}
		else if (RandomChangeState < Constants::CHANGE_DIRECTION_RANGE) //Random chance to change direction
		{
			ChangeDirection();
		}
		break;

	case APPROACH: //Pursues the player

		xVel = startXVel + Constants::APPROACH_SPEED_INCREASE; //Increased speed when pursing 
		yVel = startYVel + Constants::APPROACH_SPEED_INCREASE;

		if (!SearchZone.IntersectsWith(player->CollisionBox)) //If not within search range
		{
			ChangeDirection();
			ActionState = PATROL;
		}
		else if (SpritesHaveCollided(player)) //If touching the player
		{
			ActionState = ATTACK;
		}
		break;

	case ATTACK:
		if (!SpritesHaveCollided(player)) //If not touching the player
		{
			ActionState = APPROACH;
		}
		break;
	}

	if (Health <= 0) // If the sprite runs out of life it dies
	{
		IsAlive = false;
	}

}//End Update State


 ///////////////////////////////////////////////////////////////////////////////////////////////
 // Accesses the sprites current state and runs the code that is associated with that state 
 ///////////////////////////////////////////////////////////////////////////////////////////////

void CombatNPC::PerformAction(FSMSprite^ player)
{
	bool canMove; //Checking if the next move is legal

	switch (ActionState)
	{
	case PATROL:

		Patrol(); //Wander aimlessly
		break;

	case APPROACH:

		approach(player); //Move towards the player

		throwProjectile = rGen->Next(Constants::PROJECTILE_CHANCE); //Random chance to throw  projectile in the players direction

		if (throwProjectile<Constants::PROJECTILE_LAUNCH_RANGE)
		{
			fireProjectile(player); //Create a new projectile
		}
		break;

	case ATTACK:

		if (player->ActionState == ATTACK) //Taking damage
		{
			Health -= player->AttackDamage; //Reduce sprites health
		}

		int chanceToInjure = rGen->Next(Constants::RANDOM_LAND_BLOW_RANGE); //Randoms a chance to land the blow 

		if (chanceToInjure< Constants::LAND_BLOW_RANGE) //Land Blow
		{
			player->Health -= AttackDamage; //Reduce  players health
		}
		break;
	}


}

///////////////////////////////////////////////////////////////////////////////////////////////
// Using trigonometry to gain to establish an angle between the sprite and the player,
// work out which direction the sprite should move in
///////////////////////////////////////////////////////////////////////////////////////////////

void CombatNPC::approach(FSMSprite ^ player)
{
	bool canMove; //Check if next move is legal

	if (CollisionBox.X < player->CollisionBox.X - xVel || CollisionBox.X > player->CollisionBox.X + xVel) // + velocity because that is the max possible velocity of a NPC sprite
	{
		orientX(player); //Angle toward player on X axis 

		canMove = FindOutIfNextTileIsWalkable();

		if (canMove) //Move on X 
		{
			Move();
		}
		else //Walk Up till able to move on X again
		{
			orientY(player); //Angle toward player on Y axis 

			canMove = FindOutIfNextTileIsWalkable();

			if (canMove)
			{
				Move();
			}
		}
	}
	else //Move on Y
	{
		orientY(player); //Angle toward player on Y axis 

		canMove = FindOutIfNextTileIsWalkable();

		if (canMove)
		{
			Move();
		}
		else //Walk Up till able to move on Y again
		{
			orientX(player); //Angle toward player on X axis 

			canMove = FindOutIfNextTileIsWalkable();

			if (canMove)
			{

				Move();
			}
		}

	}
}


///////////////////////////////////////////////////////////////////////////////////////////////
// Work out which direction the sprite should move toward the player on the X axis
///////////////////////////////////////////////////////////////////////////////////////////////

void CombatNPC::orientX(FSMSprite^ player)
{
	double angle = ComputeAngleToTarget(player); //Work out angle between to the player

	int direction = (int)(Math::Cos(angle) * speed); //Figure out their direction on the X axis

	if (direction > 0)
	{
		DirectionState = EAST;
	}
	else if (direction < 0)
	{
		DirectionState = WEST;
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////
// Work out which direction the sprite should move toward the player on the Y axis
///////////////////////////////////////////////////////////////////////////////////////////////

void CombatNPC::orientY(FSMSprite^ player)
{
	double angle = ComputeAngleToTarget(player); //Work out angle between to the player

	int direction = (int)(Math::Sin(angle) * speed); //Figure out their direction on the Y axis

	if (direction > 0)
	{
		DirectionState = SOUTH;
	}
	else if (direction < 0)
	{
		DirectionState = NORTH;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
// Create a new instance of the projectile class at your x and y coordinates and randomly
// generate the amount of power behind it.
// Add it to the projectile list that this sprite has a pointer to 
///////////////////////////////////////////////////////////////////////////////////////////////

void CombatNPC::fireProjectile(FSMSprite ^ player)
{

	int power = rGen->Next(8, Constants::PROJECTILE_POWER_MAX);
	int gravity = Constants::PROJECTILE_GRAVITY_MAX;

	projectiles->AddNode(gcnew Projectile(canvas, rGen, projectileSpriteSheet, Constants::PROJECTILE_SPRITE_NFRAMES, tileMap, 0, 0, AttackDamage, CollisionBox.X - (CollisionBox.Width / 2), CollisionBox.Y - (CollisionBox.Height / 2), power, gravity, player));
}