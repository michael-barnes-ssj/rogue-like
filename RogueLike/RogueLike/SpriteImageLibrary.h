#pragma once

///////////////////////////////////////////////////////////////////////////////////////////////
// This class creates and holds arrays of bitmap images in the form of spritesheets
// for the gamemanger to use when intialising all the different sprites
///////////////////////////////////////////////////////////////////////////////////////////////

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


//Each Different direction of the sprite sheet images
public enum ImageDirection { DIR_NORTH, DIR_EAST, DIR_SOUTH, DIR_WEST };

ref class SpriteImageLibrary
{

public:

	//Gets and Sets
	property array<Bitmap^>^ PlayerWalkingImages;
	property array<Bitmap^>^ PlayerFightingImages;

	property array<Bitmap^>^ LogNPCWalkingImages;
	property array<Bitmap^>^ LogNPCSleepingImages;

	property array<Bitmap^>^ CivilianNPCWalkingImages;

	property array<Bitmap^>^ InfectedCivilianNPCWalkingImages;

	property array<Bitmap^>^ PortalImages;
	property array<Bitmap^>^ ProjectileImages;

	property array<Bitmap^>^ TreasureSilverCoinImages;
	property array<Bitmap^>^ TreasureGoldCoinImages;
	property array<Bitmap^>^ TreasureCrystalImages;

	property array<Bitmap^>^ SpeedBoostImages;
	property array<Bitmap^>^ HealthImages;
	property array<Bitmap^>^ MaxHealthBoosterImages;

public:

	//Constructor
	SpriteImageLibrary();

private:

	//Methods that are only called within the class
	array<Bitmap^>^ generatePlayerWalkingImages();
	array<Bitmap^>^ generatePlayerFightingImages();

	array<Bitmap^>^ generatePortal();
	array<Bitmap^>^ generateProjectileImage();

	array<Bitmap^>^ generatelogNPCWalkingImages();
	array<Bitmap^>^ generatelogNPCSleepingImages();

	array<Bitmap^>^ generateTreasureSilverCoinImages();
	array<Bitmap^>^ generateTreasureGoldCoinImages();
	array<Bitmap^>^ generateTreasureCrystalImages();

	array<Bitmap^>^ generateHealthImages();
	array<Bitmap^>^ generateSpeedBoostImages();
	array<Bitmap^>^ generateMaxHealthBoosterImages();

	array<Bitmap^>^ generateCivilianNPCWalkingImages();

	array<Bitmap^>^ generateInfectedCivilianNPCWalkingImages();
};

