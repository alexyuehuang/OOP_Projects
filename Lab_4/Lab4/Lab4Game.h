#pragma once
#include "Header.h"
#include <algorithm>
//gamebase class
class GameBase {
protected:
	unsigned int height = 0;
	unsigned int width = 0;
	vector<vector<string>> gameBoard;
	string o = "O";
	string x = "X";
	int maxLength = max(o.length(),x.length());
public:
	virtual bool done() = 0;
	virtual bool draw() = 0;
	int prompt(unsigned int& row, unsigned int& col);
	virtual int turn() = 0;
	virtual void print() = 0;
	int play();
	static shared_ptr<GameBase> checkArg(int a, char* b[]);
	friend ostream& operator<<(ostream& inStream, const GameBase& game);
};
//insertion operator
ostream& operator<< (ostream& inStream, const GameBase& game);