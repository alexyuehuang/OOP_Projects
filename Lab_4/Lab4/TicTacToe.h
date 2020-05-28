#pragma once
#include "Lab4Game.h"
//class tictactoe derived from gamebase class
class TicTacToe : public GameBase {
public:
	virtual bool done();
	virtual bool draw();
	virtual int turn();
	void print();
	TicTacToe();
};