#pragma once


//////////////////////////////////////////////////////////////////////////
//This class is used to hold the feedback messages that the form will use
//when the player activates certain items or picks up some treasure
//////////////////////////////////////////////////////////////////////////

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


ref class FeedBackMessages
{
public:

	//Gets and Sets
	property String^ Message;
	property int MessageTicks;

public:

	//Constuctor
	FeedBackMessages();

	//Methods that can be called globally
	void CountDownMessageTimeout();
};

