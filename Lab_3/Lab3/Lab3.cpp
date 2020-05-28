// Lab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//what to include
#include <iostream>
#include "Header.h"
#include <sstream>
//initialize board
board::board() {
	myPiece = vector<pieces>(length*length);
	for (int i = 0; i < length*length; ++i) {
		myPiece[i] = NA;
	}
	for (int i = 1; i < (length - 1); ++i) {
		for (int j = 1; j < (length - 1); ++j) {
			myPiece[length * i + j] = E;
		}
	}
}
//return if the game finishes and someone wins
bool board::done() {
	for (int i = 1; i < (length-1); ++i) {
		int dim = length * i + 1;
		if (((*this).myPiece[dim]<actualPiecesCount)&&(*this).myPiece[dim] == (*this).myPiece[dim + 1] && (*this).myPiece[dim + 2] == (*this).myPiece[dim + 1]) {
			xWon = ((*this).myPiece[dim] == X);
			return true;
		}
	}
	for (int j = 1; j < 4; ++j) {
		int dim1 = j + length;
		int dim2 = j + 2*length;
		int dim3 = j + 3*length;
		if (((*this).myPiece[dim1] < actualPiecesCount) &&(*this).myPiece[dim1] == (*this).myPiece[dim2] && (*this).myPiece[dim2] == (*this).myPiece[dim3]) {
			xWon = ((*this).myPiece[dim1] == X);
			return true;
		}
	}
	int dim1 = 1 + length;
	int dim2 = 2 + length * 2;
	int dim3 = 3 + length * 3;
	if (((*this).myPiece[dim1] < actualPiecesCount) &&(*this).myPiece[dim1] == (*this).myPiece[dim2] && (*this).myPiece[dim3] == (*this).myPiece[dim1]) {
		xWon = ((*this).myPiece[dim1] == X);
		return true;
	}
	int dim4 = 3 + length;
	int dim5 = 2 + length * 2;
	int dim6 = 1 + length * 3;
	if (((*this).myPiece[dim4] < actualPiecesCount) &&(*this).myPiece[dim4] == (*this).myPiece[dim5] && (*this).myPiece[dim5] == (*this).myPiece[dim6]) {
		xWon = ((*this).myPiece[dim4] == X);
		return true;
	}
	return false;
}
//return if this vector includes the winning solution
bool isDone(vector<pieces>& myPiece) {
	for (int i = 1; i < 4; ++i) {
		int dim = length * i + 1;
		if ((myPiece[dim] < actualPiecesCount) && myPiece[dim] == myPiece[dim + 1] && myPiece[dim + 2] == myPiece[dim + 1]) {
			return true;
		}
	}
	for (int j = 1; j < 4; ++j) {
		int dim1 = j + length;
		int dim2 = j + length*2;
		int dim3 = j + length*3;
		if ((myPiece[dim1] < actualPiecesCount) && myPiece[dim1] == myPiece[dim2] && myPiece[dim2] == myPiece[dim3]) {
			return true;
		}
	}
	int dim1 = 1 + length;
	int dim2 = 2 + length * 2;
	int dim3 = 3 + length * 3;
	if ((myPiece[dim1] < actualPiecesCount) && myPiece[dim1] == myPiece[dim2] && myPiece[dim3] == myPiece[dim1]) {
		return true;
	}
	int dim4 = 3 + length;
	int dim5 = 2 + length * 2;
	int dim6 = 1 + length * 3;
	if ((myPiece[dim4] < actualPiecesCount) && myPiece[dim5] == myPiece[dim6] && myPiece[dim4] == myPiece[dim5]) {
		return true;
	}
	return false;
}
//return if a draw happens
bool board::draw() {
	if ((*this).done()) {
		return false;
	}
	for (int i = 1; i < (length - 1); ++i) {
		for (int j = 1; j < (length - 1); ++j) {
			if ((*this).myPiece[length * i + j] == E) {
				return false;
			}
		}
	}
	return true;
}
//prompt the user
int board::prompt(unsigned int&a, unsigned int &b) {
	cout << "please enter a valid coordinate or quit" << endl;
	string i;
	if (!(cin >> i)) {
		cout << "cannot extract!" << endl;
		return notExtract;
	}
	int k = checkResult(i, a,b);
	while (k != success) {
		if (k == quitted) {
			return quitted;
		}
		cout << "try again!" << endl;
		if (!(cin >> i)) {
			cout << "cannot extract!" << endl;
			return notExtract;
		}
		k = checkResult(i, a,b);
	}
	return success;
}
//check if the input string is valid
int checkResult(string i, unsigned int& a, unsigned int& b) {
	if (i == "quit") {
		return quitted;
	}
	i.replace(1, 1, " ");
	int num1, num2;
	istringstream iss(i);
	if (!(iss >> num1)) {
		cout << "invalid!" << endl;
		return invalidEntry;
	}
	if (!(iss >> num2)) {
		cout << "invalid!" << endl;
		return invalidEntry;
	}
	int index = num1 * length + num2;
	if (num1 > (length - 2) || num1 < 1 || num2>(length - 2) || num2 < 1) {
		cout << "invalid!" << endl;
		return invalidEntry;
	}
	a = num1;
	b = num2;
	return success;
}
//what to do for each turn;
int board::turn() {
	if (board::isX) {
		cout << "X turn" << endl;
	}
	if (!(board::isX)) {
		cout << "O turn" << endl;
		if (isAuto) {
			vector<int> a;
			a = (*this).auto_player();
			int index = a[0] * length + a[1];
			(*this).myPiece[index] = O;
			cout << *this << endl;
			(*this).oMove += to_string(a[0]);
			(*this).oMove += ", ";
			(*this).oMove += to_string(a[1]);
			(*this).oMove += "; ";
			printMove(*this);
			isX = !isX;
			++numTurns;
			return success;
		}
	}
	unsigned int a=0, b=0;
	int c = (*this).prompt(a, b);
	if (c == quitted) {
		return quitted;
	}
	while (((*this).myPiece[a * length + b] != E)||(c!=success)) {
		
		int d = (*this).prompt(a, b);
		if (d == quitted) {
			return quitted;
		}
	}
	if (board::isX) {
		(*this).myPiece[a * length + b] = X;
		(*this).xMove += to_string(a);
		(*this).xMove += ", ";
		(*this).xMove += to_string(b);
		(*this).xMove += "; ";
	}
	if (!(board::isX)) {
		(*this).myPiece[a * length + b] = O;
		(*this).oMove += to_string(a);
		(*this).oMove += ", ";
		(*this).oMove += to_string(b);
		(*this).oMove += "; ";
	}
	cout << *this<<endl;
	printMove(*this);
	isX = !isX;
	++numTurns;
	return success;
}
//print the line after board
void printMove(const board a) {
	string i;
	if (a.isX) {
		i += "Player X: ";
		cout << i << a.xMove << endl;
	}
	if (!(a.isX)) {
		i += "Player O: ";
		cout << i << a.oMove << endl;
	}
	cout << "" << endl;
	
}
//runs the game
int board::play() {
	cout << *this;
	int a = (*this).turn();
	if (a == quitted) {
		cout << "user quitted" << endl;
		cout << numTurns << " turns are played" << endl;
		return quitted;
	}
	while (a == success) {
		if ((*this).done()) {
			if (xWon) {
				cout << "X won!" << endl;
			}
			else{
				cout << "O won!" << endl;
			}
			return success;
		}
		if ((*this).draw()) {
			cout << numTurns << " turns are played and no winning moves remain" << endl;
			return drawn;
		}
		a = (*this).turn();
		if (a == quitted) {
			cout << "user quitted" << endl;
			cout << numTurns << " turns are played" << endl;
			return quitted;
		}
	}
	return success;
}
//main method
int main(int argc, char* argv[])
{
	if (argc != argumentNum) {
		if (argc == autoargnum) {
			if ((argv[1] == arg1) && (argv[2] == arg2)) {
				isAuto = true;
				board a = board();
				return a.play();
			}
			return message(argv[0], "if want to use auto, put two arguments: TicTacToe and auto_player");
		}
		return message(argv[0], "should enter two strings, the second is your argument");
	}
	if(argv[1]!=arg1){
		return message(argv[0], "wrong second argument! should be TicTacToe");
	}
	board a=board();
	return a.play();
}
//print error message
int message(char* c, char* d) {
	cout << c << "  " << d << endl;
	return wrong_num_arguments;
}
//print out the board
ostream& operator<< (ostream& out, const board a) {
	for (int i = (length-1); i > 0; --i) {
		out << i;
		for (int j = 0; j < length; ++j) {
			int dimension = length *j + i;
			if (a.myPiece[dimension] == E || a.myPiece[dimension] == NA) {
				out << " ";
			}
			if (a.myPiece[dimension] == X) {
				out << "X";
			}
			if (a.myPiece[dimension] == O) {
				out << "O";
			}
		}
		out << "\n";
	}
	out << 0 << endl;
	cout <<" "<< 0 << 1 << 2 << 3 << 4 << endl;
	return out;
}
//finds the next move
vector<int> board::auto_player() {
	vector<int> empties;
	vector<int> a;
	pieces c = O;
	pieces next = X;
	if (isX) {
		c = X;
		next = O;
	}
	for (int i = 1; i <= (length-2); ++i) {
		for (int j = 1; j <= (length - 2); ++j) {
			int index = length * i + j;
			if ((*this).myPiece[index] == E) {
				empties.push_back(index);
			}
		}
	}
	for (unsigned int i = 0; i < empties.size(); ++i) {
		int j = empties[i];
		vector<pieces> k = (*this).myPiece;
		k[j] = c;
		if (isDone(k)) {
			a.push_back(j / length);
			a.push_back(j % length);
			return a;
		}
	}
	for (unsigned int i = 0; i < empties.size(); ++i) {
		int j = empties[i];
		vector<pieces> k = (*this).myPiece;
		k[j] = next;
		if (isDone(k)) {
			a.push_back(j / length);
			a.push_back(j % length);
			return a;
		}
	}
	int midDim = midL * length + midL;
	if ((*this).myPiece[midDim] == E) {
		int j = midDim;
		a.push_back(j / length);
		a.push_back(j % length);
		return a;
	}
	int j = empties[0];
	a.push_back(j / length);
	a.push_back(j % length);
	return a;
}


