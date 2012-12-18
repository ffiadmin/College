/* 
  Authors:  Dorian P. Yeager and Oliver Spryn
  Course:   COMP 220, Computer Programming II 
  Date:     10 December 2012
  Description:  This file manages all of the changes to the document. 
*/ 

#include "Document.h"
#include <fstream>
using std::ifstream;

Change * Insertion::reverse() {
	return new Deletion(context);
}

void Insertion::apply(Document &d) {
	if (vch.size() > 0) {
		d.goTo(context);

		for (int i = 0; i < vch.size(); i++) {
			d.insert(vch[i]);
		}
	} else {
		d.goTo(context);
		d.insert(ch);
	}
}

void Insertion::adjustContextAfterUndo(Document &d) {
	--d;
}

void Deletion::apply(Document &d) {
	d.goTo(context);
	ch = d.remove();
}

Change * Deletion::reverse() {
	return new Insertion(context,ch);
}

void MoveLeft::apply(Document &d) {
	--d;
}

void MoveRight::apply(Document &d) {
	++d;
}

void MoveDown::apply(Document &d) {
	d.moveDown();
}

void MoveUp::apply(Document &d) {
	d.moveUp();
}

void BeginningOfLine::apply(Document &d) {
	d.goTo(d.lineBegin());
}

void EndOfLine::apply(Document &d) {
	while(!d.atEnd() && *d != '\n') ++d;
}

void BeginningOfFile::apply(Document &d) {
	d.goTo(d.begin());
}

void EndOfFile::apply(Document &d) {
	d.goTo(d.end());
}

void Undo::apply(Document &d) {
	d.undo();
}

void Word::apply(Document &d) {
	Context oldContext = d.getContext();
	while(!d.atEnd() && !isspace(*d)) ++d;
	while(!d.atEnd() && isspace(*d)) ++d;
	if (d.atEnd() && !isspace(*d)) d.goTo(oldContext);
}

void Save::apply(Document &d) {
	d.save(fileName);
}

void ESave::apply(Document &d) {
	d.save(fileName);
	exit(0);
}

void NewLine::apply(Document &d) {
	context = d.getContext();
	d.insert('\n');
}

Change * NewLine::reverse() {
	return new Deletion(context);
}

void DeleteLine::apply(Document &d) {
	while (*d != '\n') --d;
	++d;
	while (!d.atEnd() && *d != '\n') ch.push_back(d.remove());
}

Change * DeleteLine::reverse() {
	return new Insertion(context, ch);
}

void DeleteWord::apply(Document &d) {
//Move forward until the current character isn't a space or new line
	if (isspace(*d) || *d == '\n') {
		do {
			++d;
		} while (isspace(*d) || *d == '\n');
//Move backward until we reach the first letter of the line
	} else {
		do {
			if (d.atBeginning()) {
				break;
			}

			--d;
		} while (!isspace(*d) && *d != '\n');
		
		if (!d.atBeginning()) {
			++d;
		}
	}

	do {
		ch.push_back(d.remove());
	} while (!isspace(*d) && *d != '\n');
}

Change * DeleteWord::reverse() {
	return new Insertion(context, ch);
}

void BackOneWord::apply(Document &d) {
	--d;
	while (!d.atBeginning() && isspace(*d)) --d;
	while (!d.atBeginning() && !isspace(*d)) --d;
	if (isspace(*d)) ++d;
}

