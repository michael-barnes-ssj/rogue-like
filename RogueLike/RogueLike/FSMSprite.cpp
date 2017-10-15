#include "FSMSprite.h"


///////////////////////////////////////////////////////////////////////////////////////////////
// Contructor - intialise variables
///////////////////////////////////////////////////////////////////////////////////////////////

FSMSprite::FSMSprite(Graphics ^ startCanvas, Random ^ startRGen, array<Bitmap^>^ startSpriteSheet, int startNFrames, TileMap ^ startTileMap, int startScoreValue, int startMaxHealth, int startAttackDamage):
			Sprite(startCanvas, startRGen, startSpriteSheet, startNFrames, startTileMap, startScoreValue)
{
	velocityDirections = SetVelocityDirections();
	SleepingTicks = 0;
	PatrolTicks = 0;
	RandomChangeState = 0;
	updateSearchZone();
	lastDirection = DirectionState;
	nWalkFrames = startNFrames;
	movementSpriteSheet = startSpriteSheet;
	MaxHealth = startMaxHealth;
	Health = MaxHealth;
	healthBarHeight = Constants::HEALTH_BAR_HEIGHT;
	healthBarWidth = FrameWidth;
	AttackDamage = startAttackDamage;
} //End constructor


//Empty methods never implemented, class is absract and methods will always be overriden.
void FSMSprite::UpdateState(FSMSprite ^ player) {}
void FSMSprite::PerformAction(FSMSprite ^ player) {}

///////////////////////////////////////////////////////////////////////////////////////////////
// Overrided draw method calls draw health bar
///////////////////////////////////////////////////////////////////////////////////////////////

void FSMSprite::Draw(int xLocation, int yLocation)
{
	Bitmap^ currentBitmap = spriteSheet[DirectionState];
	int startX = currentFrame* FrameWidth;
	Rectangle rectangle = Rectangle(startX, 0, FrameWidth, FrameHeight);
	canvas->DrawImage(currentBitmap, xLocation, yLocation, rectangle, GraphicsUnit::Pixel);

	// Draw healthbar
	drawHealthBar(xLocation, yLocation);

} //End draw

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Moves the x and y position based on the velocity directions. Updates the collision rectangle and search zone
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void FSMSprite::Move() //Moves x and y positions in direction based on their state.
{
	XPos += xVel * velocityDirections[DirectionState].X;
	YPos += yVel * velocityDirections[DirectionState].Y;
	updateCollisonBox();
	updateSearchZone();

} //End move

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Draws health bar above player
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void FSMSprite::drawHealthBar(int xLocation, int yLocation) //Moves x and y positions in direction based on their state.
{
	//Moves healthbar above sprite
	int healthBarDistanceHigh = Constants::HEALTH_BAR_DISTANCE_HIGH;
	int calculateHealth = (int)healthBarWidth*Health / MaxHealth;
	
	//creates rectangles to draw based on health
	Rectangle maxHealthRectangle = Rectangle(xLocation, yLocation - healthBarDistanceHigh, healthBarWidth, healthBarHeight);
	Rectangle healthRectangle = Rectangle(xLocation, yLocation - healthBarDistanceHigh, calculateHealth, healthBarHeight);

	//Draws rectangles
	canvas->FillRectangle(Brushes::Red, maxHealthRectangle);
	canvas->FillRectangle(Brushes::LightGreen, healthRectangle);

} //end drawHealthBar


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Returns array of points to use as velocity directions. NORTH SOUTH EAST WEST
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
array<Point>^ FSMSprite::SetVelocityDirections()
{
	array<Point>^ directions = gcnew array<Point>(Constants::NDIRECTIONS);
	directions[EDirection::NORTH] = Point(0, -1);
	directions[EDirection::SOUTH] = Point(0, 1);
	directions[EDirection::EAST] = Point(1, 0);
	directions[EDirection::WEST] = Point(-1, 0);

	return directions;
} //End Set Velocity Directions


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Returns a boolean saying if the next tile is walkable or not. Finds sprites next position based on
// their velocity and direction. Then asks tilemap if the tile they will be on is walkable or not and return result.
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool FSMSprite::FindOutIfNextTileIsWalkable()
{
	int nextXPos = CollisionBox.X + xVel* velocityDirections[DirectionState].X; //finds the pixel location after next move.
	int nextYPos = CollisionBox.Y + yVel * velocityDirections[DirectionState].Y;

	switch (DirectionState)
	{
	case EDirection::EAST: //if going east, use middle rightside as collision point
		nextXPos += CollisionBox.Width;
		nextYPos += CollisionBox.Height / 2;
		break;

	case EDirection::SOUTH:	//if going south, use middle bottom as collision point	
		nextXPos += CollisionBox.Width / 2;
		nextYPos += CollisionBox.Height /2;

	case EDirection::WEST: //if going west, use middle left as collision point
		nextYPos += CollisionBox.Height /2;
		break;

	case EDirection::NORTH: //if going north, use middle top as collision point
		nextXPos += CollisionBox.Width / 2;
		break;
	}

	int tileRow = nextYPos / Constants::TILESIDE; //divide next pixel locations by tileside to see what the next tile is in tilemap
	int tileColumn = nextXPos / Constants::TILESIDE;

	return tileMap->GetWalkableState(tileRow, tileColumn); //ask tilemap to find out if the tile is walkable
} // FindOutIfNextTileIsWalkable

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Updates the search zone the sprites use to detect other sprites. This is based on sprites x and y positions and
// creates an outer rectangle around them.
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void FSMSprite::updateSearchZone()
{
	int xOffset = FrameWidth*Constants::SEARCH_ZONE_WIDTH_NUM_TIMES_SIZE;
	int yOffset = FrameHeight*Constants::SEARCH_ZONE_HEIGHT_NUM_TIMES_SIZE;


	//Uses offset constants to create rectangle
	SearchZone = Rectangle(
		XPos - xOffset,
		YPos - yOffset,
		FrameWidth + (xOffset * 2),
		FrameHeight + (yOffset * 2)
	);
} //end Update Search Zone

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//randomly generates sprites movement speed.
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
void FSMSprite::SetVelocity()
{
	speed = rGen->Next(Constants::MIN_VELOCITY, Constants::MAX_VELOCITY);
	xVel = speed;
	yVel = speed;
} //End set velocty

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Changes direction to a direction that was not the current direction
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void FSMSprite::ChangeDirection()
{
	lastDirection = DirectionState;
	do //Randomly generate new direction state while same as previous one
	{
		DirectionState = rGen->Next(Constants::NDIRECTIONS);

	} while (DirectionState == lastDirection);
} //End change direction

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Calls move method if sprite can walk, if it can't implement bounds aciton
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void FSMSprite::Patrol()
{
	bool canMove = FindOutIfNextTileIsWalkable();

	if (canMove)
	{
		Move();
	}
	else
	{
		ImplementOutOfBoundsAction();
	}
} //End patrol


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Checks current bounds state and performs actions depending on state
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void FSMSprite::ImplementOutOfBoundsAction()
{
	switch (BoundState)
	{
	case EBoundAction::BOUNCE:
		//Switch to opposite direction
		DirectionState = (DirectionState + 2) % Constants::NDIRECTIONS;
		break;
	case EBoundAction::STOP:
		//Stop moving
		xVel = 0;
		yVel = 0;
		break;
	case EBoundAction::DIE: 
		//Die
		IsAlive = false;
		break;	
	case EBoundAction::WANDER:
		//No action but keeping as optio in case it is to be implemented later
		break;
	}
} // End ImplementOutOfBoundsAction

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Use arc-tangent calculation to work out angle from sprite to it's target sprite
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

double FSMSprite::ComputeAngleToTarget(FSMSprite^ player)
{
	double angle;

	int xDelta = player->CollisionBox.X - CollisionBox.X;
	int yDelta = player->CollisionBox.Y- CollisionBox.Y;

	if ((xDelta != 0) && (yDelta != 0))
	{
		// atan2 returns the angle of rotation between two points with vertical distance arg1 and horizontal distance arg2
		angle = Math::Atan2(yDelta, xDelta);	// result is in radians
	}
	else
		angle = 0.0;	// instance and target share an x or y axis location. This works as a heuristic

	return angle;
} //End ComputeAngleToTarget



