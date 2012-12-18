/* 
  Authors:  Dorian P. Yeager and Oliver Spryn
  Course:   COMP 220, Computer Programming II 
  Date:     10 December 2012
  Description:  This class contains the editor and is used to provide interaction between the user and document. 
*/ 

#include <conio.h>
#include "Display.h"
#include "Editor.h"
#include <fstream>
#include <Windows.h>

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x; 
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),
                           coord);
}

Editor::Editor(Document *doc)
        : doc(doc), buffer("") {
    baseX = DEF_BASEX;
    baseY = DEF_BASEY;
	dispMan = new DisplayManager(*doc);

	this->changes = 0;
}
    
Editor::~Editor() {
	delete dispMan;
}

Change * Editor::carveInsert() {
    char insChar = buffer[0];
    buffer = buffer.substr(1);
    Context context = doc->getContext();
    return new Insertion(context,insChar);
}

Change * Editor::getChange(istream &in) {
    if (buffer != "") {
        return carveInsert();
    }
    else {
        if (in == cin) {
            gotoxy(baseX,baseY);
            cout << ": ";
        }
        in.sync();
        string token;
        in >> token;
        for (int i=0; i<(int)token.length(); ++i) token[i] = toupper(token[i]);
        if (token == "I") {
            char space = in.get();
            if (space != ' ') return 0;
            getline(in,buffer);
            if (buffer == "") return 0;
            else {
				this->changes++;
				return carveInsert();
			}
        }
        else if (token == "X") {
            Context context = doc->getContext();
			this->changes++;
            return new Deletion(context);
        }
        else if (token == "N") {
			if (this->changes >= 0) this->changes--;
			return new Undo();
		}
        else if (token == "F") 
            return new MoveRight();
        else if (token == "B") return new MoveLeft();
        else if (token == "L") return new MoveDown();
        else if (token == "W") return new Word();
		else if (token == "-W") return new BackOneWord();
		else if (token == "-L") return new MoveUp();
		else if (token == "NL") {
			this->changes++;
			return new NewLine();
		}
		else if (token == "DL") {
			this->changes++;
			return new DeleteLine();
		}
		else if (token == "DW") {
			this->changes++;
			return new DeleteWord();
		}
		else if (token == "BOL") return new BeginningOfLine();
        else if (token == "EOL") 
            return new EndOfLine();
		else if (token == "BOF")
			return new BeginningOfFile();
		else if (token == "EOF")
			return new EndOfFile();
        else if (token == "SAVE") {
            while (in.peek() != '\n' && isspace(in.peek())) in.ignore();
            static string lineRemainder;
            getline(in,lineRemainder);
			this->changes = 0;
            return new Save(lineRemainder.c_str());
		}
        else if (token == "EXIT") {
			if (this->changes != 0) {
				char input[1];

				Display::coloredText("This document has unsaved changes. Save them now? (y/n) ", red);
				cin >> input;
				strupr(input);

				if (strcmp(input, "Y") == 0) {
					return new ESave();
				}
			}

			return new Exit();
		}
		else if (token == "HELP") {
			Display::clear();

			ifstream fin;
			fin.open("help.txt");

			if (fin.fail()) {
				Display::coloredText("Help cannot be retrieved. What have you done???", red);
				Sleep(3000);

				return new NontrivialChange();
			}

			char next;

			while(fin.get(next) && !fin.eof()) {
				cout << next;
			}

			cout << endl
				 << "Press any key to return to the document";

			getch();
			fin.close();

			return new NontrivialChange();
		}
		else {
			Display::coloredText("Try again bucko", red);
			Sleep(3000);

			return new NontrivialChange();
		}
    }
}

void Editor::edit() {
    system("cls");
    dispMan->displayNeighborhood(cout);
    Change * change = getChange(cin);
    while (change == 0 || !change->isExit()) {
        if (change != 0) doc->apply(*change);
        if (buffer.length() == 0) {
			// If buffer is not empty, then multiple characters are being
			// inserted.  In this case, delay painting the screeen until 
			// all changes have been applied.
            system("cls");
            dispMan->displayNeighborhood(cout);
        }
        delete change;
        change = getChange(cin);
    }
    delete change;
}
