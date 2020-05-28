#include "TicTacToe.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <memory>
using namespace std;
//initialize empty board
TicTacToe::TicTacToe() {
	width = smallestdimension;
	height = smallestdimension;
	for (unsigned int i = 0; i <= width-1; i++) {
		vector<string> a;
		for (unsigned int j = 0; j <= height-1; j++) {
			a.push_back(" ");
		}
		gameBoard.push_back(a);
	}
}
//print method print the board
void TicTacToe::print() {
	cout << *this << endl;
}
//done()method takes in nothing and return a boolean. If done/win, return true. Otherwise, return false
bool TicTacToe::done() {
	//find three o or x
	//horizontal win
	for (unsigned int i = 0; i <= smallestdimension-1; i++) {
		if (gameBoard[i][1] == gameBoard[i][0] && gameBoard[i][2] == gameBoard[i][1] && gameBoard[i][1] != " ") {
			return true;
		}
	}
	//vertical win 
	for (unsigned int j = 0; j <= smallestdimension-1; j++) {
		if (gameBoard[1][j] == gameBoard[0][j] && gameBoard[2][j] == gameBoard[1][j] && gameBoard[1][j] != " ") {
			return true;
		}
	}
	//cross win(bottom to top and top to bottom)
	if ((gameBoard[1][1] == gameBoard[0][0] && gameBoard[2][2] == gameBoard[1][1] && gameBoard[1][1] != " ") || (gameBoard[2][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[0][2] && gameBoard[1][1] != " ")) {
		return true;
	}
	return false;
}
//draw() method takes in nothing and return a boolean.
bool TicTacToe::draw() {
	//check if done() returns true
	bool checkdone = false;
	checkdone = done();
	//first check if done() is true
	if (checkdone == false) {
		//check if there is any empty space on the board
		for (unsigned int i = 0; i <= smallestdimension-1; i++) {
			for (unsigned int j = 0; j <= smallestdimension-1; j++) {
				if (gameBoard[i][j] == " ") {
					return false;
					break;
				}
			}
		}
	}
	// if done() is false, return false
	else {
		return false;
	}
	//return true for any other circumstances
	return true;
}
//turn method decide whose turn and make the move and print out the current move for the player
int TicTacToe::turn() {
	unsigned int playerO = 0;
	unsigned int playerX = 0;
	unsigned int empty = 0;
	unsigned int a;
	unsigned int b;
	bool successMove = false;
	//if cannot get valid coordinates
	if (prompt(a, b) == quit) {
		return quit;
	}
	//count whose 
	for (unsigned int i = 0; i <= smallestdimension-1; ++i) {
		for (unsigned int j = 0; j <= smallestdimension-1; j++) {
			if (gameBoard[i][j] == "O") {
				playerO++;
			}
			else if (gameBoard[i][j] == "X") {
				playerX++;
			}
			else {
				empty++;
			}
		}
	}
	//playerO go first(empty board case)
	if (empty == smallestdimension* smallestdimension) {
		cout << "PlayerO starts first" << endl;
	}
	if (playerO > playerX && playerO != 0 && empty != smallestdimension* smallestdimension) {
		cout << "It's playerX's turn" << endl;
	}
	else if (playerO != 0 && playerO == playerX && empty != smallestdimension* smallestdimension) {
		cout << "It's playerO's turn" << endl;
	}
	if (gameBoard[a][b] == " " && a >= 0 && a <= smallestdimension-1 && b >= 0 && b <= smallestdimension-1) {
		if (playerO > playerX) {
			//make the move
			gameBoard[a][b] = "X";
			successMove = true;
			//record all the move by playerX
			vector<string> taken;
			for (unsigned int i = 0; i <= smallestdimension-1; ++i) {
				for (unsigned int j = 0; j <= smallestdimension-1; ++j) {
					if (gameBoard[i][j] == "X") {
						taken.push_back(to_string(i+1));
						taken.push_back(",");
						taken.push_back(to_string(j+1));
						taken.push_back(";");
					}
				}
			}
			//print the board
			cout << *this << endl;
			cout << "PlayerX: ";
			for (unsigned int i = 0; i < taken.size(); i++) {
				cout << taken[i];
			}
			cout << endl;
			return success;
		}
		else {
			//make the move
			gameBoard[a][b] = "O";
			successMove = true;
			vector<string> taken;
			for (unsigned int i = 0; i <= smallestdimension-1; ++i) {
				for (unsigned int j = 0; j <= smallestdimension-1; ++j) {
					if (gameBoard[i][j] == "O") {
						taken.push_back(to_string(i+1));
						taken.push_back(",");
						taken.push_back(to_string(j+1));
						taken.push_back(";");
					}
				}
			}
			//print the board
			cout << *this << endl;
			cout << "PlayerO: ";
			for (unsigned int i = 0; i < taken.size(); i++) {
				cout << taken[i];
			}
			cout << endl;
			return success;
		}
	}
	return notValidMove;
}
