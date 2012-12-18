#include <iostream>

#include "FileOpenFailureException.h"
#include "Inventory.h"

using std::cin;
using std::cout;
using std::endl;

Inventory::Inventory(char *source) {
	this->fin.open(source);

	if (this->fin.fail()) {
		throw FileOpenFailureException("The requested file could not be opened!");
	}

	this->initStorage();
	this->parse();
	this->read();
}

void Inventory::initStorage() {
	for(int i = 0; i < 16; i++) {
		for(int j = 0; j < 7; j++) {
			for(int k = 0; k < 8; k++) {
				this->count[i][j][k] = 0;
			}
		}
	}
}

void Inventory::parse() {
	int bundle = 0;
	int thickness = 0;
	int lengths = 0;
	int length1 = 0;
	int length2 = 0;
	int length3 = 0;
	int garbage = 563465854;
	int temp = 0;
	double sum = 0.0;

	this->boardfeet = 0.0;

//Set output precision
	cout.setf(std::ios_base::fixed);
	cout.setf(std::ios_base::showpoint);
	cout.precision(2);

	this->fin >> bundle;

	while (!this->fin.eof()) {
	//Read the bundle data
		this->fin >> thickness;
		this->fin >> lengths;
		this->fin >> length1;

		if (lengths >= 2) {
			this->fin >> length2;
		}

		if (lengths == 3) {
			this->fin >> length3;
		}

	//Read the widths in each bundle
		this->fin >> garbage;

		for(int i = 0; i < 7; i++) {
			this->fin >> temp;
			this->count[thickness - 1][i][(length1 / 2) - 3] += temp;
			sum += ((static_cast<double>(i) + 1) * 2.0) * (static_cast<double>(length1)) * (thickness / 4.0) * static_cast<double>(temp);
		}
		
		if (lengths >= 2) {
			this->fin >> garbage;

			for(int j = 0; j < 7; j++) {
				this->fin >> temp;
				this->count[thickness - 1][j][(length2 / 2) - 3] += temp;
				sum += ((static_cast<double>(j) + 1) * 2.0) * (static_cast<double>(length2)) * (thickness / 4.0) * static_cast<double>(temp);
			}
		}

		if (lengths == 3) {
			this->fin >> garbage;

			for(int k = 0; k < 7; k++) {
				this->fin >> temp;
				this->count[thickness - 1][k][(length3 / 2) - 3] += temp;
				sum += ((static_cast<double>(k) + 1) * 2.0) * (static_cast<double>(length3)) * (thickness / 4.0) * static_cast<double>(temp);
			}
		}

		sum /= 12.0;

		cout << "Processed " << bundle << ",    " << sum << endl;
		this->fin >> bundle;
		boardfeet += sum;
		sum = 0.0;
	}

	cout << "Inventory data loaded. " << sum << " total board feet." << endl << endl;
}

void Inventory::read() {
	char command = 'a';
	int boardNum = 0;
	double thickness = 0.0;
	int width = 0;
	int length = 0;
	int item = 0;

	cout << this->boardfeet << " total board feet." << endl;

	cin.get(command);

	while (toupper(command) != 'E') {
	//Read in the data
		if (command == 'R' && cin.peek() == ' ') {
			cin >> boardNum;
			cin >> thickness;
			cin.ignore();
			cin >> width;
			cin >> length;

			item = this->count[static_cast<int>(thickness * 4 - 1)][width / 2 - 1][length / 2 - 3];

			if (boardNum <= item) {
				boardfeet -= static_cast<double>(width * thickness * length) / 12.0;
				this->count[static_cast<int>(thickness * 4 - 1)][width / 2 - 1][length / 2 - 3] = item - boardNum;

				cout << "Yes, we have " << boardNum << " " << length << "-foot boards "
					 << thickness << " inches by " << width << " inches. "
					 << "After filling this order we now have " << item - boardNum 
					 << " remaining " << length << "-foot boards "
					 << thickness << " inches by " << width << " inches."
					 << endl << endl;

			} else {
				cout << "Why do you ask so much of us? We only have " << item << " boards." << endl << endl;
			}

		} else {
			cout << "Sorry, we are unable to process this request.  Please try again." << endl << endl;
		}

		cout << this->boardfeet << " total board feet." << endl;

		cin.ignore(1000, '\n');
		cin.get(command);
	}
}