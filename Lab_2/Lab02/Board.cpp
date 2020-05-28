#include <iostream>
#include <fstream>
#include "Board.h"
#include <sstream>
using namespace std;

int dimensions(ifstream& a, unsigned int& b, unsigned int& c) {
	string line_1;
	unsigned int word_1 = 0;
	unsigned int word_2 = 0;
	if (!a.is_open()) {
		cout << "cannot open file" << endl;
		return notOpen;
	}
	if (!getline(a, line_1)) {
		cout << "cannot extract line" << endl;
		return notExtract;
	}
	istringstream iss (line_1);
	if (!(iss >> word_1)) {
		cout << "not read this line" << endl;
		return notRead;
	}
	if (!(iss >> word_2)) {
		cout << "not read this line" << endl;
		return notRead;
	}
	iss >> word_1;
	iss >> word_2;
	b = word_1;
	c = word_2;
	return success;
}
int read(ifstream& a, vector<piece>& d, unsigned int& b, unsigned int& c) {
	unsigned int w1, w2;
	string line_1;
	unsigned int& word_1 = w1;
	unsigned int& word_2 = w2;
	int t = dimensions(a, word_1, word_2);
	while (t == notRead) {
		t = dimensions(a, word_1, word_2);
	}
	if(success!=t) {
		return notExtract;
	}
	d = vector<piece>(w1 * w2);
	b = word_1;
	c = word_2;
	int k=0;
	while (getline(a, line_1)) {
		piece thisPiece;
		string itColor, itName, itDisplay, itX, itY;
		istringstream iss(line_1);
		unsigned int x, y;
		
		iss >> itColor;
		iss >> itName;
		iss >> itDisplay;
		iss >> x;
		iss >> y;
		unsigned int index = w1 *y + x;
		thisPiece.color = toEnum(itColor);
		thisPiece.name = itName;
		thisPiece.display = itDisplay;
		if (!(thisPiece.color == invalid || x >= w1 || y >= w2)) {
			d[index] = thisPiece;
			k = 1;
		}
		}
		if (k == 0) {
			return noPiecestoRead;

		}
		else {
			return success;
		}
		
}
//print out the board "-" indicate squares not played
int print(const vector<piece>& a, unsigned int b, unsigned int c) {
	vector<piece> k = a;
	if (k.size() != b * c) {
		cout << "wrong dimension" << endl;
		return wrong_dimension;
	}
	
	for (int i = c - 1; i >= 0; --i) {
		string output = "";
		for (int j = 0; j < (int)b; ++j) {
			string thisPiece = "-";
			int index = b * i + j;
			if (k[index].color != invalid) {
				thisPiece=k[index].display;
			}
			output += thisPiece;
		}
		cout << output << endl;
	}
	return success;
}
//print elements and its neighbors in the vector
int neighbors(const vector<piece>& a, unsigned int b, unsigned int c) {
	vector<piece> k = a;
	int g = 0;
	for (int i = 0; i < (int)c; ++i) {
		for (int j = 0; j < (int)b; ++j) {
			int index = b * i + j;
			int newIndex = index;
			if (k[index].color != invalid) {
				g++;
				string thisPiece;
				cout << j << "," << i <<" "<< (toStr((int)k[index].color)) << " " << k[index].name << ": ";
				if (i != 0) {
					index -= b;
					if (k[index].color != invalid) {
						cout<< j<< "," << i-1 <<" "<< (toStr((int)k[index].color)) << " " << k[index].name << "; ";
					}
				}
				index = newIndex;
				if (i != c-1) {
					index += b;
					if (k[index].color != invalid) {
						cout << j << "," << i +1 << " " << (toStr((int)k[index].color)) << " " << k[index].name << "; ";
					}
				}
				index = newIndex;
				if (j != 0) {
					index -= 1;
					if (k[index].color != invalid) {
						cout << j -1<< "," << i << " " << (toStr((int)k[index].color)) << " " << k[index].name << "; ";
					}
				}
				index = newIndex;
				if (j != b-1) {
					index += 1;
					if (k[index].color != invalid) {
						cout << j+1 << "," << i  << " " << (toStr((int)k[index].color)) <<" "<< k[index].name << "; ";
					}
				}
				index = newIndex;
				if (i != c - 1 && j != 0) {
					index += b - 1;
					if (k[index].color != invalid) {
						cout << j - 1 << "," << i+1 << " " << (toStr((int)k[index].color)) << " " << k[index].name << "; ";
					}
				}
				index = newIndex;
				if (i != 0 && j != 0) {
					index -= b + 1;
					if (k[index].color != invalid) {
						cout << j - 1 << "," << i - 1 << " " << (toStr((int)k[index].color)) << " " << k[index].name << "; ";
					}
				}
				index = newIndex;
				if (i != c - 1 && j != b-1) {
					index += b + 1;
					if (k[index].color != invalid) {
						cout << j + 1 << "," << i + 1 << " " << (toStr((int)k[index].color)) << " " << k[index].name << "; ";
					}
				}
				index = newIndex;
				if (i != 0 && j != b-1) {
					index +=  1-b;
					if (k[index].color != invalid) {
						cout << j + 1 << "," << i - 1 << " " << (toStr((int)k[index].color)) << " " << k[index].name << "; ";
					}
				}
				index = newIndex;
				cout << " " << endl;
			}
			
		}
	}
	if (g!=0) {
		return noPiecestoRead;
	}
	return success;
}