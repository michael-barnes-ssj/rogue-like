#include "SpriteInformation.h"



SpriteInformation::SpriteInformation()
{
	ResetValues(); //Sets all fields to default values

}//End Constuctor 


 ///////////////////////////////////////////////////////////////////////////////////////////////
 // Each time the player enters a new level the health and damage of each of the NPCSprites
 // are increased by different values unique to that type of sprite
 ///////////////////////////////////////////////////////////////////////////////////////////////

void SpriteInformation::UpdateStats()
{
	LogHealth += Constants::LOG_SPRITE_START_HEALTH_INCREASE;
	CivilianHealth += Constants::CIVILIAN_SPRITE_START_HEALTH_INCREASE;
	CivilianDamage += Constants::CIVILIAN_SPRITE_START_DAMAGE_INCREASE;
	InfectedHealth += Constants::INFECTED_SPRITE_START_HEALTH_INCREASE;
	InfectedDamage += Constants::INFECTED_SPRITE_START_DAMAGE_INCREASE;
}


///////////////////////////////////////////////////////////////////////////////////////////////
// Sets all the FSMSprites health and damage to their default values
///////////////////////////////////////////////////////////////////////////////////////////////

void SpriteInformation::ResetValues()
{
	PlayerHealth = Constants::PLAYER_SPRITE_START_HEALTH;
	PlayerDamage = Constants::PLAYER_SPRITE_START_DAMAGE;
	LogHealth = Constants::LOG_SPRITE_START_HEALTH;
	CivilianHealth = Constants::CIVILIAN_SPRITE_START_HEALTH;
	CivilianDamage = Constants::CIVILIAN_SPRITE_START_DAMAGE;
	InfectedHealth = Constants::INFECTED_SPRITE_START_HEALTH;
	InfectedDamage = Constants::INFECTED_SPRITE_START_DAMAGE;
}
