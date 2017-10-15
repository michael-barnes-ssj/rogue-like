#include "MenuForm.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void MenuForm(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	RogueLike::MenuForm form;
	Application::Run(%form);
}

