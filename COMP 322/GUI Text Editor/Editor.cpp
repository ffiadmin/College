// File: Editor.cpp 
// Author: Dorian P. Yeager
// Date: December 11, 2013 
// Installation: Grove City College 
// Contents:  
//    The main function which drives the contents//    of the text editor

#include "stdafx.h"
#include "Form1.h"

using namespace Editor;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew Form1());
	return 0;
}
