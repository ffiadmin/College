/* 
  Authors:  Oliver Spryn
  Course:   COMP 220, Computer Programming II 
  Date:     10 December 2012
  Description:  This class provides a file browser for a user to choose a file to edit. 
*/ 

#include <fstream>
#include <iostream>
#include <windows.h>

#include "Display.h"
#include "FileBrowser.h"

using std::cin;
using std::cout;
using std::endl;
using std::ofstream;

FileBrowser::FileBrowser(string directory) {
	this->directory = directory;

	this->fetch();
}

string FileBrowser::print() {
	for (int i = 0; i < this->info.size(); i++) {
	//Assign ".." to the hot key 0
		if (this->info[0].name == "..") {
			cout << i;

		//Add some spaces to line up the columns
			if (i <= 9) {
				cout << "   ";
			} else if (i <= 99) {
				cout << "  ";
			} else if (i <= 999) {
				cout << " ";
			}
		} else {
			cout << i + 1;

		//Add some spaces to line up the columns
			if (i + 1 <= 9) {
				cout << "   ";
			} else if (i + 1 <= 99) {
				cout << "  ";
			} else if (i + 1 <= 999) {
				cout << " ";
			}
		}

		if (this->info[i].isDirectory) {
			cout << "[DIR] ";
		} else {
			cout << "      ";
		}

		cout << this->info[i].name << endl;
	}

	cout << endl
		 << "Open file or folder by number, or type \"N\" for new file: ";

//Get the file or folder number
	char option[3];
	int numOption;
	cin >> option;

	if (isdigit(option[0])) {
		numOption = atoi(option);
	} else {
		strupr(option);

		if (strcmp(option, "N") == 0) {
			return this->newFile();
		} else {
			Display::coloredText("What was that?", red);
			Sleep(3000);

			this->fetch();
			return this->print();
		}
	}

//Verify that the given file or folder exists
	if (this->info[0].name == ".." && this->info.size() >= numOption && numOption >= 0) {
		if (this->info[numOption].isDirectory) {
			this->directory = this->info[numOption].fullPath;
			this->fetch();
			return this->print();
		} else {
			return this->info[numOption].fullPath;
		}
	} else if (this->info[0].name != ".." && this->info.size() >= numOption - 1 && numOption - 1 >= 0) {
		if (this->info[numOption - 1].isDirectory) {
			this->directory = this->info[numOption - 1].fullPath;
			this->fetch();
			return this->print();
		} else {
			return this->info[numOption - 1].fullPath;
		}
	} else {
		Display::coloredText("This file or folder does not exist!", red);
		Sleep(3000);

		this->fetch();
		return this->print();
	}
}

void FileBrowser::fetch() {
	HANDLE directoryH;
	WIN32_FIND_DATA file;
	vector<FileInfo> info;

	Display::clear();

//Check to see if at least one file exists in the directory
	directoryH = FindFirstFile((this->directory + "\\*.*").c_str(), &file);

	if (directoryH == INVALID_HANDLE_VALUE) {
		this->info.clear();
	} else {
	//Output the data from the file handle into a vector for later usage
		do {
			if (strcmp(file.cFileName, ".") != 0) {
				FileInfo f;
				f.name = file.cFileName;
				f.fullPath = this->directory + "/" + file.cFileName;
				f.isDirectory = static_cast<bool>(file.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY);
				info.push_back(f);
			}
		} while(FindNextFile(directoryH, &file));

		FindClose(directoryH);

		this->info = info;
	}
}

string FileBrowser::newFile() {
	string file;
	Display::clear();

	cout << "Enter the name of the file you would like to create: ";
	cin >> file;

	ofstream fout;
	fout.open(file);
	fout.close();

	return file;
}