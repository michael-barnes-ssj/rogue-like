#pragma once

/*
This class is used to create different types of item sprites and treasure sprites
and then apply the effects that corresponds to the their type, to the player
*/

#include "Sprite.h"
#include "FeedBackMessages.h"
#include "PlayerSprite.h"


//Different types of Items
public enum EItemType { HEALTH, BOOTS, BOOSTER, TREASURE };

ref class ItemSprite : public Sprite
{
private:

	//Fields
	FeedBackMessages^ messageController;

public:

	//Gets and Sets
	property int ItemType;

public:

	//Constructor
	ItemSprite(Graphics ^ startCanvas,
		Random ^ startRGen,
		array<Bitmap^>^ startSpriteSheet,
		int startNFrames,
		TileMap ^ startTileMap,
		int startScoreValue,
		int startItemType,
		FeedBackMessages^ startMessageController);

	//Methods that can be called globally
	void ApplyEffects(PlayerSprite^ player);




};
