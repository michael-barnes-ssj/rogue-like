#pragma once

///////////////////////////////////////////////////////////////////////////////////////////////
// This class holds the stats of all FSMSprites and modifies them as the player 
// progresses onto each new level
///////////////////////////////////////////////////////////////////////////////////////////////

#include "Constants.h"

ref class SpriteInformation
{

public:

	//Gets and Sets
	property int PlayerHealth;
	property int PlayerDamage;
	property int LogHealth;
	property int CivilianHealth;
	property int CivilianDamage;
	property int InfectedHealth;
	property int InfectedDamage;

public:

	//Constructor
	SpriteInformation();

	//Methods that can be called globally
	void UpdateStats();
	void ResetValues();
};

