//enum to string
#include <iostream>
#include <fstream>
#include "game_pieces.h"
using namespace std;
string toStr(int f) {
	string colorsStr[] = { "red", "blue", "BLUE" , "black", "white", "no_color", "invalid" };
	return allLower(colorsStr[f]);
}
//string to enum
colors toEnum(string c) {
	string colorsStr[] = { "red", "blue", "BLUE" , "black", "white", "no_color", "invalid" };
	if (c == "") {
		return no_color;
	}
	for (int i = 0; i < 6; ++i) {
		if (c == colorsStr[i]) {
			return colors(i);
		}
	}
	return invalid;
}