#include "CardGroup.h"
using std::cin;

int nUniqueVal = 0;

int getValidIntChoice(int acceptedValues[], int numValues) {
	string choice = " ";
	int intChoice;

	cin >> choice;

	for(unsigned int i=0; i<choice.size(); i++) {
		if(!isdigit(choice.at(i)) && choice.at(i) != '-' && choice.at(i) != '.')
			break;
	}

	intChoice = atoi(choice.c_str());
		
	for(int i=0; i<numValues; i++) {
		if(intChoice == acceptedValues[i])
			return acceptedValues[i];
	}
	
	return -1; //change later
}