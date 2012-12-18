/* 
  Authors:  Oliver Spryn
  Course:   COMP 220, Computer Programming II 
  Date:     10 December 2012
  Description:  This class provides a file browser for a user to choose a file to edit. 
*/ 


#include <string>
#include <vector>

using std::string;
using std::vector;

typedef struct {
	string name;
	string fullPath;
	bool isDirectory;
} FileInfo;

class FileBrowser {
public : 
	string directory;
	vector<FileInfo> info;

	FileBrowser(string directory);
	string print();

private : 
	void fetch();
	string goTo(int option);
	string newFile();
};