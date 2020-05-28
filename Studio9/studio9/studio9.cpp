// studio9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <forward_list>
#include <list>
#include <deque>
using namespace std;
int main(int, char* [])
{
	vector<int> v;
	forward_list<int> f;
	list<int> l;
	deque<int> d;
	v.push_back(2);
	v.push_back(4);
	v.push_back(5);
	v.push_back(7);
	v.push_back(3);
	d.push_front(4);
	d.push_front(2);
	d.push_back(5);
	d.push_back(7);
	d.push_back(3);
	f.push_front(3);
	f.push_front(7);
	f.push_front(5);
	f.push_front(4);
	f.push_front(2);
	l.push_front(4);
	l.push_front(2);
	l.push_back(5);
	l.push_back(7);
	l.push_back(3);
	sort(v.begin(), v.end());
	sort(d.begin(), d.end());
	reverse(l.begin(), l.end());
	reverse(d.begin(), d.end());
	reverse(v.begin(), v.end());
	auto start = v.begin();     // cbegin() gives iterator
	while (start != v.cend()) {  // over const elements
		cout << *start << endl;
		++start;
	}
	auto stat = f.begin();     // cbegin() gives iterator
	while (stat != f.end()) {  // over const elements
		cout << *stat << endl;
		++stat;
	}
	auto stt = d.begin();     // cbegin() gives iterator
	while (stt != d.end()) {  // over const elements
		cout << *stt << endl;
		++stt;
	}
	auto st = l.begin();     // cbegin() gives iterator
	while (st != l.end()) {  // over const elements
		cout << *st << endl;
		++st;
	}

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
