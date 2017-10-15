#pragma once

/*
	This class controls the entire game. It creates an instance of all the classes needed to run the game. It calls the methods in the classes
	it creates to generate the dungeon and perform the game cycle.
*/

#include"TileMap.h"
#include"TileSet.h"
#include"ViewPort.h"
#include"Dungeon.h"
#include"Constants.h"
#include "PlayerSprite.h"
#include "SpritesLinkedList.h"
#include "ItemLinkedList.h"
#include "NPCLinkedList.h"
#include "ProjectileLinkedList.h"
#include "Portal.h"
#include "NonCombatNPC.h"
#include "CombatNPC.h"
#include "Score.h"
#include "SpriteImageLibrary.h"
#include "ItemSprite.h"
#include "Minimap.h"
#include "SpriteInformation.h"
#include "FeedBackMessages.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class GameManager
{
private:

	//Fields
	Graphics^ canvas;
	Random^ rGen;
	TileMap^ tileMap;
	TileSet^ tileSet;
	ViewPort^ viewport;
	Minimap^ miniMap;
	Dungeon^ dungeonGenerator;
	SpriteImageLibrary^ spriteImageLibrary;
	SpriteInformation^ spriteInfo;
	NPCLinkedList^ npcList;	
	ItemLinkedList^ treasure;
	ItemLinkedList^ items;
	Portal^ portal;
	ProjectileLinkedList^ npcProjectiles;

	int nRows;
	int nCols;
	int tileSide;

public:

	property FeedBackMessages^ MessageController;
	property Score^ ScoreController;
	property PlayerSprite^ player;

public:

	GameManager(Graphics ^ startCanvas, Random ^ randomGenerator, Size^ canvasSize); //Constructor

	//Methods
	void StartNewGame();
	void RunGameCycle();
	void KeyDown(KeyEventArgs^  e);
	void KeyUp(KeyEventArgs^  e);

private:

	//Methods
	void fillTileSet();
	void setMapFromDungeon();
	NPCLinkedList^ createNPCs(int numNPCs);
	PlayerSprite^ createPlayer();
	ItemLinkedList^ createTreasure(int numCoins);
	ItemLinkedList ^ createItems(int numItems);
	Portal^ createPortal();
	void setUpNewLevel();
};

