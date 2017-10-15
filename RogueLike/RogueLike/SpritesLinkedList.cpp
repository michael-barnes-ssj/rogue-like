#include "SpritesLinkedList.h"



SpritesLinkedList::SpritesLinkedList(Score^ score)
{
	//Intializing fields
	Head = nullptr;
	tail = nullptr;
	playerScore = score;
}

//Adds a Sprite to the list
void SpritesLinkedList::AddNode(Sprite ^ newNode)
{
	// If the list is empty
	if (Head == nullptr)
	{
		Head = newNode;
		tail = newNode;
	}
	//If adding a new item to the list
	else
	{
		tail->Next = newNode;
		tail = newNode;
	}
}
//Deletes the specified Sprite from the list
void SpritesLinkedList::DeleteOneNode(Sprite ^ nodeToDelete)
{
	Sprite^ nodeWalker = Head; //nodeWalker points at what is stored in head

	if (nodeToDelete == Head) //If nodeWalker is the first sprite, the first sprite becomes what nodeWalker was pointing at
	{
		Head = nodeToDelete->Next;
	}
	else if (Head == nodeToDelete && tail == nodeToDelete)//If nodeWalker is the last sprite
	{
		Head = nullptr;
		tail = nullptr;
	}
	else
	{
		while (nodeWalker->Next != nodeToDelete)
		{
			nodeWalker = nodeWalker->Next;
		}

		if (nodeToDelete->Next == nullptr)
		{
			tail = nodeWalker;
			nodeWalker->Next = nullptr;
		}
		else
		{
			nodeWalker->Next = nodeToDelete->Next;
		}
	}

}

//Deletes all of the Sprites, thats isAlive is false, from the list
void SpritesLinkedList::DeleteAllDeadNodes()
{
	Sprite^ nodeWalker = Head; //nodeWalker points at what is stored in head

							   //Cycles through until it reaches the end of the list
	while (nodeWalker != nullptr)
	{
		if (nodeWalker->IsAlive == false)
		{
			DeleteOneNode(nodeWalker);
			playerScore->CurrentScore += nodeWalker->ScoreValue;
		}

		nodeWalker = nodeWalker->Next;
	}
}

//Moves all the Projectiles in the list ActionState



void SpritesLinkedList::DrawInTheViewport(int viewportWorldX, int viewportWorldY, int viewportWidth, int viewportHeight, array<bool, 2>^ visibleMap)
{
	Sprite^  nodeWalker = Head; //nodeWalker points at what is stored in head

								//Cycles through until it reaches the end of the list
	while (nodeWalker != nullptr)
	{
		if ((nodeWalker->XPos  > viewportWorldX) && (nodeWalker->XPos <  viewportWorldX + viewportWidth) &&
			(nodeWalker->YPos> viewportWorldY) && (nodeWalker->YPos <  viewportWorldY + viewportHeight))
		{
			int spriteViewportLocX = nodeWalker->XPos - viewportWorldX;
			int spriteViewportLocY = nodeWalker->YPos - viewportWorldY;

			int row = (nodeWalker->YPos / Constants::TILESIDE); //use sprites world position to calculate what tile they are on
			int col = (nodeWalker->XPos / Constants::TILESIDE);

			if (visibleMap[row, col]) //ash visible map if that tile is visible
			{
				nodeWalker->Draw(spriteViewportLocX, spriteViewportLocY); //if it is draw it
				nodeWalker->UpdateFrame();
			}
		}
		nodeWalker = nodeWalker->Next; //Sets projectileWalker to point, at what the current item, is pointing at
	}
}
//Counts the amount of Sprites in the list
int SpritesLinkedList::CountNodes()
{
	int count = 0;
	Sprite^ nodeWalker = Head; //nodeWalker points at what is stored in head

							   //Cycles through until it reaches the end of the list
	while (nodeWalker != nullptr)
	{
		count++;
		nodeWalker = nodeWalker->Next; //Sets nodeWalker to point, at what the current item, is pointing at
	}

	return count;
}

