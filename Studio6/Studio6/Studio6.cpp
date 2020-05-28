// Studio6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;
double divideSquaredElements(vector<int> a, unsigned int b, unsigned int c);
int squareElement(vector<int> a, unsigned int b);
int main(int argc, char* argv[])
{
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(6);
	a.push_back(0);
	/*try {
		int k = squareElement(a, 10);
	}
	catch (const std::out_of_range) {
		cout << "wrong index:" << 10 << endl;
		return 1;
	}
	catch(...){
		cout << "probably wrong index:" << 10 << endl;
		return 1;
	}*/
	int k;
	try {
		k = divideSquaredElements(a, 3,2);
	}
	catch (const std::out_of_range) {
		cout << "wrong index:" << endl;
		return 1;
	}
	catch (const std::logic_error) {
		cout << "divide 0" << endl;
		return 1;
	}
	catch (...) {
		cout << "probably wrong index:" << 10 << endl;
		return 1;
	}
	cout << k << endl;
	cout << squareElement(a, 3) << endl;
	cout << squareElement(a, 2) << endl;
	return 0;
}
int squareElement(vector<int> a, unsigned int b) {
	if (b >= a.size() + 1) {
		cout << "index out of bounds!" << endl;
		throw std::out_of_range("index not right");;
	}
	return a[b] * a[b];
}
double divideSquaredElements(vector<int> a, unsigned int b, unsigned int c) {
	int m = squareElement(a, b);
	int n = squareElement(a, c);
	if (n == 0)
	{
		cout << "second one cannot zero!" << endl;
		throw std::logic_error("divide zero");;
	}
	return ((double)m) / ((double)n);
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
