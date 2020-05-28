#include "Gomoku.h"
#include <math.h>
#include <algorithm>
//constructor 1
GomokuGame::GomokuGame() {
	width = gomokudimension;
	height = gomokudimension;
	for (unsigned int i = 0; i < gomokudimension; i++) {
		vector<string> a;
		for (unsigned int j = 0; j < gomokudimension; j++) {
			a.push_back(" ");	 
		}
		gameBoard.push_back(a);
	}
}
// constructor takes in width height and numWin.
GomokuGame::GomokuGame(int a, int b, int c) {
	numWin = c;
	width = a;
	height = b;
	for (unsigned int i = 0; i < width; i++) {
		vector<string> a;
		for (unsigned int j = 0; j < height; j++) {
			a.push_back(" ");
		}
		gameBoard.push_back(a);
	}
}
// constructor takes in width and height.
GomokuGame::GomokuGame(int a, int b) {
	width = a;
	height = b;
	for (unsigned int i = 0; i < width; i++) {
		vector<string> a;
		for (unsigned int j = 0; j < height; j++) {
			a.push_back(" ");
		}
		gameBoard.push_back(a);
	}
}
//done()method takes in nothing and return a boolean. If done/win, return true. Otherwise, return false
bool GomokuGame:: done() {
	if ((gameBoard.size()) < numWin) {
		return false;
	}
	for (unsigned int i = 0; i < gameBoard[0].size(); i++) {
		for (unsigned int j = 0; j < gameBoard.size() - numWin + 1; j++) {
			// horizontal win
			bool check = true;
			for (unsigned int k = 1; k < numWin; k++) {
				if (gameBoard[i][j] != gameBoard[i][j + k]) {
					check = false;
				}
				
			}
			if (gameBoard[i][j] == " ") {
				check = false;
			}
			if (check) {
				return true;
			}
		}
	}
	//vertical win
	for (unsigned int i = 0; i < gameBoard[0].size() - numWin + 1; i++) {
		for (unsigned int j = 0; j < gameBoard.size(); j++) {
			bool check = true;
			for (unsigned int k = 1; k < numWin; k++) {
				if (gameBoard[i][j] != gameBoard[i+k][j]) {
					check = false;
				}

			}
			if (gameBoard[i][j] == " ") {
				check = false;
			}
			if (check) {
				return true;
			}
		}
	}
	//bottom to top diagonal
	for (unsigned int i = 0; i < gameBoard[0].size() - numWin + 1; i++) {
		for (unsigned int j = 0; j < gameBoard.size() - numWin + 1; j++) {
			bool check = true;
			for (unsigned int k = 1; k < numWin; k++) {
				if (gameBoard[i][j] != gameBoard[i + k][j + k]) {
					check = false;
				}

			}
			if (gameBoard[i][j] == " ") {
				check = false;
			}
			if (check) {
				return true;
			}
		}
	}
	//top to bottom diagonal
	for (unsigned int i = numWin - 1; i < gameBoard[0].size(); i++) {
		for (unsigned int j = 0; j < gameBoard.size() - numWin + 1; j++) {
			bool check = true;
			for (unsigned int k = 1; k < numWin; k++) {
				if (gameBoard[i][j] != gameBoard[i - k][j + k]) {
					check = false;
				}

			}
			if (gameBoard[i][j] == " ") {
				check = false;
			}
			if (check) {
				return true;
			}
		}
	}
	
	return false;
}
//draw() method takes in nothing and return a boolean.
bool GomokuGame:: draw() {
	int numEmpty = 0;
	
	for (unsigned int i = 0; i < gameBoard[0].size(); i++) {
		for (unsigned int j = 0; j < gameBoard.size(); j++) {
			if (gameBoard[i][j] == " ") {
				numEmpty++;
			}
		}
	}
	if (numWin > gameBoard.size()) {
		if (numEmpty == 0) {
			return true;
		}
		return false;
	}
	if (numEmpty == 0 && !(*this).done()) {
		cout << 1;
		return true;
	}
	unsigned int half = (int)ceil(numEmpty/2);
	for (unsigned int i = 0; i < gameBoard[0].size()-numWin+1; i++) {
		for (unsigned int j = 0; j < gameBoard.size(); j++) {
			string a = "";
			bool b = true;
			unsigned int count = 0;
			for (unsigned int k = 0; k < numWin; k++) {
				if (gameBoard[i + k][j] != " ") {
					if (a == "") {
						a = gameBoard[i + k][j];
					}
					else if(a!= gameBoard[i + k][j]){
						b = false;
					}
				}
				else {
					count++;
				}
			}
			if (b&&count<=half) {
				return !b;
			}
		}
	}
	for (unsigned int i = 0; i < gameBoard[0].size() ; i++) {
		for (unsigned int j = 0; j < gameBoard.size()-numWin+1; j++) {
			string a = "";
			bool b = true;
			unsigned int count = 0;
			for (unsigned int k = 0; k < numWin; k++) {
				if (gameBoard[i][j+k] != " ") {
					if (a == "") {
						a = gameBoard[i][j+k];
					}
					else if (a != gameBoard[i][j+k]) {
						b = false;
					}
				}
				else {
					count++;
				}
			}
			if (b && count <= half) {
				return !b;
			}
		}
	}
	for (unsigned int i = 0; i < gameBoard[0].size()-numWin+1; i++) {
		for (unsigned int j = 0; j < gameBoard.size() - numWin+1; j++) {
			string a = "";
			bool b = true;
			unsigned int count = 0;
			for (unsigned int k = 0; k < numWin; k++) {
				if (gameBoard[i+k][j + k] != " ") {
					if (a == "") {
						a = gameBoard[i+k][j + k];
					}
					else if (a != gameBoard[i+k][j + k]) {
						b = false;
					}
				}
				else {
					count++;
				}
			}
			if (b && count <= half) {
				return !b;
			}
		}
	}
	for (unsigned int i = numWin-1; i < gameBoard[0].size(); i++) {
		for (unsigned int j = 0; j < gameBoard.size() - numWin; j++) {
			string a = "";
			bool b = true;
			unsigned int count = 0;
			for (unsigned int k = 0; k < numWin; k++) {
				if (gameBoard[i-k][j + k] != " ") {
					if (a == "") {
						a = gameBoard[i-k][j + k];
					}
					else if (a != gameBoard[i-k][j + k]) {
						b = false;
					}
				}
				else {
					count++;
				}
			}
			if (b && count <= half) {
				return !b;
			}
		}
	}
	return true;
}
//turn() method takes in nothing and return an integer.
int GomokuGame ::turn() {
	unsigned int playerB = 0;
	unsigned int playerW = 0;
	unsigned int empty = 0;
	unsigned int a;
	unsigned int b;
	bool successMove = false;
	//if cannot get valid coordinates
	if (prompt(a, b) == quit) {
		return quit;
	}
	//count whose 
	for (unsigned int i = 0; i < height; ++i) {
		for (unsigned int j = 0; j < width; j++) {
			if (gameBoard[i][j] == "W") {
				playerW++;
			}
			else if (gameBoard[i][j] == "B") {
				playerB++;
			}
			else {
				empty++;
			}
		}
	}
	//playerO go first(empty board case)
	if (empty == height * width) {
		cout << "PlayerB starts first" << endl;
	}
	if (playerB > playerW && playerB != 0 && empty != height*width) {
		cout << "It's playerW's turn" << endl;
	}
	else if (playerB != 0 && playerB == playerW && empty != height*width) {
		cout << "It's playerB's turn" << endl;
	}
	if (gameBoard[a][b] == " " && a >= 0 && a < height && b >= 0 && b < width) {
		if (playerB > playerW) {
			//make the move
			gameBoard[a][b] = "W";
			successMove = true;
			//record all the move by playerX
			vector<string> taken;
			for (unsigned int i = 0; i < height; ++i) {
				for (unsigned int j = 0; j < width; ++j) {
					if (gameBoard[i][j] == "W") {
						taken.push_back(to_string(i+1));
						taken.push_back(",");
						taken.push_back(to_string(j+1));
						taken.push_back(";");
					}
				}
			}
			//print the board
			cout << *this << endl;
			cout << "PlayerW: ";
			for (unsigned int i = 0; i < taken.size(); i++) {
				cout << taken[i];
			}
			cout << endl;
			return success;
		}
		else {
			//make the move
			gameBoard[a][b] = "B";
			successMove = true;
			vector<string> taken;
			for (unsigned int i = 0; i < height; ++i) {
				for (unsigned int j = 0; j < width; ++j) {
					if (gameBoard[i][j] == "B") {
						taken.push_back(to_string(i+1));
						taken.push_back(",");
						taken.push_back(to_string(j+1));
						taken.push_back(";");
					}
				}
			}
			//print the board
			cout << *this << endl;
			cout << "PlayerB: ";
			for (unsigned int i = 0; i < taken.size(); i++) {
				cout << taken[i];
			}
			cout << endl;
			return success;
		}
	}
	return notValidMove;
}
//print the board.
void GomokuGame:: print() {
	cout << *this << endl;
}
