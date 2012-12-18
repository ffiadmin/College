/* 
  Authors:  Dorian P. Yeager
  Course:   COMP 220, Computer Programming II 
  Date:     10 December 2012
  Description:  This class contains the documement and applies direct changes to its content. 
*/ 

#include "Document.h"
#include <fstream>
using std::swap;
using std::ifstream;
using std::ofstream;

Document::Document(const char *fileName): fileName(fileName) {
	ifstream fin(fileName);
	char ch;
	fin.get(ch);
	while (!fin.eof()) {
		text += ch;
		fin.get(ch);
	}
	currentContext = 0;
	fin.close();
}

void Document::save(const char *fileName) {
	if (strlen(fileName) == 0) fileName = this->fileName;
	ofstream fout(fileName);
	if (!fout.fail()) {
		Context oldContext = getContext();
		goTo(begin());
		while (!atEnd()) {
			fout << **this;
			++(*this);
		}
		goTo(oldContext);
		this->fileName = fileName;
	}
}

void Document::apply(Change &c) {
	c.apply(*this);
	Change *reverse = c.reverse();
	if (reverse != 0) history.push(reverse);
}

void Document::moveDown(int lines) {
	Document &doc = *this;
	int offsetInThisLine = doc.currentLineOffset();
	for (int i=0; i<lines; ++i) {
		while (*doc != '\n' && !doc.atEnd()) ++doc;
		if (doc.atEnd()) {
			doc.text = doc.text + '\n';
			if (*doc != '\n') {
				doc.text = doc.text + '\n';
				++doc;
			}
		}
		++doc;
	}
	while (!doc.atEnd() && 
		   *doc != '\n' && 
		   doc.currentLineOffset() != offsetInThisLine)
	    ++doc;
}

void Document::moveUp(int lines) {
	int offsetInThisLine = currentLineOffset();
	for (int i=0; i<lines; ++i)
		if (!atBeginning())
			do {
				--(*this);
			} while (!atBeginning() && (**this) != '\n');
	while (currentLineOffset() > offsetInThisLine) --(*this);
}

void Document::insert(char ch) {
	text = text.substr(0,currentContext.offset) + ch + 
		   text.substr(currentContext.offset);
	currentContext.offset++;
}

char Document::remove() {
	char rv = text[currentContext.offset];
	text = text.substr(0,currentContext.offset) + text.substr(currentContext.offset+1);
	if ((int)text.length() <= currentContext.offset) currentContext.offset--;
	return rv;
}

Context Document::getContext() {
	return currentContext;
}

void Document::undo() {
	if (!history.empty()) {
		Change * undoer = history.top();
		history.pop();
		undoer->apply(*this);
		undoer->adjustContextAfterUndo(*this);
		delete undoer;
	}
}

char & Document::operator*() {
	return text[currentContext.offset];
}

void Document::operator++() {
	currentContext.offset++;
	if (text.length() == currentContext.offset)
		text = text + "\n";
}

void Document::operator--() {
	currentContext.offset--;
	if (currentContext.offset < 0) currentContext.offset = 0;
}

int Document::currentLineOffset() {
	int startOfThisLine = currentContext.offset;
	while (startOfThisLine != 0 && text[startOfThisLine-1] != '\n')
		--startOfThisLine;
	return currentContext.offset - startOfThisLine;
}

void Document::goTo(Context context) {
	currentContext = context;
	if (currentContext.offset < 0) currentContext.offset = 0;
	if (currentContext.offset >= (int)text.length()) 
		currentContext.offset = text.length()-1;
}

Context Document::begin() {
	return Context();
}

Context Document::end() {
	return Context(text.length()-1);
}

Context Document::lineBegin() {
	if (atBeginning()) return getContext();
	else {
		Context oldContext = getContext();
		Context rv;
		Document &doc = *this;
		if (*doc == '\n') --doc;
		while (!doc.atBeginning() && *doc != '\n') --doc;
		if (*doc == '\n') ++doc;
		rv = getContext();
		goTo(oldContext);
		return rv;
	}
}

Context Document::lineEnd() {
	Context oldContext = getContext();
	Context rv;
	Document &doc = *this;
	while (!doc.atEnd() && *doc != '\n') ++doc;
	rv = getContext();
	goTo(oldContext);
	return rv;
}

bool Document::inSameLine(Context c1, Context c2) {
	if (c1 > c2) swap(c1,c2);
	while (c1 < c2) {
		if (text[c1.offset] == '\n') return false;
		++c1.offset;
	}
	return true;
}
