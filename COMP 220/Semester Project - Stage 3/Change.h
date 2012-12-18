/* 
  Authors:  Dorian P. Yeager and Oliver Spryn
  Course:   COMP 220, Computer Programming II 
  Date:     10 December 2012
  Description:  This file manages all of the changes to the document. 
*/ 

#ifndef __CHANGE_H
#define __CHANGE_H

#include "context.h"
#include <vector>

using std::vector;

class Document;

class Change {
public:
	virtual Change * reverse() {return 0;}
	virtual void apply(Document&) {};
	virtual bool isExit() { return true; };
	virtual void adjustContextAfterUndo(Document &d) {}
};

typedef Change Exit;

class NontrivialChange: public Change {
	virtual bool isExit() { return false; }
};

class Insertion: public NontrivialChange {
public:
	Insertion(Context context, char ch): context(context), ch(ch) {}
	Insertion(Context context, vector<char> ch): context(context), vch(ch) {}
	virtual Change * reverse();
	virtual void apply(Document &d);
	virtual void adjustContextAfterUndo(Document &d);
private:
	Context context; 
	char ch;
	vector<char> vch;
};

class Deletion: public NontrivialChange {
public:
	Deletion(Context context): context(context) {}
	virtual Change * reverse();
	virtual void apply(Document &d);
private:
	Context context; 
	char ch;
};

class Undo: public NontrivialChange {
public:
	virtual void apply(Document &d);
};

class MoveLeft: public NontrivialChange {
public:
	virtual void apply(Document &d);
};

class MoveRight: public NontrivialChange {
public:
	virtual void apply(Document &d);
};

class MoveUp: public NontrivialChange {
public:
	virtual void apply(Document &d);
};

class MoveDown: public NontrivialChange {
public:
	virtual void apply(Document &d);
};

class BeginningOfLine: public NontrivialChange {
public:
	virtual void apply(Document &d);
};

class EndOfLine: public NontrivialChange {
public:
	virtual void apply(Document &d);
};

class BeginningOfFile: public NontrivialChange {
public:
	virtual void apply(Document &d);
};

class EndOfFile: public NontrivialChange {
public:
	virtual void apply(Document &d);
};

class Word: public NontrivialChange {
public:
	virtual void apply(Document &d);
};

class Save: public NontrivialChange {
public:
	Save(const char * fileName = ""): fileName(fileName) {}
	virtual void apply(Document &d);
private:
	const char * fileName;
};

class ESave: public NontrivialChange {
public:
	ESave(const char * fileName = ""): fileName(fileName) {}
	virtual void apply(Document &d);
private:
	const char * fileName;
};

class NewLine: public NontrivialChange {
public:
	virtual void apply(Document &d);
	virtual Change * reverse();
private:
	Context context;
};

class DeleteLine: public NontrivialChange {
public:
	virtual void apply(Document &d);
	virtual Change * reverse();
private:
	Context context;
	vector<char> ch;
};

class DeleteWord: public NontrivialChange {
public:
	virtual void apply(Document &d);
	virtual Change * reverse();
private:
	Context context;
	vector<char> ch;
};

class BackOneWord: public NontrivialChange {
public:
	virtual void apply(Document &d);
};


#endif
