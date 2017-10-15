#include "Score.h"



Score::Score()
{
	ResetValues(); //Setting all fields to default values

}//End Constructor 


 ///////////////////////////////////////////////////////////////////////////////////////////////
 // Updates the score value of the different NPC sprites each time the player completes a level
 ///////////////////////////////////////////////////////////////////////////////////////////////

void Score::UpdateScoreValues()
{
	LogScoreValue += Constants::LOG_SPRITE_SCORE_VALUE_INCREASE;
	CivilianScoreValue += Constants::CIVILIAN_SPRITE_SCORE_VALUE_INCREASE;
	InfectedScoreValue += Constants::INFECTED_SPRITE_SCORE_VALUE_INCREASE;

}//End UpdateScoreValues

 ///////////////////////////////////////////////////////////////////////////////////////////////
 // All fields are reset to their intial (on load) values
 ///////////////////////////////////////////////////////////////////////////////////////////////

void Score::ResetValues()
{
	CurrentScore = 0;

	PortalScoreValue = Constants::PORTAL_SPRITE_SCORE_VALUE;
	LogScoreValue = Constants::LOG_SPRITE_SCORE_VALUE;
	CivilianScoreValue = Constants::CIVILIAN_SPRITE_SCORE_VALUE;
	InfectedScoreValue = Constants::INFECTED_SPRITE_SCORE_VALUE;
	CrystalScoreValue = Constants::CRYSTAL_SPRITE_SCORE_VALUE;
	GoldCoinScoreValue = Constants::GOLD_COIN_SPRITE_SCORE_VALUE;
	SilverCoinScoreValue = Constants::SILVER_COIN_SPRITE_SCORE_VALUE;
	HealthBoosterScoreValue = Constants::HEALTH_BOOSTER_SPRITE_SCORE_VALUE;
	HealthScoreValue = Constants::HEALTH_SPRITE_SCORE_VALUE;
	BootsScoreValue = Constants::BOOTS_SPRITE_SCORE_VALUE;

}//End ResetValues
