#include "TicTacToe.h"
#include "Gomoku.h"
#include <sstream>
using namespace std;
//insertion operator, takes in ostream reference and gamebase referencce
ostream& operator<< (ostream& inStream, const GameBase& game) {
	for (int i = game.gameBoard[0].size() - 1; i >= 0; i--) {
		//If it is two digit
		if (i + 1 >= 10){
			inStream << i + 1;
		}
		else{
			inStream << i + 1 << " ";
		}
		for (unsigned int j = 0; j < game.gameBoard.size(); j++) {
			inStream << game.gameBoard[j][i]<<" ";
			if (j >= 9) {
				inStream << " ";
			}
		}
		cout << endl;
	}
	inStream << "X";
	for (unsigned int j = 1; j <= game.gameBoard.size(); j++) {
		inStream << " "<<j;
	}
	cout << endl;
	return inStream;
}
//shared pointer takes in an integer(size) and a pointer char array and check the input number and name
shared_ptr<GameBase> GameBase::checkArg(int a, char* b[]) {
	//Two argument case
	if (a == correctNumInput) {
		string s = b[gameName];
		//TicTacToe game
		if (s == "TicTacToe") {
			shared_ptr<GameBase> c = make_shared<TicTacToe>();
			return c;
		}
		//Gomoku Game
		if (s == "Gomoku") {
			shared_ptr<GameBase> c = make_shared<GomokuGame>();
			return c;
		}
	}
	//three argument case
	if (a == correctNumInputExtraCredit) {
		stringstream str(b[extraCreditFirst]);
		int x;
		if (!(str >> x)) {
			shared_ptr<GameBase> c = 0;
			return c;
		}
		//
		if (x >= smallestdimension) {
			shared_ptr<GameBase> c = make_shared<GomokuGame>(x,x);
			return c;
		}
		
	}
	if (a == correctNumInputExtraArgument) {
		stringstream str(b[extraCreditFirst]);
		stringstream str2(b[extraCreditSecond]);
		int x,y;
		if (!(str >> x )||!(str2>>y)) {
			shared_ptr<GameBase> c = 0;
			return c;
		}
		if (y <= x && y >= smallestdimension) {
			shared_ptr<GameBase> c = make_shared<GomokuGame>(x, x, y);
			return c;
		}
		
	}
	// 0 pointer
	shared_ptr<GameBase> c = 0;
	return c;
}
//prompt takes in unsigned int reference row and column and return int.
int GameBase::prompt(unsigned int& row, unsigned int& col) {
	cout << "Please either enter a valid cordinate(in the form of: col#,row#) or enter quit" << endl;
	string s;
	cin >> s;
	//check if user type in quit
	if (s == "quit") {
		return quit;
	}
	//replace comma with space
	for (unsigned int i = 0; i < s.length(); i++) {
		if (s[i] == ',') {
			s[i] = ' ';
		}
	}
	istringstream iss(s);
	//extract row and col and return success
	if (iss >> row >> col) {
		if (row >= 1 && row <= width && col >= 1 && col <= height && gameBoard[row-1][col-1] == " ") {
			row--;
			col--;
			return success;
		}
		else {
			cout << "Please Re-enter a valid coordinate within the range that has not been occupied" << endl;
			return prompt(row, col);
		}
	}
	//if cannot extract
	else {
		//main function needs to repeatly call prompt if false!
		cout << "Please Re-enter a valid coordinate within the range that has not been occupied" << endl;
		return prompt(row, col);
	}
}
//play method takes in nothing and return integer showing win or tie
int GameBase::play() {
	unsigned int a = 0;
	unsigned int b = 0;
	//print out the gameboard
	cout << *this << endl;
	bool doneb = done();
	bool drawb = draw();
	int turnReturn = turn();
	//repeatedly call method
	while ((doneb != true) && (drawb != true) && (turnReturn != quit)) {
		turnReturn = turn();
		doneb = done();
		drawb = draw();
	}
	//Case1: done() return true, print out success message 
	int countX = 0;
	int countO = 0;
	//first check if the game is done(someone wins the game or not)
	if (doneb) {
		//if someone success, then determine the winner.
		//count for moves
		for (unsigned int i = 0; i < height; ++i) {
			for (unsigned int j = 0; j < width; ++j) {
				if (gameBoard[i][j] == "X" || gameBoard[i][j] == "B") {
					countX++;
				}
				else if (gameBoard[i][j] == "O" || gameBoard[i][j] == "W") {
					countO++;
				}
			}
		}
		//check the shape of game piece
		bool isB = true;
		for (unsigned int i = 0; i < height; ++i) {
			for (unsigned int j = 0; j < width; ++j) {
				if (gameBoard[i][j] == "X" || gameBoard[i][j] == "O") {
					isB = false;
				}
			}
		}
		//if playerX has more or equal move and since playerO start first, playerX must win
		if (countX >= countO&&!isB) {
			cout << "PlayerX wins!" << endl;
			return success;
		}
		//if playerO has more moves, playerO wins
		else if(!isB) {
			cout << "PlayerO wins!" << endl;
			return success;
		}
		else if(isB && countX > countO) {
			cout << "PlayerB wins!" << endl;
			return success;
		}
		else if(isB && countX <= countO){
			cout << "PlayerW wins!" << endl;
			return success;
		}
	}
	//Case2: draw() returns true
	int boardCount = 0;
	if (drawb) {
		//check all the occupied space
		for (unsigned int i = 0; i < height; ++i) {
			for (unsigned int j = 0; j <width; ++j) {
				if (gameBoard[i][j] != " ") {
					boardCount++;
				}
			}
		}
		cout << boardCount << " turns were played. " << "This is a Draw!";
		return tie;
	}
	//Case3: user quit
	if (turnReturn == quit) {
		for (unsigned int i = 0; i <height; ++i) {
			for (unsigned int j = 0; j < width; ++j) {
				if (gameBoard[i][j] != " ") {
					boardCount++;
				}
			}
		}
		cout << boardCount << " turns were played. The user quit!";
		return quit;
	}
	return success;
}