#include "ItemLinkedList.h"



ItemLinkedList::ItemLinkedList(Score^ score) :
	SpritesLinkedList(score)
{
}//End Constructor


 //////////////////////////////////////////////////////////////////////////
 // Checks to see if the player has collided with an item and then calls the 
 // ApplyEffects method to act according on the type of item it is 
 //////////////////////////////////////////////////////////////////////////

void ItemLinkedList::CheckItemCollisions(PlayerSprite ^ player)
{
	ItemSprite^  nodeWalker = (ItemSprite^)Head; //nodeWalker points at what is stored in head

	while (nodeWalker != nullptr) //Cycles through until it reaches the end of the list
	{
		if (nodeWalker->SpritesHaveCollided(player))
		{
			nodeWalker->ApplyEffects(player);
		}
		nodeWalker = (ItemSprite^)nodeWalker->Next; //Sets nodeWalker to point, at what the current item, is pointing at
	}
}//End CheckItemCollisions
