//what to include
#include <iostream>
#include <vector>
using namespace std;
//definitions:enums
enum results{ success, failure, userQuit, invalidEntry, notExtract, quitted, drawn, wrong_num_arguments};
enum values { programName, fileName, argumentNum, autoargnum };
//pieces, NA means no value should be added and E means waiting user value. 
enum pieces{X, O, NA, E};
//values for this lab
int actualPiecesCount = 2;
string arg1 = "TicTacToe";
string arg2 = "auto_player";
int length = 5;
int midL = 2;
bool isAuto = false;
//define a board class
class board {
private:
	std::vector<pieces> myPiece = vector<pieces>(0);
public:
	string xMove, oMove;
	bool isX = true;
	board();
	bool xWon;
	int numTurns;
	bool done();
	bool draw();
	int turn();
	vector<int> auto_player();
	int play();
	int prompt(unsigned int& a, unsigned int& b);
	friend ostream& operator<< (ostream& out, const board a);
	friend void printMove(const board a);
};
//functions
ostream &operator<< (ostream &out,const board a);
void printMove(const board a);
int checkResult(string i,unsigned int& a, unsigned int& b);
int message(char* c, char* d);

