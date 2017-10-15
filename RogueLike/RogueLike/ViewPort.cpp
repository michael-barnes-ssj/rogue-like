#include "ViewPort.h"


ViewPort::ViewPort(Size^ canvasSize, TileMap ^ startBackgroundMap, Graphics ^ startCanvas)
{
	backgroundMap = startBackgroundMap;
	canvas = startCanvas;

	tileSide = Constants::TILESIDE; 

	ViewportTilesHigh = canvasSize->Height / tileSide+1; //+1, incase the display leaves a remainder, doesnt allow the edges of the screen to be blurry
	ViewportTilesWide = canvasSize->Width / tileSide+1;

	ViewPortPixelWidth = ViewportTilesWide*tileSide;
	ViewPortPixelHeight = ViewportTilesHigh*tileSide;	
}

///////////////////////////////////////////////////////////////////////////////////////////////
// Draws the tiles to the screen if they have been revealed by the player
///////////////////////////////////////////////////////////////////////////////////////////////

void ViewPort::ViewportDraw()
{
	int viewPortTileX = ViewportWorldX / tileSide; //converts pixel location to row location. Where viewports pixel location divided by tileside gets which tile it is
	int viewPortTileY = ViewportWorldY / tileSide;

	int viewPortOffSetX = ViewportWorldX % tileSide; //finds the offset so it can draw half of a tile
	int viewPortOffSetY = ViewportWorldY % tileSide;

	for (int r = viewPortTileY; r < viewPortTileY + Constants::FOG_HIGH; r++) //Makes the fog of war view area 
	{
		for (int c = viewPortTileX; c < viewPortTileX + Constants::FOG_WIDE; c++)
		{
			int fogRow = (r + (ViewportTilesHigh / 2)) - Constants::FOG_OFFSET_ROW; //starts 5 back from centre of screen
			int fogCol = (c + (ViewportTilesWide / 2)) - Constants::FOG_OFFSET_COL;

			backgroundMap->VisibleMap[fogRow, fogCol] = true; //sets value to true
		}
	}

	for (int r = viewPortTileY; r <= (viewPortTileY + ViewportTilesHigh); r++) //starting at the first tile in viewport, and going to the last tile in viewport. Iterate through each tile.
	{
		for (int c = viewPortTileX; c <= (viewPortTileX + ViewportTilesWide); c++)
		{
			int screenY = ((r - viewPortTileY) * tileSide) - viewPortOffSetY; //pixel location of being drawn in viewport
			int screenX = ((c - viewPortTileX) * tileSide) - viewPortOffSetX;

			Bitmap^ tileImage = backgroundMap->GetTileBitmap(r, c);

			Rectangle rec = Rectangle(screenX, screenY, tileSide, tileSide);

			if (backgroundMap->VisibleMap[r, c]) //only draw if visible in fow
			{
				canvas->DrawImage(tileImage, rec);
			}
			else //if not visible then draw black rectangle
			{
				canvas->FillRectangle(Brushes::Black, rec);
			}

			//canvas->DrawRectangle(Pens::Blue, rec);
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Centres the ViewPort around the middle of the main sprite
///////////////////////////////////////////////////////////////////////////////////////////////

void ViewPort::CentreViewPortAroundSprite(PlayerSprite^ sprite)
{
	ViewportWorldX = sprite->XPos - (ViewPortPixelWidth / 2);  //Takes the sprites position and centres itself around it
	ViewportWorldY = sprite->YPos - (ViewPortPixelHeight / 2); 
}
