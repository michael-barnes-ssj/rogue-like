#include "Minimap.h"
#include "Constants.h"

Minimap::Minimap(Graphics^ startCanvas, TileMap^ startMap, Size^ canvasSize, int halfViewportXOffset, int halfViewportYOffset)
{
	//Intialising fields
	canvas = startCanvas;
	map = startMap;
	mapDrawColStart = halfViewportXOffset / 2;
	mapDrawRowStart = halfViewportYOffset / 2;
	mapDrawXLocation = 4 * (canvasSize->Width / 5) - 20;
	mapDrawYLocation = (canvasSize->Height / 40);
	width = canvasSize->Width / 6;
	height = canvasSize->Height / 4;
	NRows = map->NRows - (2 * mapDrawRowStart);
	NCols = map->NCols - (2 * mapDrawColStart);
	CalculateTileSize(canvasSize);

}//End Constructor


 ///////////////////////////////////////////////////////////////////////////////////////////////
 // Draws the entire dungeon in a smaller form so the player can keep track of their progress
 // of the uncovered map much easier
 ///////////////////////////////////////////////////////////////////////////////////////////////

void Minimap::DrawMiniMap(int xpos, int ypos)
{
	int x; //Actual draw location
	int i; //Actual draw location
	int playerXpos = xpos / Constants::TILESIDE;
	int playerYpos = ypos / Constants::TILESIDE;


	x = mapDrawYLocation;

	for (int r = mapDrawRowStart; r < NRows; r++)
	{
		i = mapDrawXLocation;
		for (int c = mapDrawColStart; c < NCols; c++)
		{
			Bitmap^ mapEntry = map->GetTileBitmap(r, c);

			if (r == playerYpos && c == playerXpos) //Draw player position on the map
			{
				canvas->FillRectangle(Brushes::White, i, x, miniMapTileSizeWidth, miniMapTileSizeHeight);
			}
			else if (!map->VisibleMap[r, c]) //Draw fog covered map
			{
				canvas->DrawRectangle(Pens::SlateGray, i, x, miniMapTileSizeWidth, miniMapTileSizeHeight);
			}
			else //Draw visible map
			{
				canvas->DrawImage(mapEntry, i, x, miniMapTileSizeWidth, miniMapTileSizeHeight);
			}

			i += miniMapTileSizeWidth; //Spacing out each tile
		}
		x += miniMapTileSizeHeight; //Spacing out each tile
	}
}//End DrawMiniMap


 //////////////////////////////////////////////////////////////////////////////////
 //Calculate the size of the tile so that it fit the width and height specifications
 //////////////////////////////////////////////////////////////////////////////////

void Minimap::CalculateTileSize(Size ^ canvasSize)
{
	miniMapTileSizeWidth = width / NCols + 1; //+1 to each so that if the tilesize less that 1 that it still draws
	miniMapTileSizeHeight = height / NRows + 1;

}//End CalculateTileSize
