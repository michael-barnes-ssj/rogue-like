#pragma once

//////////////////////////////////////////////////////////////////////////
// This class is used to hold multiple instances of object types NonCombatNPC and CombatNPC.
// It contains methods that both apply to the NonCombatNPC and CombatNPC type objects and uses
// casting to enable the use of inheritance in this class hierarchy
//////////////////////////////////////////////////////////////////////////

#include "SpritesLinkedList.h"
#include "FSMSprite.h"

ref class NPCLinkedList : public SpritesLinkedList
{
public:

	//Constructor
	NPCLinkedList(Score^ score);

	//Methods that can be called globally
	void RunNodeFSM(FSMSprite^ player);
};

