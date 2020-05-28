// Studio5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
void mySwap(int& a, int& b);
//void mySwap(int*& a, int*& b);
void mySwap(int* const & a, int*const & b);
int main(int argc, char *argv[])
{
	int x = 1;
	int y = 2;
	int * r = &x;
	int * q = &y;
	int* const m = &x;
	int* const n = &y;
	mySwap(m, n);
	cout << *m <<*n << endl;

	
	return 0;
}
void mySwap(int* const& a, int* const& b) {
	cout << "mySwap version 3 " << endl;
	int c = * a;
	*a = *b;
	*b = c;
}
//void mySwap(int*& a, int*& b) {
	//cout << "mySwap version 2 " << endl;
//	int* c = a;
	//a = b;
	//b = c;
//}
void mySwap(int& a, int& b) {
		cout << "mySwap version 1 " << endl;
		int c =  a;
		a = b;
		b = c;
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
