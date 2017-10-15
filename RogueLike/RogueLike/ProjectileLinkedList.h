#pragma once

//////////////////////////////////////////////////////////////////////////
// This class is used to hold multiple instances of object type Projectile.
// It contains methods that only apply to the projectile type object and uses
// casting to enable the use of inheritance in this class hierarchy
//////////////////////////////////////////////////////////////////////////

#include "SpritesLinkedList.h"
#include "Projectile.h"

ref class ProjectileLinkedList : public SpritesLinkedList
{
public:

	//Constructor
	ProjectileLinkedList(Score^ score);

	//Methods that can be called globally
	void RunProjectileCycle(FSMSprite^ player);
};

