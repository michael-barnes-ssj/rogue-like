#include "SpriteImageLibrary.h"



SpriteImageLibrary::SpriteImageLibrary()
{
	//Intialising fields
	PlayerWalkingImages = generatePlayerWalkingImages();
	PlayerFightingImages = generatePlayerFightingImages();

	LogNPCWalkingImages = generatelogNPCWalkingImages();
	LogNPCSleepingImages = generatelogNPCSleepingImages();

	CivilianNPCWalkingImages = generateCivilianNPCWalkingImages();

	InfectedCivilianNPCWalkingImages = generateInfectedCivilianNPCWalkingImages();

	PortalImages = generatePortal();
	ProjectileImages = generateProjectileImage();

	TreasureSilverCoinImages = generateTreasureSilverCoinImages();
	TreasureGoldCoinImages = generateTreasureGoldCoinImages();
	TreasureCrystalImages = generateTreasureCrystalImages();

	SpeedBoostImages = generateSpeedBoostImages();
	HealthImages = generateHealthImages();
	MaxHealthBoosterImages = generateMaxHealthBoosterImages();

}//End Constructor 


 ///////////////////////////////////////////////////////////////////////////////////////////////
 // Creates an array of bitmap image and returns it
 ///////////////////////////////////////////////////////////////////////////////////////////////

array<Bitmap^>^ SpriteImageLibrary::generatePlayerWalkingImages()
{

	array<Bitmap^>^ imageArray = gcnew array<Bitmap^>(4); //delcares array to hold images

	imageArray[ImageDirection::DIR_NORTH] = gcnew Bitmap("images/characterNorth.png"); //puts each image in array
	imageArray[ImageDirection::DIR_SOUTH] = gcnew Bitmap("images/characterSouth.png");
	imageArray[ImageDirection::DIR_EAST] = gcnew Bitmap("images/characterEast.png");
	imageArray[ImageDirection::DIR_WEST] = gcnew Bitmap("images/characterWest.png");


	return imageArray;

}//End


 ///////////////////////////////////////////////////////////////////////////////////////////////
 // Creates an array of bitmap image and returns it
 ///////////////////////////////////////////////////////////////////////////////////////////////

array<Bitmap^>^ SpriteImageLibrary::generatePlayerFightingImages()
{

	array<Bitmap^>^ imageArray = gcnew array<Bitmap^>(4); //delcares array to hold images

	imageArray[ImageDirection::DIR_NORTH] = gcnew Bitmap("images/characterFightNorth.png"); //puts each image in array
	imageArray[ImageDirection::DIR_SOUTH] = gcnew Bitmap("images/characterFightSouth.png");
	imageArray[ImageDirection::DIR_EAST] = gcnew Bitmap("images/characterFightEast.png");
	imageArray[ImageDirection::DIR_WEST] = gcnew Bitmap("images/characterFightWest.png");


	return imageArray;

}//End


 ///////////////////////////////////////////////////////////////////////////////////////////////
 // Creates an array of bitmap image and returns it
 ///////////////////////////////////////////////////////////////////////////////////////////////

array<Bitmap^>^ SpriteImageLibrary::generatePortal()
{

	array<Bitmap^>^ imageArrayPortal = gcnew array<Bitmap^>(1); //delcares array to hold images

	imageArrayPortal[0] = gcnew Bitmap("images/portal.png");

	return imageArrayPortal;

}//End


 ///////////////////////////////////////////////////////////////////////////////////////////////
 // Creates an array of bitmap image and returns it
 ///////////////////////////////////////////////////////////////////////////////////////////////

array<Bitmap^>^ SpriteImageLibrary::generatelogNPCWalkingImages()
{
	array<Bitmap^>^ imageArrayLog = gcnew array<Bitmap^>(4); //delcares array to hold images

	imageArrayLog[ImageDirection::DIR_NORTH] = gcnew Bitmap("images/logNorth.png");
	imageArrayLog[ImageDirection::DIR_SOUTH] = gcnew Bitmap("images/logSouth.png");
	imageArrayLog[ImageDirection::DIR_EAST] = gcnew Bitmap("images/logEast.png");
	imageArrayLog[ImageDirection::DIR_WEST] = gcnew Bitmap("images/logWest.png");


	return imageArrayLog;
}//End


 ///////////////////////////////////////////////////////////////////////////////////////////////
 // Creates an array of bitmap image and returns it
 ///////////////////////////////////////////////////////////////////////////////////////////////

array<Bitmap^>^ SpriteImageLibrary::generatelogNPCSleepingImages()
{
	array<Bitmap^>^ imageArrayLogSleep = gcnew array<Bitmap^>(1); //delcares array to hold images

	imageArrayLogSleep[0] = gcnew Bitmap("images/logSleep.png");

	return imageArrayLogSleep;
}//End


 ///////////////////////////////////////////////////////////////////////////////////////////////
 // Creates an array of bitmap image and returns it
 ///////////////////////////////////////////////////////////////////////////////////////////////

array<Bitmap^>^ SpriteImageLibrary::generateProjectileImage()
{
	array<Bitmap^>^ imageArrayPortal = gcnew array<Bitmap^>(1); //delcares array to hold images

	imageArrayPortal[0] = gcnew Bitmap("images/boomerang.png");

	return imageArrayPortal;
}//End


 ///////////////////////////////////////////////////////////////////////////////////////////////
 // Creates an array of bitmap image and returns it
 ///////////////////////////////////////////////////////////////////////////////////////////////

array<Bitmap^>^ SpriteImageLibrary::generateTreasureSilverCoinImages()
{
	array<Bitmap^>^ silverCoinArray = gcnew array<Bitmap^>(1);

	silverCoinArray[0] = gcnew Bitmap("images/coin_silver.png");

	return silverCoinArray;
}//End


 ///////////////////////////////////////////////////////////////////////////////////////////////
 // Creates an array of bitmap image and returns it
 ///////////////////////////////////////////////////////////////////////////////////////////////

array<Bitmap^>^ SpriteImageLibrary::generateHealthImages()
{
	array<Bitmap^>^ health = gcnew array<Bitmap^>(1);

	health[0] = gcnew Bitmap("images/redCandy.png");

	return health;
}//End


 ///////////////////////////////////////////////////////////////////////////////////////////////
 // Creates an array of bitmap image and returns it
 ///////////////////////////////////////////////////////////////////////////////////////////////

array<Bitmap^>^ SpriteImageLibrary::generateSpeedBoostImages()
{
	array<Bitmap^>^ speedBoost = gcnew array<Bitmap^>(1);

	speedBoost[0] = gcnew Bitmap("images/blueCandy.png");

	return speedBoost;
}//End


 ///////////////////////////////////////////////////////////////////////////////////////////////
 // Creates an array of bitmap image and returns it
 ///////////////////////////////////////////////////////////////////////////////////////////////

array<Bitmap^>^ SpriteImageLibrary::generateMaxHealthBoosterImages()
{
	array<Bitmap^>^ healthBoost = gcnew array<Bitmap^>(1);

	healthBoost[0] = gcnew Bitmap("images/healthPotion.png");

	return healthBoost;
}//End


 ///////////////////////////////////////////////////////////////////////////////////////////////
 // Creates an array of bitmap image and returns it
 ///////////////////////////////////////////////////////////////////////////////////////////////

array<Bitmap^>^ SpriteImageLibrary::generateTreasureGoldCoinImages()
{
	array<Bitmap^>^ silverCoinArray = gcnew array<Bitmap^>(1);

	silverCoinArray[0] = gcnew Bitmap("images/coin_gold.png");

	return silverCoinArray;
}//End


 ///////////////////////////////////////////////////////////////////////////////////////////////
 // Creates an array of bitmap image and returns it
 ///////////////////////////////////////////////////////////////////////////////////////////////

array<Bitmap^>^ SpriteImageLibrary::generateTreasureCrystalImages()
{
	array<Bitmap^>^ silverCoinArray = gcnew array<Bitmap^>(1);

	silverCoinArray[0] = gcnew Bitmap("images/crystals.png");

	return silverCoinArray;
}//End


 ///////////////////////////////////////////////////////////////////////////////////////////////
 // Creates an array of bitmap image and returns it
 ///////////////////////////////////////////////////////////////////////////////////////////////

array<Bitmap^>^ SpriteImageLibrary::generateCivilianNPCWalkingImages()
{
	array<Bitmap^>^ imageArray = gcnew array<Bitmap^>(4); //delcares array to hold images

	imageArray[ImageDirection::DIR_NORTH] = gcnew Bitmap("images/npcNorth.png"); //puts each image in array
	imageArray[ImageDirection::DIR_SOUTH] = gcnew Bitmap("images/npcSouth.png");
	imageArray[ImageDirection::DIR_EAST] = gcnew Bitmap("images/npcEast.png");
	imageArray[ImageDirection::DIR_WEST] = gcnew Bitmap("images/npcWest.png");

	return imageArray;
}//End


 ///////////////////////////////////////////////////////////////////////////////////////////////
 // Creates an array of bitmap image and returns it
 ///////////////////////////////////////////////////////////////////////////////////////////////

array<Bitmap^>^ SpriteImageLibrary::generateInfectedCivilianNPCWalkingImages()
{
	array<Bitmap^>^ imageArray = gcnew array<Bitmap^>(4); //delcares array to hold images

	imageArray[ImageDirection::DIR_NORTH] = gcnew Bitmap("images/npcPurpleNorth.png"); //puts each image in array
	imageArray[ImageDirection::DIR_SOUTH] = gcnew Bitmap("images/npcPurpleSouth.png");
	imageArray[ImageDirection::DIR_EAST] = gcnew Bitmap("images/npcPurpleEast.png");
	imageArray[ImageDirection::DIR_WEST] = gcnew Bitmap("images/npcPurpleWest.png");

	return imageArray;
}//End
