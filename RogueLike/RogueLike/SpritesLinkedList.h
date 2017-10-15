#pragma once

//////////////////////////////////////////////////////////////////////////
// This class is used to hold multiple instances of object type sprite.
// It contains methods that apply to the sprite object.
// Each sprite is given a pointer to the next sprite that was added except
// the last sprite.
// sprites can also be deleted from the list by removing its pointer to another 
// sprite and another sprites pointer to it
//////////////////////////////////////////////////////////////////////////

#include "Sprite.h"
#include "Score.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class SpritesLinkedList
{
private:

	//Fields
	Sprite^ tail;
	Score^ playerScore;

public:

	property Sprite^ Head;

	//Constructor
	SpritesLinkedList(Score^ score);

	//Methods that can be called globally
	void AddNode(Sprite^ newNode);
	void DeleteOneNode(Sprite^ nodeToDelete);
	void DeleteAllDeadNodes();
	void DrawInTheViewport(int viewportWorldX, int viewportWorldY, int viewportWidth, int viewportHeight, array<bool, 2>^ visibleMap);
	int CountNodes();
};