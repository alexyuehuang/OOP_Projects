// Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "Header.h"
using namespace std;
int main(int argc, char* argv[])
{
	if (argc != 2) {
		return message(argv[0]);
	}
	vector <string> a;
	char * c=argv[1];
	vector <int> integers;
//	const char *b =c[0];
	int k = read(a, c);
	if (k != 0) {
		return k;
	}
	
	string iterator;
	for (int i = 0; i < a.size(); ++i) {
		iterator = a[i];
		if (isNumber(iterator)) {
			istringstream argsin(iterator);
			int out;
			argsin >> out;
			integers.push_back(out);
		}
		else {
			cout << iterator << endl;
		}
	}
	int out;
	for (int i = 0; i < integers.size(); ++i) {
		out = integers[i];
		cout << out << endl;
	}
	return 0;
}
bool isNumber(string k) {
	bool value = true;
	for (int i = 0; i < k.length(); ++i) {
		if (!isdigit(k[i])) {
			value = false;
		}
	}
	return value;
}
int read(vector <string> &a, char * b) {
	ifstream ifs;
	ifs.open(b);
	string word_1;
		if (!(ifs.is_open())) {
			return failure;
		}
		while (ifs >> word_1) {
			a.push_back(word_1);
		}
		return success;
}

int message(char* c) {
	//string* d = c + 1;
	//if (*d == "") {
	//	return no_file_name;
	//}
	cout << "usage: " << c<< "<input_file_name>" << endl;
	return failure;
	//cout << "Usage: " <<c<<d<< endl;
	//return success;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
