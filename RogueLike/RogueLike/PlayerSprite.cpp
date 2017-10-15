#include "PlayerSprite.h"



PlayerSprite::PlayerSprite(Graphics ^ startCanvas, Random ^ startRGen, array<Bitmap^>^ startSpriteSheet, int startNFrames, TileMap ^ startTileMap, int startScoreValue, array<Bitmap^>^ startFightSpriteSheet, int startMaxHealth, int startAttackDamage) :
	FSMSprite(startCanvas, startRGen, startSpriteSheet, startNFrames, startTileMap, startScoreValue, startMaxHealth, startAttackDamage)
{
	//Initialising Fields
	ActionState = SLEEP;
	fightSpriteSheet = startFightSpriteSheet;
	SetVelocity();
	IncreaseSpeedTicks = 0;
	isGoingFast = false;

}//End Constructor


 ///////////////////////////////////////////////////////////////////////////////////////////////
 // Accesses the sprites current state and updates its state and fields according to conditions
 // that are present within each case statement
 ///////////////////////////////////////////////////////////////////////////////////////////////

void PlayerSprite::UpdateState()
{
	switch (ActionState)
	{
	case PATROL:

		if (PatrolTicks == 0) //If just entering this sets its spritesheet to the walking spritesheet
		{
			SetSpriteSheet(movementSpriteSheet, nWalkFrames);
		}

		if (IncreaseSpeedTicks > 200) //If speed boost has ran out
		{
			isGoingFast = false;
			IncreaseSpeedTicks = 0;
			SetVelocity();
		}

		break;

	case ATTACK:

		if (attackTicks == 0) //If just entering this sets its spritesheet to the attack spritesheet
		{
			SetSpriteSheet(fightSpriteSheet, nWalkFrames);
		}

		if (attackTicks > nWalkFrames - 1) //4 frames of attack. Stop attacking after 4
		{
			ActionState = SLEEP; //If switched to moving, player runs with key press
			SetSpriteSheet(movementSpriteSheet, nWalkFrames);
			attackTicks = 0;
			PatrolTicks = 0;
		}
		break;

	case SLEEP: //Resets the counters for both the attack and sleep states
		attackTicks = 0;
		PatrolTicks = 0;
		break;
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////
// Accesses the sprites current state and runs the code that is associated with that state 
///////////////////////////////////////////////////////////////////////////////////////////////

void PlayerSprite::PerformAction()
{
	bool canMove;

	switch (ActionState)
	{
	case PATROL: //Moves based on which key has been pressed 

		canMove = FindOutIfNextTileIsWalkable();
		if (canMove)
		{
			Move();
			PatrolTicks++;
		}

		if (isGoingFast)
		{
			IncreaseSpeedTicks++;
		}

		UpdateFrame();

		break;



	case ATTACK: //Performs the sprites attack animation
		attackTicks++;
		UpdateFrame();
		break;
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////
// Sets the speed of the sprite its default values
///////////////////////////////////////////////////////////////////////////////////////////////

void PlayerSprite::SetVelocity()
{
	int speed = Constants::PLAYER_START_SPEED_VALUE;

	xVel = speed;
	yVel = speed;
}


///////////////////////////////////////////////////////////////////////////////////////////////
// Restores the health of the sprite by a specific amount
///////////////////////////////////////////////////////////////////////////////////////////////

void PlayerSprite::IncreaseHealth()
{
	int restoreValue = Constants::HEALTH_RESTORE_VALUE;

	if (Health <= MaxHealth - restoreValue) //if under 50 then add health
	{
		Health += restoreValue;
	}
	else //if not anything would increase to full health
	{
		Health = MaxHealth;
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////
// Increases the speed of the sprite by specific amount 
///////////////////////////////////////////////////////////////////////////////////////////////

void PlayerSprite::IncreaseSpeed()
{
	isGoingFast = true;
	int speedIncreaseValue = Constants::SPEED_INCREASE_VALUE;
	SetVelocity(); //Reseting so the player doesnt get addition speed if a new drop is picked up
	IncreaseSpeedTicks = 0; //Reseting each time to give each drop the correct amount of active time
	xVel += speedIncreaseValue;
	yVel += speedIncreaseValue;
}


///////////////////////////////////////////////////////////////////////////////////////////////
// Increases the maximum health of the sprite by a specific amount and sets their health to equal
// the new max health
///////////////////////////////////////////////////////////////////////////////////////////////

void PlayerSprite::IncreaseMaxHealth()
{
	int increaseValue = Constants::HEALTH_MAX_INCREASE_VALUE;

	MaxHealth += increaseValue;
	Health = MaxHealth;
}

///////////////////////////////////////////////////////////////////////////////////////////////
// Spawns the player sprite inside one of the rooms on the map that does not contain the portal
///////////////////////////////////////////////////////////////////////////////////////////////

void PlayerSprite::SpawnInRoom(List<Room^>^ rooms)
{
	int randomRoom;

	do
	{
		randomRoom = rGen->Next(rooms->Count); //Randomly chooses a room the sprite will spawn in

	} while (rooms[randomRoom]->HasPortal);


	Rectangle spawnRoom = rooms[randomRoom]->getWorldLocation();//Gets the rooms inner bounds excluding walls from the list of rooms

																//Randomly chooses a location in the room
	XPos = rGen->Next(spawnRoom.Left, spawnRoom.Right - FrameWidth);
	YPos = rGen->Next(spawnRoom.Top, spawnRoom.Bottom - FrameHeight);

	updateCollisonBox(); //Creates collison rectangle
}




