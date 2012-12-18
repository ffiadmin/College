/*
  Author:       Oliver J. M. Spryn
  Course:       COMP 220, Computer Programming II
  Date:         6 September 2012
  Description:  This file encapsulates the complete functionality of this program.
                Between the main() driver function and five helper functions, this
				program will find the first 100 emirps, and output them in the 
				console in a 10 x 10 right-justified table.
*/

#include <iostream>;
#include <cmath>;
using std::cout;
using std::endl;
using std::pow;

int reverse(int number);
bool isPrime(int number);
bool hasEmirp(int number);
bool isPalindrome(int number);
void format(int number, int cellWdith);

int main (int argc, char *argv[]) {
	const int FIND_NUMBER_OF_EMIRPS = 100;
	const int CHAR_WIDTH_OF_TABLE_CELL = 6;
	int emirps = 1;
	int number = 10;

	cout << "Below are the first " << FIND_NUMBER_OF_EMIRPS << " emirps in existance: "
		 << endl << endl;

//Repeat the emirp determination algorithm until FIND_NUMBER_OF_EMIRPS has been reached
	do {
		if (!isPalindrome(number) && isPrime(number) && hasEmirp(number)) {
			format(number, CHAR_WIDTH_OF_TABLE_CELL);

		//Create a line break every 10 "table cells"
			if (emirps % 10 == 0 && emirps != 0) {
				cout << endl;
			}

		//Keep track of the number of emirps we have found
			emirps++;
		}

		number ++;
	} while(emirps <= FIND_NUMBER_OF_EMIRPS);

	return 0;
}

/**
 * This function contains an algorithm to reverse a integer. For example,
 * if 356 is given, then 653 will be returned, and if 1000 is given, 1 is
 * returned. The algorithm is briefly outlined here:
 *
 * - 1. the exponential power (actually one less than the exponential power)
 *      of the provided number is calculated, and its power is stored in a
 *      variable for future use
 * - 2. using this number, it is brought in a for loop and it is used to
 *      mathematically traverse the given number backwards
 * - 3. using integer division, the last number is retrieved (in the case
 *      of 356, the 3 is retrieved), then it is added to number the function
 *      will return
 * - 4. while performing a modulo operation, the original number is updated,
 *      and the first digit is stripped off (in the case of 356, the 3 is 
 *      removed and 56 replaces the original value)
 * - 5. this process is repeated until only one number remains
 * - 6. if only one number remains, step 4 is skipped
 * - 7. due to a mathematical calculation error, numbers such as 10, 100,
 *      1000, etc... will always return 10. Therefore, if the calculated
 *      result is 10, the algorithm will update the returned value to 
 *      simply 1. This is not a problem with 20, 300, 4000, etc...
 * - 8. the calculated integer is returned
 *
 * Precondition  : a number must be provided to the function
 * Postcondition : the provided number will be reversed
 *
 * @param     int      number        The number the algorithm should reverse
 * @return    float    reverse       The reverse of the supplied argument
*/

int reverse(int number) {
	int power = 0;
	int powerReverse = 0;
	int basePowerResult = 0;
	int reverse = 0;

//Step 1
	while (number > pow(10.0, power + 1)) {
		power++;
	}
	
//Steps 2, 3, 4, 5, and 6
	for (int i = power; i >= 0; i --) {
		basePowerResult = static_cast<int>(pow(10.0, power));

		reverse += (number / basePowerResult) * pow(10.0, powerReverse);

		if (i > 0) {
			number = number % basePowerResult;
		}
		
		power --;
		powerReverse ++;
	}

//Step 7
	if (reverse == 10) {
		reverse = 1;
	}

	return reverse;
}

/**
 * This function determines whether or not the given number is prime.
 * Since the definition of a prime number is "a number which can be
 * divided by a number other than 1 and itself and return a whole
 * number", the algorithm will divide the provided number by all
 * integers between, but not including 1 and itself.
 *
 * If division results in no remaining values, then we know the
 * provided number is composite, and does not satisfy this condition.
 *
 * Precondition  : a number must be provided to the function
 * Postcondition : a boolean will be returned, indicating whether or not
 *                 the provided number is prime
 *
 * @param     int      number        The number the algorithm should determine whether it is prime
 * @return    bool     <undefined>   Whether or not the provided number is prime
*/

bool isPrime(int number) {
	for (int i = 2; i < number; i ++) {
		if (number % i == 0) {
			return false;
		}
	}

	return true;
}

/**
 * This function determines whether or not the given number has an
 * emirp. It is simply a shortcut function which calls the previously
 * defined reverse() and isPrime() functions and returns true of false
 * based on the conditions that these functions have determined.
 *
 * Precondition  : a number must be provided to the function, and the 
 *                 reverse() and isPrime() helper functions must be
 *                 defined
 * Postcondition : a boolean will be returned, indicating whether or not
 *                 the provided number has an emirp
 *
 * @param     int      number        The number the algorithm should determine whether it has an emirp
 * @return    bool     <undefined>   Whether or not the provided number has an emirp
*/

bool hasEmirp(int number) {
	number = reverse(number);
	return isPrime(number);
}

/**
 * This function determines whether or not the given number is a
 * palindrome. It is simply a shortcut function which utilizes the
 * previously defined reverse() function and compares the output
 * of this function with the originally supplied number.
 *
 * Precondition  : a number must be provided to the function, and the 
 *                 reverse() helper function must be defined
 * Postcondition : a boolean will be returned, indicating whether or not
 *                 the provided is a palindrome
 *
 * @param     int      number        The number the algorithm should determine whether it is a palindrome
 * @return    bool     <undefined>   Whether or not the provided number is a palindrome
*/

bool isPalindrome(int number) {
	if (number == reverse(number)) {
		return true;
	} else {
		return false;
	}
}

/**
 * This function will format the given text so that the main() 
 * driver function can use it to emulate the appearance of a 
 * right-justified table. This function will not return the 
 * formatted output, but, rather, will cout it to the console.
 *
 * Precondition  : a number must be provided to the function
 * Postcondition : a boolean will be returned, indicating whether or not
 *                 the provided is a palindrome
 *
 * @param     int      number        The number the algorithm should right-justify
 * @return    void
*/

void format(int number, int cellWidth) {
	int power = 0;

//How many spaces should be added to the left, to right-justify the number?
	while (number > pow(10.0, power)) {
		power++;
	}

//Hmm... I can't get setw() working, so I'll just manually cout spaces
	for (int i = 1; i <= cellWidth - power; i ++) {
		cout << " ";
	}

	cout << number;
}