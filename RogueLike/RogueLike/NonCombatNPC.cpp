#include "NonCombatNPC.h"

///////////////////////////////////////////////////////////////////////////////////////////////
// Constructor. Initialises Variables
///////////////////////////////////////////////////////////////////////////////////////////////

NonCombatNPC::NonCombatNPC(Graphics ^ startCanvas, Random ^ startRGen, array<Bitmap^>^ startSpriteSheet, int startNFrames, TileMap ^ startTileMap, int startScoreValue, array<Bitmap^>^ startSleepSpriteSheet, int startNSleepFrames, int startMaxHealth, int startAttackDamage):
				FSMSprite(startCanvas, startRGen, startSpriteSheet, startNFrames, startTileMap, startScoreValue, startMaxHealth, startAttackDamage)
{
	BoundState = EBoundAction::BOUNCE;
	ActionState = EActionState::PATROL;
	sleepSpriteSheet = startSleepSpriteSheet;
	nSleepFrames = startNSleepFrames;
	SetVelocity();
}

///////////////////////////////////////////////////////////////////////////////////////////////
// This method updates the state of the sprite. If certian events happen then the sprite 
// will change to a new state, which will change the action performed in perform action.
///////////////////////////////////////////////////////////////////////////////////////////////

void NonCombatNPC::UpdateState(FSMSprite^ player)
{
	RandomChangeState = rGen->Next(Constants::RANDOM_STATE_NUMBER);

	switch (ActionState)
	{
		case SLEEP:

			//if sleeping ticks is over limit and random state number is high enough
			if ((SleepingTicks > Constants::SLEEP_TICK_LIMIT) && (RandomChangeState  > Constants::RANDOM_STATE_CHANCE))
			{	
				//Change to patrol and set up
				SleepingTicks = 0;			
				ActionState = PATROL;
				ChangeDirection();
				SetSpriteSheet(movementSpriteSheet, nWalkFrames);
			}
			else if (player->ActionState == ATTACK && SpritesHaveCollided(player)) //if player attacks you
			{ 
				//Switch to avoid
				ActionState = AVOID;
				SetSpriteSheet(movementSpriteSheet, nWalkFrames);
			}
			break;

		case PATROL:

			if (SearchZone.IntersectsWith(player->CollisionBox)) //if player in search zone switch to avoid
			{
				ActionState = AVOID;		
			}
			else if (RandomChangeState < Constants::RANDOM_STATE_CHANCE_DIRECTION) 
			{
				ChangeDirection();	
			}
			//if patrol ticks limit 
			else if (PatrolTicks > Constants::PATROL_TICK_LIMIT && RandomChangeState > Constants::RANDOM_STATE_CHANCE_TO_PATROL)
			{	
				//change to sleep and reset
				PatrolTicks = 0;
				ActionState = SLEEP;
				DirectionState = NORTH;	
				SetSpriteSheet(sleepSpriteSheet, nSleepFrames);				
			}
			break;

		case AVOID: 
			if (!SearchZone.IntersectsWith(player->CollisionBox)) //if  player leaves search zone change to patrol
			{
				ActionState = PATROL;
				SetSpriteSheet(movementSpriteSheet, nWalkFrames);
				ChangeDirection();
			}
			
			break;
	}

	if (Health <= 0) //if health is gone die
	{
		IsAlive = false;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
// This method performs actions depending on the state the sprite is in
///////////////////////////////////////////////////////////////////////////////////////////////

void NonCombatNPC::PerformAction(FSMSprite^ player)
{
	bool canMove;

	switch (ActionState)
	{
		case SLEEP:			
			
			SleepingTicks++;
			break;

		case PATROL:			
			Patrol();
			PatrolTicks++;
			break;

		case AVOID:		

			//if sprite X is greater or less than players
			if (CollisionBox.X<player->CollisionBox.X- xVel || CollisionBox.X>player->CollisionBox.X+ xVel)
			{
				OrientX(player); //orient on the x axis

				canMove = FindOutIfNextTileIsWalkable();

				if (canMove) 
				{
					Move();
				}
				else //if can't move orient on the y
				{
					OrientY(player); 

					canMove = FindOutIfNextTileIsWalkable();

					if (canMove)
					{
						Move();
					}
				}
			}
			else //else the x axis is the same
			{
				OrientY(player); //so orient on the y

				canMove = FindOutIfNextTileIsWalkable();

				if (canMove)
				{
					Move();
				}
				else //if cant move then orient on the x
				{
					OrientX(player);

					canMove = FindOutIfNextTileIsWalkable();

					if (canMove)
					{
						Move();
					}
				}
			}

			break;
	}	
	//if player attacks you lose damage based on his attack damage
	if (player->ActionState == ATTACK && SpritesHaveCollided(player))
	{
		Health -= player->AttackDamage;
	}

}

///////////////////////////////////////////////////////////////////////////////////////////////
// Computes angle to player and uses result to work out X direction away form player
///////////////////////////////////////////////////////////////////////////////////////////////

void NonCombatNPC::OrientX(FSMSprite^ player)
{
	double angle = ComputeAngleToTarget(player); //gets angle

	int direction = (Math::Cos(angle) * speed)*-1;	 //gets X direction away from player

	if (direction > 0) //positive is go east
	{
		DirectionState = EAST;
	}
	else if (direction < 0) //negative is go west
	{
		DirectionState = WEST;
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////
// Computes angle to player and uses result to work out Y direction away form player
///////////////////////////////////////////////////////////////////////////////////////////////


void NonCombatNPC::OrientY(FSMSprite^ player)
{
	double angle = ComputeAngleToTarget(player); //gets angle

	int direction = (Math::Sin(angle) * speed)*-1;  //gets Y direction away from player

	if (direction > 0) //positive is south
	{
		DirectionState = SOUTH;
	}
	else if (direction < 0) //negative is north
	{
		DirectionState = NORTH;
	}
}


