#include <iostream>
#include <fstream>
#include <string>
#include "game_pieces.h"
#include <vector>
//use standard namespace
using namespace std; 
struct piece {
	string name;
	string display;
	colors color = invalid;
};
//functions
int dimensions(ifstream& a, unsigned int& b, unsigned int& c);
int read(ifstream& a, vector<piece>& d, unsigned int& b, unsigned int& c);
int print(const vector<piece>& a, unsigned int b, unsigned int c);
int neighbors(const vector<piece>& a, unsigned int b, unsigned int c);