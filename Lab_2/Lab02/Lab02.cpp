// Lab02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "Board.h"
using namespace std;
//main func, receives input and prints out board
int main(int argc, char* argv[])
{
	char* c = argv[programName];
	if (argc != numofArguments) {
		return message(c, "should enter two strings, the second is your argument");
		
	}
	
	ifstream ifs(argv[fileName]);
	unsigned int a = 0;
	unsigned int b = 0;
	unsigned int& n = a;
	unsigned int& m = b;
	vector<piece> pieces;
	if (success != read(ifs, pieces, m, n)) {
		return notRead;
	}
	const vector<piece> readOnly = pieces;
	print(readOnly, m, n);
	neighbors(readOnly, m, n);
	return success;
}
//create an error message with two inputs
int message(char* c, char* d) {
	cout << c <<"  "<< d << endl;
	return wrong_number_arguments;
}
//function that changes the values in the input to lower case
char toLower(char* c) {
	char k = *c;
	if (*c <= 90 && *c >= 65) {
		k = *c + 32;
	}
	return k;
}
//same as above, but for string
string allLower(string c) {
	string d = "";
	for (int i = 0; i < (int) c.length(); ++i) {
		d += toLower(&c[(unsigned int)i]);
	}
	return d;
}
