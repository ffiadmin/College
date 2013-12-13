// File: Editor.cpp 
// Author: Visual Studio
// Date: December 11, 2013 
// Installation: Grove City College 
// Contents:  
//    The Windows Form container class which will display everything
//    to the screen

#pragma once

#include "Context.h"
#include "Document.h"
#include "DisplayManager.h"

namespace editorNS {
	const int  CHAR_HEIGHT    = 18;
	const int  CHAR_WIDTH     = 10;
	const int  CURSOR_HEIGHT  = 18;
	const int  CUR_PAD_LEFT   = 2;
	const int  CUR_PAD_TOP    = 0;
	const char DEFAULT_FILE[] = "Bible.txt";
	const int  HEIGHT         = 535;
	const int  PADDING        = 18;
	const int  TOP_OFFSET     = 30;
	const int  WIDTH          = 655;
}

namespace Editor {

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
		Form1(void) : renderCursor(true)
		{
			InitializeComponent();
			
		//Initilize the content boundaries
			int cols = (editorNS::WIDTH - (editorNS::PADDING * 2)) / editorNS::CHAR_WIDTH;
			int rows = (editorNS::HEIGHT - editorNS::TOP_OFFSET - (editorNS::PADDING * 2)) / editorNS::CURSOR_HEIGHT;

		//Display the doucment with a default size
			d = new Document(editorNS::DEFAULT_FILE);
			dm = new DisplayManager(*d);
			dm->configure(rows, cols);
			dm->fillDisplay();
			print();

		//Cursor
			pen = gcnew Pen(Color::FromArgb(255, 0, 0, 0));
			p1.X = editorNS::CUR_PAD_LEFT;
			p1.Y = editorNS::CUR_PAD_TOP;
			p2.X = editorNS::CUR_PAD_LEFT;
			p2.Y = editorNS::CUR_PAD_TOP + editorNS::CURSOR_HEIGHT;
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

			delete d;
			delete dm;
		}

	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  editToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  finToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  replaceToolStripMenuItem;


	private: Document *d;
	private: DisplayManager *dm;
	private: bool renderCursor;
	private: System::Windows::Forms::Label^ text;
	private: System::Drawing::Pen^ pen;
	private: System::Drawing::Point p1;
	private: System::Drawing::Point p2;
	private: System::Windows::Forms::Timer^  timer1;
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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->finToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->replaceToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->text = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fileToolStripMenuItem,
					this->editToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(639, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->openToolStripMenuItem,
					this->saveToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(114, 22);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::OpenHandler);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(114, 22);
			this->saveToolStripMenuItem->Text = L"Save As";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::saveHandler);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(114, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::exitHandler);
			// 
			// editToolStripMenuItem
			// 
			this->editToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->finToolStripMenuItem,
					this->replaceToolStripMenuItem
			});
			this->editToolStripMenuItem->Name = L"editToolStripMenuItem";
			this->editToolStripMenuItem->Size = System::Drawing::Size(39, 20);
			this->editToolStripMenuItem->Text = L"Edit";
			// 
			// finToolStripMenuItem
			// 
			this->finToolStripMenuItem->Name = L"finToolStripMenuItem";
			this->finToolStripMenuItem->Size = System::Drawing::Size(115, 22);
			this->finToolStripMenuItem->Text = L"Find";
			// 
			// replaceToolStripMenuItem
			// 
			this->replaceToolStripMenuItem->Name = L"replaceToolStripMenuItem";
			this->replaceToolStripMenuItem->Size = System::Drawing::Size(115, 22);
			this->replaceToolStripMenuItem->Text = L"Replace";
			// 
			// text
			// 
			this->text->AutoSize = true;
			this->text->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->text->Location = System::Drawing::Point(13, 36);
			this->text->Name = L"text";
			this->text->Size = System::Drawing::Size(0, 18);
			this->text->TabIndex = 1;
			this->text->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::paintHandler);
			this->text->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::clickHandler);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::cursorHandler);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(639, 497);
			this->Controls->Add(this->text);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Editor of Enlightenment";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::keyDownHandler);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::keyPressHandler);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void OpenHandler(System::Object^ sender, System::EventArgs^ e) {
	//Like, load the file and stuff
		OpenFileDialog^ dlg = gcnew OpenFileDialog();
		dlg->Filter = "Text Files|*.txt|All Files|*.*";
	
		if (dlg->ShowDialog() != System::Windows::Forms::DialogResult::OK) {
			return;
		}

		IntPtr name = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(dlg->FileName);
		const char* file = static_cast<const char*>(name.ToPointer());
		d->load(file);

	//Configure the display manager
		dm->fillDisplay();

	//Like, display the contents ;)
		print();
	}

	private: System::Void saveHandler(System::Object^ sender, System::EventArgs^ e) {
		SaveFileDialog^ dlg = gcnew SaveFileDialog();
		dlg->Filter = "Text Files|*.txt|All Files|*.*";
	
		if (dlg->ShowDialog() != System::Windows::Forms::DialogResult::OK) {
			return;
		}

		IntPtr name = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(dlg->FileName);
		const char* file = static_cast<const char*>(name.ToPointer());
		d->save(file);
	}

	private: System::Void keyDownHandler(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		Change *cp = 0;
		int ci = 0, cj = 0;
		
		switch(e->KeyCode) {
		//Cursor right
			case Keys::Right : 
				cp = new MoveRight(dm);

				break;
		
		//Cursor left
			case Keys::Left : 
				cp = new MoveLeft(dm);
				break;

		//Cursor up
			case Keys::Up : 
				cp = new MoveUp(dm);
				break;

		//Cursor down
			case Keys::Down : 
				cp = new MoveDown(dm);
				break;

		//End of line
			case Keys::End : 
				if (e->Control)
					cp = new EndOfDocument();
				else
					cp = new EndOfLine(dm);

				break;

		//Backspace
			case Keys::Back : 
				cp = new BackSpace(d->getContext(), dm);
				break;

		//Delete
			case Keys::Delete : 
				cp = new Deletion(d->getContext(), 'c', dm); //Why the char?
				break;

		//Undo
			case Keys::Z : 
				if (e->Control) {
					cp = new Undo();
				}

				break;

		//Advanace one word
			case Keys::W : 
				if (e->Control) {
					cp = new NextWord();
				}

				break;

		//Next page
			case Keys::PageDown : 
				cp = new PageForward(dm);

				break;

		//Previous page
			case Keys::PageUp : 
				cp = new PageBackward(dm);
				
				break;
		}
		
		if (cp != 0) {
		//Apply the changes to the text
			d->apply(*cp);
			dm->fillDisplay();
			Refresh();
			print();

		//Apply the changes to the cursor
			dm->getContextCoords(ci, cj);

			p1.X = editorNS::CUR_PAD_LEFT + editorNS::CHAR_WIDTH * cj;
			p1.Y = editorNS::CUR_PAD_TOP + editorNS::CHAR_HEIGHT * ci;
			p2.X = editorNS::CUR_PAD_LEFT + editorNS::CHAR_WIDTH * cj;
			p2.Y = editorNS::CUR_PAD_TOP + editorNS::CURSOR_HEIGHT + editorNS::CHAR_HEIGHT * ci;
		}
		
		delete cp;
	}

	private: System::Void paintHandler(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		if (renderCursor) {
			pen->Color = Color::FromArgb(255, 0, 0, 0);
		} else {
			pen->Color = Color::FromArgb(255, 0, 0, 0);
		}

		e->Graphics->DrawLine(pen, p1, p2);
	}

	private: System::Void print() {
		text->Text = "";

		for (int i = 0; i < dm->size(); ++i) {
			String^ temp = gcnew String(dm->at(i).c_str());
			text->Text += temp;

			if (!temp->EndsWith("\n"))
				text->Text += "\n";
		}
	}

	private: System::Void keyPressHandler(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		Change *cp = 0;
		char val = static_cast<char>(e->KeyChar);

		if (val == 13 || val == 10)
			val = '\n';

		if (isprint(val) || isspace(val)) {
			cp = new Insertion(d->getContext(), val, dm);
		}

		if (cp != 0) {
			d->apply(*cp);
			dm->fillDisplay();
			Refresh();
			print();

		//Apply the changes to the cursor
			int ci = 0, cj = 0;
			dm->getContextCoords(ci, cj);

			p1.X = editorNS::CUR_PAD_LEFT + editorNS::CHAR_WIDTH * cj;
			p1.Y = editorNS::CUR_PAD_TOP + editorNS::CHAR_HEIGHT * ci;
			p2.X = editorNS::CUR_PAD_LEFT + editorNS::CHAR_WIDTH * cj;
			p2.Y = editorNS::CUR_PAD_TOP + editorNS::CURSOR_HEIGHT + editorNS::CHAR_HEIGHT * ci;
		}

		cp = new MoveRight(dm);
	}

	private: System::Void exitHandler(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}

	private : System::Void clickHandler(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		int mouseX = e->X, mouseY = e->Y;
		int xLoc = Math::Floor(mouseX / editorNS::CHAR_WIDTH);
		int yLoc = Math::Floor(mouseY / editorNS::CHAR_HEIGHT);

		if (yLoc < dm->size() && xLoc > dm->at(yLoc).size()) {
			xLoc = dm->at(yLoc).size() - 1;
		}

		p1.X = editorNS::CUR_PAD_LEFT + editorNS::CHAR_WIDTH * xLoc;
		p1.Y = editorNS::CUR_PAD_TOP + editorNS::CHAR_HEIGHT * yLoc;
		p2.X = editorNS::CUR_PAD_LEFT + editorNS::CHAR_WIDTH * xLoc;
		p2.Y = editorNS::CUR_PAD_TOP + editorNS::CURSOR_HEIGHT + editorNS::CHAR_HEIGHT * yLoc;

		Refresh();
	}

	private: System::Void cursorHandler(System::Object^ sender, System::EventArgs^ e) {
		renderCursor = !renderCursor;
	}
};
}

