#include "NPCLinkedList.h"



NPCLinkedList::NPCLinkedList(Score^ score) :
	SpritesLinkedList(score)
{
}//End Constructor


 //////////////////////////////////////////////////////////////////////////
 // Casts each sprite to a FSMSprite so that can calls the UpdateState and
 // PerformAction methods
 //////////////////////////////////////////////////////////////////////////

void NPCLinkedList::RunNodeFSM(FSMSprite^ player)
{
	FSMSprite^  nodeWalker = (FSMSprite^)Head; //projectileWalker points at what is stored in head

											   //Cycles through until it reaches the end of the list
	while (nodeWalker != nullptr)
	{
		//nodeWalker->Patrol();
		nodeWalker->UpdateState(player);
		nodeWalker->PerformAction(player);//Calls the Move method of the item in the list that projectileWalker is pointing at
		nodeWalker = (FSMSprite^)nodeWalker->Next; //Sets projectileWalker to point, at what the current item, is pointing at
	}
} // End RunNodeFSM