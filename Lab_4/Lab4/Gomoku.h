#pragma once
#include "Lab4Game.h"
using namespace std;
//class gomokugame derived from gamebase class
class GomokuGame : public GameBase {
protected:
	string B = "B";
	unsigned int numWin = 5;
	string W = "W";
public: 
	GomokuGame();
	GomokuGame(int a, int b);
	GomokuGame(int a, int b, int c);
	virtual bool done();
	virtual bool draw();
	virtual int turn();
	virtual void print();
};
