#pragma once

//////////////////////////////////////////////////////////////////////////
// This class is used to hold multiple instances of object type ItemSprite.
// It contains methods that only apply to the ItemSprite type object and uses
// casting to enable the use of inheritance in this class hierarchy
//////////////////////////////////////////////////////////////////////////


#include "SpritesLinkedList.h"
#include "ItemSprite.h"

ref class ItemLinkedList : public SpritesLinkedList
{
public:

	//Constructor
	ItemLinkedList(Score^ score);

	//Methods that can be called globally
	void CheckItemCollisions(PlayerSprite^ hero);
};

