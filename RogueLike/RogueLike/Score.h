#pragma once

///////////////////////////////////////////////////////////////////////////////////////////////
// This class is used to keep track and update the players score and also the score balue of each
// different type of sprite in the game 
///////////////////////////////////////////////////////////////////////////////////////////////

#include "Constants.h"

ref class Score
{
public:

	//Gets and Sets
	property int CurrentScore;

	property int PortalScoreValue;
	property int LogScoreValue;
	property int CivilianScoreValue;
	property int InfectedScoreValue;
	property int CrystalScoreValue;
	property int GoldCoinScoreValue;
	property int SilverCoinScoreValue;
	property int HealthBoosterScoreValue;
	property int HealthScoreValue;
	property int BootsScoreValue;

public:

	//Constructor
	Score();

	//Methods that can be called globally
	void UpdateScoreValues();
	void ResetValues();
};

