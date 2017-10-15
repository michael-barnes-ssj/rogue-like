#pragma once
#include "Constants.h"

/*
	This class is the secondary form and the pause menu and instructions menu. It is the first form the user see. It gives instructions to the user about how to play the game, 
	and gives them a story that relates to the game. All of the components are dynamially generated based on screen size. 
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
	/// Summary for InstructionsForm
	/// </summary>
	public ref class MenuForm : public System::Windows::Forms::Form
	{
	private:



	public:
		MenuForm()
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
		~MenuForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  playButton;
	protected:

	private: System::Windows::Forms::PictureBox^  titlePictureBox;
	private: System::Windows::Forms::Button^  exitButton;
	private: System::Windows::Forms::PictureBox^  mainCharcterPictureBox;
	private: System::Windows::Forms::PictureBox^  logManPictureBox;
	private: System::Windows::Forms::Label^  summaryLabel;
	private: System::Windows::Forms::Label^  instructionsLabel;






	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuForm::typeid));
			this->playButton = (gcnew System::Windows::Forms::Button());
			this->titlePictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->mainCharcterPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->logManPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->summaryLabel = (gcnew System::Windows::Forms::Label());
			this->instructionsLabel = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->titlePictureBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mainCharcterPictureBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->logManPictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// playButton
			// 
			this->playButton->Font = (gcnew System::Drawing::Font(L"Rockwell", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->playButton->Location = System::Drawing::Point(823, 253);
			this->playButton->Name = L"playButton";
			this->playButton->Size = System::Drawing::Size(109, 34);
			this->playButton->TabIndex = 0;
			this->playButton->Text = L"Play";
			this->playButton->UseVisualStyleBackColor = true;
			this->playButton->Click += gcnew System::EventHandler(this, &MenuForm::playButton_Click);
			// 
			// titlePictureBox
			// 
			this->titlePictureBox->BackColor = System::Drawing::Color::Transparent;
			this->titlePictureBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"titlePictureBox.Image")));
			this->titlePictureBox->Location = System::Drawing::Point(27, 12);
			this->titlePictureBox->Name = L"titlePictureBox";
			this->titlePictureBox->Size = System::Drawing::Size(566, 214);
			this->titlePictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->titlePictureBox->TabIndex = 1;
			this->titlePictureBox->TabStop = false;
			// 
			// exitButton
			// 
			this->exitButton->Font = (gcnew System::Drawing::Font(L"Rockwell", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exitButton->Location = System::Drawing::Point(634, 228);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(109, 34);
			this->exitButton->TabIndex = 2;
			this->exitButton->Text = L"Exit";
			this->exitButton->UseVisualStyleBackColor = true;
			this->exitButton->Click += gcnew System::EventHandler(this, &MenuForm::exitButton_Click);
			// 
			// mainCharcterPictureBox
			// 
			this->mainCharcterPictureBox->BackColor = System::Drawing::Color::Transparent;
			this->mainCharcterPictureBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"mainCharcterPictureBox.Image")));
			this->mainCharcterPictureBox->Location = System::Drawing::Point(801, 12);
			this->mainCharcterPictureBox->Name = L"mainCharcterPictureBox";
			this->mainCharcterPictureBox->Size = System::Drawing::Size(159, 225);
			this->mainCharcterPictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->mainCharcterPictureBox->TabIndex = 3;
			this->mainCharcterPictureBox->TabStop = false;
			// 
			// logManPictureBox
			// 
			this->logManPictureBox->BackColor = System::Drawing::Color::Transparent;
			this->logManPictureBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"logManPictureBox.Image")));
			this->logManPictureBox->Location = System::Drawing::Point(609, 12);
			this->logManPictureBox->Name = L"logManPictureBox";
			this->logManPictureBox->Size = System::Drawing::Size(165, 198);
			this->logManPictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->logManPictureBox->TabIndex = 4;
			this->logManPictureBox->TabStop = false;
			// 
			// summaryLabel
			// 
			this->summaryLabel->AutoSize = true;
			this->summaryLabel->Font = (gcnew System::Drawing::Font(L"Rockwell", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->summaryLabel->Location = System::Drawing::Point(352, 250);
			this->summaryLabel->Name = L"summaryLabel";
			this->summaryLabel->Size = System::Drawing::Size(100, 23);
			this->summaryLabel->TabIndex = 5;
			this->summaryLabel->Text = L"summary";
			this->summaryLabel->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// instructionsLabel
			// 
			this->instructionsLabel->AutoSize = true;
			this->instructionsLabel->Font = (gcnew System::Drawing::Font(L"Rockwell", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->instructionsLabel->Location = System::Drawing::Point(132, 242);
			this->instructionsLabel->Name = L"instructionsLabel";
			this->instructionsLabel->Size = System::Drawing::Size(169, 32);
			this->instructionsLabel->TabIndex = 6;
			this->instructionsLabel->Text = L"instructions";
			this->instructionsLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// MenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1035, 594);
			this->Controls->Add(this->instructionsLabel);
			this->Controls->Add(this->summaryLabel);
			this->Controls->Add(this->logManPictureBox);
			this->Controls->Add(this->mainCharcterPictureBox);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->titlePictureBox);
			this->Controls->Add(this->playButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MaximizeBox = false;
			this->Name = L"MenuForm";
			this->Text = L"InstructionsForm";
			this->Load += gcnew System::EventHandler(this, &MenuForm::MenuForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->titlePictureBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mainCharcterPictureBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->logManPictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

#pragma endregion

	Timer^ timer; //need access to form1 timer so this form can control timer tick pausing and starting

	///////////////////////////////////////////////////////////////////////////////////////////////
	// Loads the menu form. Brings to front, and sets up positions based on size of screen
	///////////////////////////////////////////////////////////////////////////////////////////////

	private: System::Void MenuForm_Load(System::Object^  sender, System::EventArgs^  e)
	{
		TopMost = true; //Brings this form the the front

		Left = 0;
		Top = 0;

		WindowState = FormWindowState::Maximized;

		int quarter = Constants::QUARTER_VALUE;
		int distanceFromBottom = Constants::DISTANCE_FROM_BOTTOM;

		//Location of everything is generated off size of screen
		titlePictureBox->Width = Width / 2;
		titlePictureBox->Height = Height / quarter; //Height of title is 1/4 of screen
		titlePictureBox->Left = Width / 2 - titlePictureBox->Width / 2;
		titlePictureBox->Top = Top + titlePictureBox->Height / quarter; //distance from top is a quater of the size of the title

		playButton->Left = Width / 2 - playButton->Width / 2;
		exitButton->Left = Width / 2 - exitButton->Width / 2;
		exitButton->Top = Bottom - exitButton->Height*distanceFromBottom; //distance from the bottom is 4 buttons high
		playButton->Top = exitButton->Top - playButton->Height*2;

		//Images are half their width are from the edge of the screen
		mainCharcterPictureBox->Left = Left + mainCharcterPictureBox->Width / 2;
		mainCharcterPictureBox->Top = titlePictureBox->Bottom + mainCharcterPictureBox->Height;
		logManPictureBox->Left = Right - logManPictureBox->Width - logManPictureBox->Width/2;
		logManPictureBox->Top = titlePictureBox->Bottom + logManPictureBox->Height;

		//Creating the setting for the game
		summaryLabel->Text = "You awake inside a forest with no memory of how you got there. You find yourself only with your sword.\nWatch out for wild humans in the forest, they may throw boomorangs at you.\nThere are also infected humans that will try to attack you.\n\nThere are strange tree creatures wandering around, but they are more scared of you than you are of them.\nThere is magic candy lying around that gives you special abilities, and treasure for you to collect.\nYour only chance is to find a portal that will teleport you home.\n\nBut the forest seems endless... Will you ever find a way out?";
		summaryLabel->Width = Width / 2;
		//Writing instructions for the game
		instructionsLabel->Text = "Use WASD keys to move.\n\nPress spacebar to swing your sword.\n";
		instructionsLabel->Width = Width / 2;

		//Postioning summary and instructions based off each other
		summaryLabel->Left = Width / 2 - summaryLabel->Width / 2;
		summaryLabel->Top = Height / 2 - summaryLabel->Height / 2;
		instructionsLabel->Left = Width / 2 - instructionsLabel->Width / 2;
		instructionsLabel->Top = summaryLabel->Bottom + instructionsLabel->Height/2;

	} //End form Load

	/////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Gets a pointer to the form 1 timer. This allows the timer to be stopped and started from this class.
	//////////////////////////////////////////////////////////////////////////////////////////////////////////

	public: System::Void AccessTimer(Timer^ startTimer) 
	{
		timer = startTimer;
	} //End Access timer

	///////////////////////////////////////////////////////////////////////////////////////////////
	// resumes and starts the game. hides this form and enables timer.
	///////////////////////////////////////////////////////////////////////////////////////////////

	private: System::Void playButton_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		Hide(); //hides form so can't be opened unless pause button is clicked
		timer->Enabled = true;
		playButton->Text = "Resume"; //Starts off as play. When they revisit it becomes resume
	}

	///////////////////////////////////////////////////////////////////////////////////////////////
	// Exits the whole application
	///////////////////////////////////////////////////////////////////////////////////////////////

	private: System::Void exitButton_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		Application::Exit();
	} //End exitButton_Click

	};
}
