// Studio4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
int main(int argc, char* argv[])
{
	if (argc != 3) {
		cout << "wrong number of Arguments:" << argv[0] << endl;
		cout << "try two arguments" << endl;
		return 1;
	}
	/*string together, word_1;
	vector<string> arguments;
	for (int i = 0; i < argc; ++i) {
		together += " ";
		together += argv[i];
	}
	istringstream iss(together);
	while (iss >> word_1) {
		cout << word_1 << endl;

	}*/
	cout << argv[1] << endl;
	cout << argv[2] << endl;
	return 0;
	int arr[2][3][5];
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < 5; ++k) {
				cout << "x"<<i <<endl;
				cout << "y" << j << endl;
				cout << "z" << k << endl;
				int m = i * j * k;
				arr[i][j][k] = m;
				cout << "value" << m << endl;

			}
		}
	}
	return 0;
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
