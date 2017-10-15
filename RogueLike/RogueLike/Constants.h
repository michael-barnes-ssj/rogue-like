#pragma once

ref class Constants
{
public:

	//Map tile properties
	static const int NTILES = 8;
	static const int TILESIDE = 48;

	//Map size
	static const int NCOLS = 180;
	static const int NROWS = 120;


	//Dungeon room creation
	static const int MIN_NUM_ROOMS = 9;
	static const int MAX_NUM_ROOMS = 10;
	static const int MIN_ROOM_SIZE = 20;
	static const int MAX_ROOM_SIZE = 25;

	//Max movement directions
	static const int NDIRECTIONS = 4;
	
	//Player
	static const int PLAYER_SPRITE_NFRAMES = 4;
	static const int PLAYER_SPRITE_START_HEALTH = 500;
	static const int PLAYER_SPRITE_START_DAMAGE = 10;
	static const int PLAYER_START_SPEED_VALUE = 10;
	static const int HEALTH_RESTORE_VALUE = 75;
	static const int HEALTH_MAX_INCREASE_VALUE = 50;
	static const int SPEED_INCREASE_VALUE = 6;

	//Search zone and collisions
	static const double COLLISION_BOX_OFFSET = 0.1;
	static const int SEARCH_ZONE_WIDTH_NUM_TIMES_SIZE = 18;
	static const int SEARCH_ZONE_HEIGHT_NUM_TIMES_SIZE = 10;

	//Treasure
	static const int NUMBER_OF_TREASURE = 30;
	static const int CRYSTAL_SPRITE_SCORE_VALUE = 500;
	static const int GOLD_COIN_SPRITE_SCORE_VALUE = 100;
	static const int SILVER_COIN_SPRITE_SCORE_VALUE = 50;

	//NPCS
	static const int NUMBER_OF_NPCS = 10;

	static const int RANDOM_CHANGE_STATE_RANGE = 1000;
	static const int APPROACH_SPEED_INCREASE = 4;
	static const int RANDOM_LAND_BLOW_RANGE = 500;
	static const int LAND_BLOW_RANGE = 100;
	static const int CHANGE_DIRECTION_RANGE = 30;

	static const int LOG_SPRITE_START_HEALTH = 80;
	static const int LOG_SPRITE_START_HEALTH_INCREASE = 20;
	static const int LOG_SPRITE_SCORE_VALUE = 80;
	static const int LOG_SPRITE_SCORE_VALUE_INCREASE = 20;
	static const int LOG_SPRITE_NWALKFRAMES = 4;
	static const int LOG_SPRITE_NSLEEPFRAMES = 12;

	static const int CIVILIAN_SPRITE_START_HEALTH = 50;
	static const int CIVILIAN_SPRITE_START_HEALTH_INCREASE = 20;	
	static const int CIVILIAN_SPRITE_START_DAMAGE = 10;
	static const int CIVILIAN_SPRITE_START_DAMAGE_INCREASE = 2;
	static const int CIVILIAN_SPRITE_SCORE_VALUE = 90;
	static const int CIVILIAN_SPRITE_SCORE_VALUE_INCREASE = 30;
	static const int CIVILIAN_SPRITE_NWALKFRAMES = 4;

	static const int INFECTED_SPRITE_START_HEALTH = 200;
	static const int INFECTED_SPRITE_START_HEALTH_INCREASE = 50;
	static const int INFECTED_SPRITE_START_DAMAGE = 3;
	static const int INFECTED_SPRITE_START_DAMAGE_INCREASE = 1;
	static const int INFECTED_SPRITE_SCORE_VALUE = 150;
	static const int INFECTED_SPRITE_SCORE_VALUE_INCREASE = 50;
	static const int INFECTED_SPRITE_NWALKFRAMES = 4;

	//Projectile
	static const int PROJECTILE_CHANCE = 1000;
	static const int PROJECTILE_LAUNCH_RANGE = 20;
	static const int PROJECTILE_SPRITE_NFRAMES = 8;
	static const int PROJECTILE_POWER_MAX = 10;
	static const int PROJECTILE_GRAVITY_MAX = 1;
	static const int MAX_PROJECTILE_LIFE = 120;

	//Items
	static const int NUMBER_OF_ITEMS = 20;
	static const int HEALTH_BOOSTER_SPRITE_SCORE_VALUE = 200;
	static const int HEALTH_SPRITE_SCORE_VALUE = 200;
	static const int BOOTS_SPRITE_SCORE_VALUE = 200;

	//Portal
	static const int PORTAL_SPRITE_SCORE_VALUE = 500;
	static const int PORTAL_SPRITE_SCORE_VALUE_INCREASE = 100;
	static const int PORTAL_SPRITE_NFRAMES = 4;

	//Menu Form
	static const int QUARTER_VALUE = 4;
	static const int DISTANCE_FROM_BOTTOM = 4;

	//Main Form
	static const int BANNER_WIDTH = 700;
	static const int GAME_PANEL_LEFT_DISTANCE = 40;
	static const int DISTANCE_BETWEEN_GAME_BUTTONS = 4;
	static const double PANEL_HEIGHT_PERECENT = 0.75;

	//Health bar
	static const int HEALTH_BAR_HEIGHT = 4;
	static const int HEALTH_BAR_DISTANCE_HIGH = 5;

	//FSM Sprite

	static const int MIN_VELOCITY = 3;
	static const int MAX_VELOCITY = 7;

	//Game manager

	static const int RANDOM_SPRITE_CHANCE = 100; ///////////////////////////////////new
	static const int INFECTED_SPRITE_CHANCE = 100; ///////////////////////////////////new
	static const int RANDOM_TRESAURE = 100; ///////////////////////////////////new
	static const int RANDOM_TRESAURE_MIN = 25; ///////////////////////////////////new
	static const int RANDOM_TRESAURE_HIGH_CHANCE = 25; ///////////////////////////////////new
	static const int RANDOM_TRESAURE_MID_CHANCE = 70; ///////////////////////////////////new
	static const int RANDOM_TRESAURE_LOW_CHANCE = 95; ///////////////////////////////////new

	static const int RANDOM_ITEM = 100; //////////////////////////////new
	static const int RANDOM_ITEM_MIN = 50; ///////////////////////////////////new	
	static const int RANDOM_ITEM_MID_CHANCE = 75; ///////////////////////////////////new
	static const int RANDOM_ITEM_LOW_CHANCE = 95; ///////////////////////////////////new

	//NonCombatNPC

	static const int RANDOM_STATE_NUMBER = 1000; ///////////////////////////////////new	
	static const int RANDOM_STATE_CHANCE = 900; ///////////////////////////////////new	
	static const int RANDOM_STATE_CHANCE_DIRECTION = 30; ///////////////////////////////////new	
	static const int RANDOM_STATE_CHANCE_TO_PATROL = 100; ///////////////////////////////////new	
	static const int SLEEP_TICK_LIMIT = 1000; ///////////////////////////////////new	
	static const int PATROL_TICK_LIMIT = 150; ///////////////////////////////////new

	//projectile

	static const int PROJECTILE_MAX_DISTANCE = 3; ///////////////////////////////////new
	static const int PROJECTILE_MIN_DISTANCE = -3; ///////////////////////////////////new

	//FOW

	static const int FOG_WIDE = 18; ///////////////////////////////////new
	static const int FOG_HIGH = 12; ///////////////////////////////////new
	static const int FOG_OFFSET_ROW = 5; ///////////////////////////////////new
	static const int FOG_OFFSET_COL = 8; ///////////////////////////////////new
	
	//FeedbackMessage
	static const int MESSAGE_DISPLAY_TIME = 80; //////NEW


};

