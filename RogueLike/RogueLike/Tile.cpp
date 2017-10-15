#include "Tile.h"

Tile::Tile(String^ fileName, bool startWalkable)
{

	TileBitmap = gcnew Bitmap(fileName); //Uses passed in string to gather grab an image from the correct project folder

	IsWalkable = startWalkable; //Used by sprites to check what tiles are walkable or not

}//End Constructor
