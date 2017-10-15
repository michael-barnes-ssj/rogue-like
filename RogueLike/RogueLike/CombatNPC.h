#pragma once

/*
This class creates an instance of an enemy sprite that may cause harm to the player had he drift too close to it.
It displays complex behaviour in the form of pursing the player if he wander into the search zone of the sprite using trig to find an angle toward the player.
Furthermore he has a probabilistic chance to throw projectiles at the player inflicting damage if they make contact.
If this sprite and the player collide, it will begin to attack the player in melee combat having a probabilistic chance of landing the blow.
When the player is not inside its search zone, the sprite will wander aimlessly.
*/

#include "FSMSprite.h"
#include "Projectile.h"
#include "ProjectileLinkedList.h"

ref class CombatNPC : public FSMSprite
{

private:

	//Fields
	int throwProjectile;
	int startXVel;
	int startYVel;
	array<Bitmap^>^ projectileSpriteSheet;
	ProjectileLinkedList^ projectiles;

private:

	//Methods only called within the class
	void approach(FSMSprite^ player);
	void orientX(FSMSprite^ player);
	void orientY(FSMSprite^ player);
	void fireProjectile(FSMSprite ^ player);

public:

	//Constructor
	CombatNPC(Graphics ^ startCanvas,
		Random ^ startRGen,
		array<Bitmap^>^ startSpriteSheet,
		int startNFrames,
		TileMap ^ startTileMap,
		int startScoreValue,
		int startMaxHealth,
		int startAttackDamage,
		ProjectileLinkedList^ startProjectiles,
		array<Bitmap^>^ startProjectileSpriteSheet);

	//Methods that can be called globally
	virtual void UpdateState(FSMSprite^ player) override;
	virtual void PerformAction(FSMSprite^ player) override;
};

