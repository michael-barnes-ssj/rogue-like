#include "ItemSprite.h"



ItemSprite::ItemSprite(Graphics ^ startCanvas,
	Random ^ startRGen,
	array<Bitmap^>^ startSpriteSheet,
	int startNFrames,
	TileMap ^ startTileMap,
	int startScoreValue,
	int startItemType,
	FeedBackMessages^ startMessageController) :Sprite(startCanvas, startRGen, startSpriteSheet, startNFrames, startTileMap, startScoreValue)
{

	//Intialising fields
	ItemType = startItemType;
	messageController = startMessageController;

}//End Constructor


 ///////////////////////////////////////////////////////////////////////////////////////////////
 // Using the switch state the item applies the cooresponding effects related to its ItemType 
 // to the player and sets the MessageControllers message to give feedback on this action
 ///////////////////////////////////////////////////////////////////////////////////////////////

void ItemSprite::ApplyEffects(PlayerSprite ^ player)
{

	switch (ItemType)
	{
	case HEALTH:
		if (player->Health != player->MaxHealth) //If the player is not at full health display the additional health normally and delete the sprite
		{
			player->IncreaseHealth(); //Restore HP of the player
			messageController->Message = "Health has been\nrestored by " + Constants::HEALTH_RESTORE_VALUE.ToString(); +"!";
			IsAlive = false;
		}
		else //If health is full display as such and do not delete the sprite
		{
			messageController->Message = "Your Stomach is too full!";
		}

		break;

	case BOOTS:

		if (player->IncreaseSpeedTicks == 0) //If they are currently not affected by the speed boost display as normal
		{

			messageController->Message = "Speed has been temporarily\nincreased by " + Constants::SPEED_INCREASE_VALUE.ToString() + "!";
		}
		else //If they are currently affected by the speed boost display that the timer has just been reset
		{
			messageController->Message = "Speed duration timer has been reset!";
		}

		player->IncreaseSpeed(); //Increase speed of the player
		IsAlive = false;
		break;

	case BOOSTER:
		player->IncreaseMaxHealth(); //Increase max HP of the player
		messageController->Message = "Health has been permanently\nincreased by " + Constants::HEALTH_MAX_INCREASE_VALUE.ToString() + "!";
		IsAlive = false;
		break;

	case TREASURE: //Display that treasure has been picked up
		messageController->Message = "You picked up some treasure,\nyour score has been increased!";
		IsAlive = false;
		break;
	}

	messageController->MessageTicks = Constants::MESSAGE_DISPLAY_TIME; //Sets the amount of ticks before the message is deleted

}//End ApplyEffects
