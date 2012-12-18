/* 
  Authors:  Dorian P. Yeager
  Course:   COMP 220, Computer Programming II 
  Date:     10 December 2012
  Description:  This class contains instructions to display file content the console. 
*/ 

#include "DisplayManager.h"
#include <Windows.h>

void DisplayManager::displayCurrentLine(ostream &out) {
	Context oldContext = doc.getContext();
    doc.goTo(doc.lineBegin());
    while (!doc.atEnd() && oldContext != doc.getContext()) {
        cout << *doc;
        ++doc;
    }
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo; 
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hStdout, &csbiInfo);
    WORD wOldColorAttrs = csbiInfo.wAttributes; 
    SetConsoleTextAttribute(hStdout,
        BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    if (*doc == '\n')
        cout << ' ';
    else cout << *doc;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),wOldColorAttrs);
    if (*doc != '\n') {
        ++doc;
        while (!doc.atEnd() && *doc != '\n') {
            cout << *doc;
            ++doc;
        }
        if (*doc != '\n') cout << *doc;
    }
    doc.goTo(oldContext);
}

void DisplayManager::displayNeighborhood(ostream &out) {
    Context oldContext = doc.getContext();
    doc.moveUp(radius);
    while (!doc.inSameLine(doc.getContext(),oldContext)) {
        cout << *doc;
        ++doc;
    }
    doc.goTo(oldContext);
    displayCurrentLine(out);
	oldContext = doc.getContext();
    doc.goTo(doc.lineEnd());
    for (int i=0; i<radius && !doc.atEnd(); ++i) {
        doc.moveDown();
        out << endl;
        doc.goTo(doc.lineBegin());
        while (*doc != '\n') {
            out << *doc;
            ++doc;
        }
    }
    doc.goTo(oldContext);
}

