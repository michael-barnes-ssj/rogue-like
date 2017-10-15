#include "ProjectileLinkedList.h"
#include "FSMSprite.h"



ProjectileLinkedList::ProjectileLinkedList(Score^ score) :
	SpritesLinkedList(score)
{
}//End Contructor


 //////////////////////////////////////////////////////////////////////////
 // Casts each sprite to a Projectile Sprite so that can calls 
 //the UpdateState and PerformAction methods
 //////////////////////////////////////////////////////////////////////////

void ProjectileLinkedList::RunProjectileCycle(FSMSprite^ player)
{
	Projectile^ nodeWalker = (Projectile^)Head;

	while (nodeWalker != nullptr)
	{

		nodeWalker->UpdateState(player);
		nodeWalker->PerformAction(player);

		nodeWalker = (Projectile^)nodeWalker->Next;
	}
}//End RunProjectileCycle
