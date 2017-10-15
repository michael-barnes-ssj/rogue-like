#pragma once

#include"GameManager.h"
#include "MenuForm.h"

/* Program Name: Endless Forest
*
* Project File Name: RogueLike
*
* Author: Mike Barnes and Dean Knudson
*
* Date: 15/10/2017
*
* Language: C++
*
* Platform: Microsoft Visual Studios 2015
*
* Purpose:    To a rougue like style game in C++*             
*
* Decription: The user controls the main character who is centered in the middle of the screen. A random dungeon is generated. There
*			  are corridors connecting rooms together. The player has to fight their way though the dunegeon, destroying the many
*			  enemies and collecting treasure. Each enemy destroyed or treasure picked up increases the players score. There are 
*			  other items that effect game play that the player can pick up. The goal for the player is to find the portal in each 
*			  dungeon, this will transport you to a new random dungeon. The enemies get strong each level, and the player has to
*			  survive as long as they can.
*
* Known Bugs: None.
*
* All images in this game were obtained from https://opengameart.org/ with permission to use.
* 
*/

/*
	This class is the main form. It contains everything relating to the user interface while playing the game. This is the scoring system,
	player health, feedback, key input, and buttons for New Game, Pause, and Exit. It is the first form the user will see while playing. It gives
	instructions to the user about how to play the game, and gives them a story that relates to the game. All of the components are
	dynamially generated based on screen size. It has a timer that runs the game manager, and it creates the graphics and random number instances
	that and passess them to the other classes to use.
*/



namespace RogueLike {

#pragma region Default Code




	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Panel^  mainCanvasPanel;
	private: System::Windows::Forms::Label^  ScoreLabel;





	private: System::Windows::Forms::PictureBox^  GameOverPictureBox;
	private: System::Windows::Forms::Panel^  maxHealthPanel;
	private: System::Windows::Forms::Panel^  healthPanel;
	private: System::Windows::Forms::PictureBox^  bannerPictureBox;
	private: System::Windows::Forms::Label^  HealthLabel;
	private: System::Windows::Forms::Label^  FeedbackLabel;


	private: System::Windows::Forms::Button^  newGamebtn;
	private: System::Windows::Forms::Button^  exitBtn;
	private: System::Windows::Forms::Button^  pauseBtn;






	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->mainCanvasPanel = (gcnew System::Windows::Forms::Panel());
			this->ScoreLabel = (gcnew System::Windows::Forms::Label());
			this->GameOverPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->maxHealthPanel = (gcnew System::Windows::Forms::Panel());
			this->healthPanel = (gcnew System::Windows::Forms::Panel());
			this->bannerPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->HealthLabel = (gcnew System::Windows::Forms::Label());
			this->FeedbackLabel = (gcnew System::Windows::Forms::Label());
			this->exitBtn = (gcnew System::Windows::Forms::Button());
			this->newGamebtn = (gcnew System::Windows::Forms::Button());
			this->pauseBtn = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GameOverPictureBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bannerPictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Interval = 50;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// mainCanvasPanel
			// 
			this->mainCanvasPanel->BackColor = System::Drawing::Color::Silver;
			this->mainCanvasPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mainCanvasPanel->Location = System::Drawing::Point(12, 12);
			this->mainCanvasPanel->Name = L"mainCanvasPanel";
			this->mainCanvasPanel->Size = System::Drawing::Size(60, 51);
			this->mainCanvasPanel->TabIndex = 0;
			// 
			// ScoreLabel
			// 
			this->ScoreLabel->AutoSize = true;
			this->ScoreLabel->Font = (gcnew System::Drawing::Font(L"Rockwell", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ScoreLabel->Location = System::Drawing::Point(811, 12);
			this->ScoreLabel->Name = L"ScoreLabel";
			this->ScoreLabel->Size = System::Drawing::Size(274, 59);
			this->ScoreLabel->TabIndex = 1;
			this->ScoreLabel->Text = L"scorelabel";
			// 
			// GameOverPictureBox
			// 
			this->GameOverPictureBox->BackColor = System::Drawing::Color::Black;
			this->GameOverPictureBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"GameOverPictureBox.Image")));
			this->GameOverPictureBox->Location = System::Drawing::Point(624, 302);
			this->GameOverPictureBox->Name = L"GameOverPictureBox";
			this->GameOverPictureBox->Size = System::Drawing::Size(632, 153);
			this->GameOverPictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->GameOverPictureBox->TabIndex = 6;
			this->GameOverPictureBox->TabStop = false;
			this->GameOverPictureBox->Visible = false;
			// 
			// maxHealthPanel
			// 
			this->maxHealthPanel->Location = System::Drawing::Point(852, 470);
			this->maxHealthPanel->Name = L"maxHealthPanel";
			this->maxHealthPanel->Size = System::Drawing::Size(200, 100);
			this->maxHealthPanel->TabIndex = 3;
			// 
			// healthPanel
			// 
			this->healthPanel->Location = System::Drawing::Point(428, 210);
			this->healthPanel->Name = L"healthPanel";
			this->healthPanel->Size = System::Drawing::Size(200, 100);
			this->healthPanel->TabIndex = 7;
			// 
			// bannerPictureBox
			// 
			this->bannerPictureBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bannerPictureBox.Image")));
			this->bannerPictureBox->Location = System::Drawing::Point(121, 171);
			this->bannerPictureBox->Name = L"bannerPictureBox";
			this->bannerPictureBox->Size = System::Drawing::Size(249, 154);
			this->bannerPictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->bannerPictureBox->TabIndex = 8;
			this->bannerPictureBox->TabStop = false;
			// 
			// HealthLabel
			// 
			this->HealthLabel->AutoSize = true;
			this->HealthLabel->BackColor = System::Drawing::Color::Transparent;
			this->HealthLabel->Font = (gcnew System::Drawing::Font(L"Rockwell", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->HealthLabel->Location = System::Drawing::Point(438, 109);
			this->HealthLabel->Name = L"HealthLabel";
			this->HealthLabel->Size = System::Drawing::Size(227, 46);
			this->HealthLabel->TabIndex = 9;
			this->HealthLabel->Text = L"healthlabel";
			// 
			// FeedbackLabel
			// 
			this->FeedbackLabel->AutoSize = true;
			this->FeedbackLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FeedbackLabel->Location = System::Drawing::Point(244, 83);
			this->FeedbackLabel->Name = L"FeedbackLabel";
			this->FeedbackLabel->Size = System::Drawing::Size(146, 74);
			this->FeedbackLabel->TabIndex = 10;
			this->FeedbackLabel->Text = L"feedback\r\nLabel\r\n";
			this->FeedbackLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// exitBtn
			// 
			this->exitBtn->Font = (gcnew System::Drawing::Font(L"Rockwell", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exitBtn->Location = System::Drawing::Point(1364, 24);
			this->exitBtn->Name = L"exitBtn";
			this->exitBtn->Size = System::Drawing::Size(110, 47);
			this->exitBtn->TabIndex = 1;
			this->exitBtn->Text = L"Exit";
			this->exitBtn->UseVisualStyleBackColor = true;
			this->exitBtn->Click += gcnew System::EventHandler(this, &Form1::exitBtn_Click);
			// 
			// newGamebtn
			// 
			this->newGamebtn->Font = (gcnew System::Drawing::Font(L"Rockwell", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->newGamebtn->Location = System::Drawing::Point(1132, 24);
			this->newGamebtn->Name = L"newGamebtn";
			this->newGamebtn->Size = System::Drawing::Size(110, 47);
			this->newGamebtn->TabIndex = 0;
			this->newGamebtn->Text = L"New Game";
			this->newGamebtn->UseVisualStyleBackColor = true;
			this->newGamebtn->Click += gcnew System::EventHandler(this, &Form1::newGamebtn_Click);
			// 
			// pauseBtn
			// 
			this->pauseBtn->Font = (gcnew System::Drawing::Font(L"Rockwell", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pauseBtn->Location = System::Drawing::Point(1248, 24);
			this->pauseBtn->Name = L"pauseBtn";
			this->pauseBtn->Size = System::Drawing::Size(110, 47);
			this->pauseBtn->TabIndex = 11;
			this->pauseBtn->Text = L"Pause";
			this->pauseBtn->UseVisualStyleBackColor = true;
			this->pauseBtn->Click += gcnew System::EventHandler(this, &Form1::pauseBtn_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(1692, 1062);
			this->Controls->Add(this->pauseBtn);
			this->Controls->Add(this->newGamebtn);
			this->Controls->Add(this->exitBtn);
			this->Controls->Add(this->FeedbackLabel);
			this->Controls->Add(this->HealthLabel);
			this->Controls->Add(this->bannerPictureBox);
			this->Controls->Add(this->healthPanel);
			this->Controls->Add(this->maxHealthPanel);
			this->Controls->Add(this->GameOverPictureBox);
			this->Controls->Add(this->ScoreLabel);
			this->Controls->Add(this->mainCanvasPanel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Form1";
			this->Text = L"EndlessForest";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GameOverPictureBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bannerPictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


#pragma endregion

	//////////// Declaring variables ///////////////

	private:
		
		Graphics^ canvas; 
		Graphics^ bufferCanvas; 
		Bitmap^ backgroundBuffer;
		Bitmap^ miniMapbackgroundBuffer;
		GameManager^ gameManager;
		Random^ rGen;
		MenuForm^ menu = gcnew MenuForm();

	///////////////////////////////////////////////////////////////////////////////////////////////
	// Initialises Global Variables
	///////////////////////////////////////////////////////////////////////////////////////////////

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
	{	
		Left = 0; //Setting form to full screen
		Top = 0;	
		WindowState = FormWindowState::Maximized;

		setUpComponents(); //Sets up component positions based on each other

		//Initialising variables to run game
		rGen = gcnew Random();
		canvas = mainCanvasPanel->CreateGraphics();	
		backgroundBuffer = gcnew Bitmap(mainCanvasPanel->Width, mainCanvasPanel->Height);
		bufferCanvas = Graphics::FromImage(backgroundBuffer);
		gameManager = gcnew GameManager(bufferCanvas, rGen, mainCanvasPanel->Size);

		//Sets message to default message
		FeedbackLabel->Text = gameManager->MessageController->Message; 

		//Shows menu form and gives it timer
		menu->Show();
		menu->AccessTimer(timer1);

		//Stops buttons from stopping key input
		KeyPreview = true;

	} // end Form1_Load

	///////////////////////////////////////////////////////////////////////////////////////////////
	// Handles user key input for directional control
	///////////////////////////////////////////////////////////////////////////////////////////////

	private: System::Void Form1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
	{
		gameManager->KeyDown(e);
		//Stops beeping noises from key press
		e->SuppressKeyPress = true;

	} //end Form1_KeyDown

	///////////////////////////////////////////////////////////////////////////////////////////////
	// Handles user key input for stopping movement
	///////////////////////////////////////////////////////////////////////////////////////////////

	private: System::Void Form1_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		gameManager->KeyUp(e);
	} //end Form1_KeyUp

	///////////////////////////////////////////////////////////////////////////////////////////////
	// Sets up components positions based on screen size
	///////////////////////////////////////////////////////////////////////////////////////////////

	private: System::Void setUpComponents()
	{
		bannerPictureBox->Width = Constants::BANNER_WIDTH;
		bannerPictureBox->Left = (Width / 2) - bannerPictureBox->Width / 2;
		bannerPictureBox->Top = 0;
		mainCanvasPanel->Left = Constants::GAME_PANEL_LEFT_DISTANCE;
		mainCanvasPanel->Top = bannerPictureBox->Height;

		int distanceFromRight = Constants::GAME_PANEL_LEFT_DISTANCE * 2; //calcualtes distance from right by doubling distance from left
		mainCanvasPanel->Width = Width - distanceFromRight;

		//Calculates panel height based off height of form
		mainCanvasPanel->Height = Height * Constants::PANEL_HEIGHT_PERECENT;

		//Each button is based off other buttons position
		exitBtn->Left = mainCanvasPanel->Right - exitBtn->Width;

		//Buttons is half it's width from button to it's right
		int distanceBetweenButtons = Constants::DISTANCE_BETWEEN_GAME_BUTTONS;
		int pauseButtonPos = exitBtn->Left - pauseBtn->Width - (pauseBtn->Width / distanceBetweenButtons);
		pauseBtn->Left = pauseButtonPos;

		//Buttons is half it's width from button to it's right
		int newGameButtonPos = pauseBtn->Left - newGamebtn->Width - (newGamebtn->Width / distanceBetweenButtons);
		newGamebtn->Left = newGameButtonPos;

		exitBtn->Top = (bannerPictureBox->Height / 2) - (exitBtn->Height / 2);
		pauseBtn->Top = exitBtn->Top;
		newGamebtn->Top = exitBtn->Top;

		//Health bars are all based off each other
		maxHealthPanel->Height = HealthLabel->Height;
		maxHealthPanel->Left = mainCanvasPanel->Left;

		//calculate the centre point between bottom on main panel and bottom of screen
		int middleOfBottomGap = mainCanvasPanel->Bottom + ((Height - mainCanvasPanel->Bottom) / 2);

		//calculate middle point minus half the hight of the health. Puts it perfectly in centre
		int healthPanelPosition = middleOfBottomGap - maxHealthPanel->Height / 2;

		//calculate middle point minus half the hight of the label. Puts it perfectly in centre
		int feedBackLabelPosition = middleOfBottomGap - FeedbackLabel->Height / 2;
		FeedbackLabel->Top = feedBackLabelPosition;

		maxHealthPanel->Top = healthPanelPosition;
		healthPanel->Left = maxHealthPanel->Left;
		healthPanel->Top = maxHealthPanel->Top;
		healthPanel->Height = maxHealthPanel->Height;

		ScoreLabel->Left = mainCanvasPanel->Left;
		ScoreLabel->Top = (bannerPictureBox->Height / 2) - (ScoreLabel->Height / 2);
		HealthLabel->Left = maxHealthPanel->Left + maxHealthPanel->Width;
		HealthLabel->Top = maxHealthPanel->Top;

		//Setting health bar colours
		healthPanel->BackColor = Color::LightGreen;
		maxHealthPanel->BackColor = Color::Red;

		GameOverPictureBox->Left = (mainCanvasPanel->Width / 2) - (GameOverPictureBox->Width / 2);
		GameOverPictureBox->Top = (mainCanvasPanel->Height / 2) - (GameOverPictureBox->Height / 2);
	}

	///////////////////////////////////////////////////////////////////////////////////////////////
	// At each timer tick the background is painted transparent.
	// Game Manager run game cycle is called.
	// Finally, the offscreen buffer bitmap is drawn to the Form's canvas.
	// Update components based on game data
	// If player dies, do end of game sequence
	///////////////////////////////////////////////////////////////////////////////////////////////

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
	{		
		bufferCanvas->FillRectangle(Brushes::Transparent, 0, 0, Width, Height); //Creating a buffered image of the background image
		gameManager->RunGameCycle();
		canvas->DrawImage(backgroundBuffer, 0, 0);//Draw buffered image

		//Update components based on game data
		maxHealthPanel->Width = gameManager->player->MaxHealth;
		healthPanel->Width = gameManager->player->Health;
		HealthLabel->Left = maxHealthPanel->Left + maxHealthPanel->Width;
		FeedbackLabel->Left = mainCanvasPanel->Right - FeedbackLabel->Width;
		ScoreLabel->Text = "Score: " + gameManager->ScoreController->CurrentScore.ToString();
		HealthLabel->Text = gameManager->player->Health.ToString() + "/" + gameManager->player->MaxHealth.ToString();
		FeedbackLabel->Text = gameManager->MessageController->Message;

		if (gameManager->player->Health <= 0) //When the player is dead, the game is over. Display game over image
		{
			GameOverPictureBox->Visible = true;
			pauseBtn->Enabled = false;
			timer1->Enabled = false;
		}

	} //End timer1_Tick

	///////////////////////////////////////////////////////////////////////////////////////////////
	// Resets everything for new game
	///////////////////////////////////////////////////////////////////////////////////////////////

	private: System::Void newGamebtn_Click(System::Object^  sender, System::EventArgs^  e)
	{
		gameManager->StartNewGame();
		pauseBtn->Enabled = true;
		GameOverPictureBox->Visible = false;
		timer1->Enabled= true;
		
	} //End newGamebtn_Click

	///////////////////////////////////////////////////////////////////////////////////////////////
	// Exits application
	///////////////////////////////////////////////////////////////////////////////////////////////

	private: System::Void exitBtn_Click(System::Object^  sender, System::EventArgs^  e)
	{
		Application::Exit();
	} //End exitBtn_Click

	///////////////////////////////////////////////////////////////////////////////////////////////
	// Pauses timer and shows menu form
	///////////////////////////////////////////////////////////////////////////////////////////////

	private: System::Void pauseBtn_Click(System::Object^  sender, System::EventArgs^  e)
	{
		timer1->Enabled = false;
		menu->Show();
	} //End pauseBtn_Click
};
}
