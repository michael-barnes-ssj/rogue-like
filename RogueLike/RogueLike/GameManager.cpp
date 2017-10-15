#include "GameManager.h"


///////////////////////////////////////////////////////////////////////////////////////////////
// Constructor. Initialises Variables
///////////////////////////////////////////////////////////////////////////////////////////////

GameManager::GameManager(Graphics ^ startCanvas, Random ^ randomGenerator, Size ^ canvasSize)
{
	canvas = startCanvas;
	rGen = randomGenerator;
	nRows = Constants::NROWS;
	nCols = Constants::NCOLS;		
	
	spriteImageLibrary = gcnew SpriteImageLibrary();
	spriteInfo = gcnew SpriteInformation();
	ScoreController = gcnew Score();
	MessageController = gcnew FeedBackMessages();
	tileSet = gcnew TileSet(Constants::NTILES);
	fillTileSet();	
	tileMap = gcnew TileMap(tileSet, nRows, nCols);
	tileSide = Constants::TILESIDE;
	viewport = gcnew ViewPort(canvasSize, tileMap, canvas);
	miniMap = gcnew Minimap(canvas, tileMap, canvasSize, viewport->ViewportTilesWide, viewport->ViewportTilesHigh);
	dungeonGenerator = gcnew Dungeon(rGen, nRows, nCols,viewport->ViewportTilesWide,viewport->ViewportTilesHigh);
	StartNewGame();

}//End Constructor

 ///////////////////////////////////////////////////////////////////////////////////////////////
 // Calls methods to set up new Level
 ///////////////////////////////////////////////////////////////////////////////////////////////

void GameManager::setUpNewLevel()
{
	setMapFromDungeon();
	treasure = createTreasure(Constants::NUMBER_OF_TREASURE);
	npcList = createNPCs(Constants::NUMBER_OF_NPCS);
	items = createItems(Constants::NUMBER_OF_ITEMS);
	portal->SpawnInRoom(dungeonGenerator->Rooms);
	player->SpawnInRoom(dungeonGenerator->Rooms);		
	tileMap->ResetFog();
}

///////////////////////////////////////////////////////////////////////////////////////////////
// Sets up a completely new game. Calls methods needed to do this
///////////////////////////////////////////////////////////////////////////////////////////////

void GameManager::StartNewGame()
{
	ScoreController->ResetValues();
	spriteInfo->ResetValues();
	player = createPlayer();
	portal = createPortal();
	npcProjectiles = gcnew ProjectileLinkedList(ScoreController);
	setUpNewLevel();
}

///////////////////////////////////////////////////////////////////////////////////////////////
// Creates each tile that will be used by the tilemap
// Assigns to each tile:
//	- An Index value in the form of enumerations
//  - A string that is the path to locate that tiles image inside the project folder
//  - A boolean that states if that tile is walkable or not.
///////////////////////////////////////////////////////////////////////////////////////////////

void GameManager::fillTileSet()
{
	tileSet->SetTileArrayEntry(TileType::SURROUNDINGTERRAIN, "Images/treeTileBig.png", false);
	tileSet->SetTileArrayEntry(TileType::SURROUNDINGTERRAIN2, "Images/treeTile2Big.png", false);
	tileSet->SetTileArrayEntry(TileType::WALL, "Images/grownStumpTileBig.png", false);
	tileSet->SetTileArrayEntry(TileType::FLOOR, "Images/grassTileBig.png", true);
	tileSet->SetTileArrayEntry(TileType::CORRIDOR, "Images/grassTileBig.png", true);
	tileSet->SetTileArrayEntry(TileType::PADDING, "Images/stumpTileBig.png", false);
	tileSet->SetTileArrayEntry(TileType::DOOR, "Images/grassTileBig.png", true);

}//End FillTileSet

///////////////////////////////////////////////////////////////////////////////////////////////
// Called at each tick of the timer 
// Drives the progression of the game through method calls of the
// Sprites, LinkedLists, minimapm portal and Viewport Classes
///////////////////////////////////////////////////////////////////////////////////////////////

void GameManager::RunGameCycle()
{	
	//Viewport methods
	viewport->CentreViewPortAroundSprite(player);
	viewport->ViewportDraw();

	//minimap methods
	miniMap->DrawMiniMap(player->XPos,player->YPos);

	//Treasure methods
	treasure->DeleteAllDeadNodes();
	treasure->CheckItemCollisions(player);
	treasure->DrawInTheViewport(viewport->ViewportWorldX, viewport->ViewportWorldY, viewport->ViewPortPixelWidth,viewport->ViewPortPixelHeight, tileMap->VisibleMap);
	
	//Portal Methods
	portal->Draw(viewport->ViewportWorldX, viewport->ViewportWorldY, tileMap->VisibleMap);
	
	//Items methods
	items->DeleteAllDeadNodes();
	items->CheckItemCollisions(player);
	items->DrawInTheViewport(viewport->ViewportWorldX, viewport->ViewportWorldY, viewport->ViewPortPixelWidth, viewport->ViewPortPixelHeight, tileMap->VisibleMap);	
	
	//Player methods
	player->UpdateState();
	player->PerformAction();
	player->Draw(viewport->ViewPortPixelWidth / 2, viewport->ViewPortPixelHeight / 2);
	
	//NPCLIST methods
	npcList->DeleteAllDeadNodes();
	npcList->RunNodeFSM(player);	
	npcList->DrawInTheViewport(viewport->ViewportWorldX, viewport->ViewportWorldY, viewport->ViewPortPixelWidth, viewport->ViewPortPixelHeight, tileMap->VisibleMap);
	
	//NPCprojectile methods
	npcProjectiles->DeleteAllDeadNodes();
	npcProjectiles->RunProjectileCycle(player);
	npcProjectiles->DrawInTheViewport(viewport->ViewportWorldX, viewport->ViewportWorldY, viewport->ViewPortPixelWidth, viewport->ViewPortPixelHeight, tileMap->VisibleMap);
	
	//MessageController methods
	MessageController->CountDownMessageTimeout();
	
	//Check for portal collision, if true ser up new level
	if (portal->SpritesHaveCollided(player))
	{
		portal->ScoreForLevelCompletion();
		ScoreController->UpdateScoreValues();
		spriteInfo->UpdateStats();
		portal->ScoreValue += Constants::PORTAL_SPRITE_SCORE_VALUE_INCREASE;
		setUpNewLevel();	
	}	
	
}//End RunGameCycle

 ///////////////////////////////////////////////////////////////////////////////////////////////
 // Takes map from dungeon and gives it to tilemap
 ///////////////////////////////////////////////////////////////////////////////////////////////

void GameManager::setMapFromDungeon()
{
	array<int, 2>^ map = dungeonGenerator->GenerateMap();
	tileMap->SetTileMap(map);
}

///////////////////////////////////////////////////////////////////////////////////////////////
// Creates and Returns a linked list of randomly generated npcs
///////////////////////////////////////////////////////////////////////////////////////////////

NPCLinkedList ^ GameManager::createNPCs(int numNPCs)
{
	NPCLinkedList^ NPCList = gcnew NPCLinkedList(ScoreController);
	Sprite^ combatNPC;
	Sprite^ nonCombatNPC;
	int randomSprite;

	//Set images
	array<Bitmap^>^ infectedCivilianNPCWalkingImages = spriteImageLibrary->InfectedCivilianNPCWalkingImages;
	array<Bitmap^>^ projectileImages = spriteImageLibrary->ProjectileImages;
	array<Bitmap^>^ logWalkingImages = spriteImageLibrary->LogNPCWalkingImages;
	array<Bitmap^>^ logSleepingImages = spriteImageLibrary->LogNPCSleepingImages;
	array<Bitmap^>^ civilianNPCWalkingImages = spriteImageLibrary->CivilianNPCWalkingImages;

	for (int i = 0; i < numNPCs; i++)
	{
		randomSprite = rGen->Next(Constants::RANDOM_SPRITE_CHANCE); //generate rGen

		nonCombatNPC = gcnew NonCombatNPC(canvas, rGen, logWalkingImages, Constants::LOG_SPRITE_NWALKFRAMES, tileMap,ScoreController->LogScoreValue, logSleepingImages, Constants::LOG_SPRITE_NSLEEPFRAMES, spriteInfo->LogHealth,0);

		if (randomSprite > Constants::INFECTED_SPRITE_CHANCE) // if over sprite chance, make infected sprite
		{
			combatNPC = gcnew CombatNPC(canvas, rGen, infectedCivilianNPCWalkingImages, Constants::INFECTED_SPRITE_NWALKFRAMES, tileMap, ScoreController->InfectedScoreValue, spriteInfo->InfectedHealth, spriteInfo->InfectedDamage, npcProjectiles, projectileImages);
		}
		else //make civilian
		{
			combatNPC = gcnew CombatNPC(canvas, rGen, civilianNPCWalkingImages, Constants::CIVILIAN_SPRITE_NWALKFRAMES, tileMap, ScoreController->CivilianScoreValue, spriteInfo->CivilianHealth,spriteInfo->CivilianDamage, npcProjectiles, projectileImages);
		}

		//Spawn sprites in room
		nonCombatNPC->SpawnInRoom(dungeonGenerator->Rooms);
		combatNPC->SpawnInRoom(dungeonGenerator->Rooms);
		//add to list
		NPCList->AddNode(nonCombatNPC);
		NPCList->AddNode(combatNPC);
	}

	return NPCList;
}
///////////////////////////////////////////////////////////////////////////////////////////////
// Creates and Returns a PLayerSprite. Creates the player need to know
///////////////////////////////////////////////////////////////////////////////////////////////

PlayerSprite ^ GameManager::createPlayer()
{
	PlayerSprite^ player;

	array<Bitmap^>^ playerImages = spriteImageLibrary->PlayerWalkingImages;
	array<Bitmap^>^ playerFightImages = spriteImageLibrary->PlayerFightingImages;

	player = gcnew PlayerSprite(canvas, rGen, playerImages, Constants::PLAYER_SPRITE_NFRAMES, tileMap, 0, playerFightImages, spriteInfo->PlayerHealth,spriteInfo->PlayerDamage); //return a new sprite

	return player;
}

///////////////////////////////////////////////////////////////////////////////////////////////
// Creates and Returns a linked list of randomly generated treasure
///////////////////////////////////////////////////////////////////////////////////////////////

ItemLinkedList^ GameManager::createTreasure(int numCoins)
{
	ItemLinkedList^ treasureList = gcnew ItemLinkedList(ScoreController);
	
	array<Bitmap^>^ silverCoinImages = spriteImageLibrary->TreasureSilverCoinImages;
	array<Bitmap^>^ goldCoinImages = spriteImageLibrary->TreasureGoldCoinImages;
	array<Bitmap^>^ crystalImages = spriteImageLibrary->TreasureCrystalImages;	

	ItemSprite^ newTreasure;
	int randomSprite;

	for (int i = 0; i < numCoins; i++)
	{
		randomSprite = rGen->Next(Constants::RANDOM_TRESAURE);

		if (randomSprite > Constants::RANDOM_TRESAURE_MIN) //if over min amount
		{
			if (randomSprite >  Constants::RANDOM_TRESAURE_LOW_CHANCE) //if lowest chance make crystal
			{
				newTreasure = gcnew ItemSprite(canvas, rGen, crystalImages, 8, tileMap, ScoreController->CrystalScoreValue, TREASURE, MessageController);
			}
			else if (randomSprite > Constants::RANDOM_TRESAURE_MID_CHANCE) //if middle chance make gold
			{
				newTreasure = gcnew ItemSprite(canvas, rGen, goldCoinImages, 8, tileMap, ScoreController->GoldCoinScoreValue, TREASURE, MessageController);
			}
			else if (randomSprite > Constants::RANDOM_TRESAURE_HIGH_CHANCE) //if high chance make silver
			{
				newTreasure = gcnew ItemSprite(canvas, rGen, silverCoinImages, 8, tileMap, ScoreController->SilverCoinScoreValue, TREASURE, MessageController);
			}

			newTreasure->SpawnInRoom(dungeonGenerator->Rooms);
			treasureList->AddNode(newTreasure);
		}
	}

	return treasureList;
}

///////////////////////////////////////////////////////////////////////////////////////////////
// Creates and Returns a linked list of randomly generated items
///////////////////////////////////////////////////////////////////////////////////////////////

ItemLinkedList^ GameManager::createItems(int numItems)
{
	ItemLinkedList^ itemList = gcnew ItemLinkedList(ScoreController);

	array<Bitmap^>^ bootImages = spriteImageLibrary->SpeedBoostImages;
	array<Bitmap^>^ healthImages = spriteImageLibrary->HealthImages;
	array<Bitmap^>^ healthBoosterImages = spriteImageLibrary->MaxHealthBoosterImages;
	
	Sprite^ newItem;
	int randomSprite;

	for (int i = 0; i < numItems; i++)
	{
		randomSprite = rGen->Next(Constants::RANDOM_ITEM);
		
		if (randomSprite > Constants::RANDOM_ITEM_MIN) // if over min amount
		{
			if (randomSprite > Constants::RANDOM_ITEM_LOW_CHANCE) //if low chance make health booster
			{
				newItem = gcnew ItemSprite(canvas, rGen, healthBoosterImages, 1, tileMap, ScoreController->HealthBoosterScoreValue, BOOSTER, MessageController);
			}
			else if (randomSprite > Constants::RANDOM_ITEM_MID_CHANCE) //if mid chance make boots
			{
				newItem = gcnew ItemSprite(canvas, rGen, bootImages, 1, tileMap, ScoreController->HealthScoreValue, BOOTS, MessageController);
			}
			else //else make health
			{
				newItem = gcnew ItemSprite(canvas, rGen, healthImages, 1, tileMap, ScoreController->BootsScoreValue, HEALTH, MessageController);
			}

			newItem->SpawnInRoom(dungeonGenerator->Rooms);
			itemList->AddNode(newItem);
		}
	}	

	return itemList;
}

///////////////////////////////////////////////////////////////////////////////////////////////
// Creates and Returns a portal
///////////////////////////////////////////////////////////////////////////////////////////////

Portal ^ GameManager::createPortal()
{
	Portal^ portal;

	array<Bitmap^>^ portalImages = spriteImageLibrary->PortalImages;

	portal = gcnew Portal(canvas, rGen, portalImages, 4, tileMap, ScoreController->PortalScoreValue, ScoreController);

	return portal;
}

///////////////////////////////////////////////////////////////////////////////////////////////
// Handles key input. Key down event. Each key changes direction state and action state of player
///////////////////////////////////////////////////////////////////////////////////////////////


void GameManager::KeyDown(KeyEventArgs ^ down)
{
	switch (down->KeyData)
	{
	case Keys::A:
		player->ActionState = PATROL;
		player->DirectionState = EDirection::WEST;
		break;
	case Keys::D:
		player->ActionState = PATROL;
		player->DirectionState = EDirection::EAST;
		break;
	case Keys::W:
		player->ActionState = PATROL;
		player->DirectionState = EDirection::NORTH;
		break;
	case Keys::S:
		player->ActionState = PATROL;
		player->DirectionState = EDirection::SOUTH;		
		break;
	case Keys::Space:
		player->ActionState = ATTACK;
		break;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
// Handles key input. Key up event. Each key changes action state of player
///////////////////////////////////////////////////////////////////////////////////////////////

void GameManager::KeyUp(KeyEventArgs ^ e)
{
	switch (e->KeyData)
	{
	case Keys::A:
		player->ActionState = SLEEP;
		break;
	case Keys::D:
		player->ActionState = SLEEP;
		break;
	case Keys::W:
		player->ActionState = SLEEP;
		break;
	case Keys::S:
		player->ActionState = SLEEP;

		break;
	}
}
