#include <iostream>
#include "Lab4Game.h"
//usage message 
int usage(string c, string rest) {
	cout << "usage: " << c << rest << endl;
	return fail;
}
//main function takes in argc and char* argv[] and return int type
int main(int argc, char* argv[])
{
	//try catch bad_alloc or unknown error
	try {
		shared_ptr<GameBase> k = GameBase::checkArg(argc, argv);
		if (k == nullptr) {
			return usage(argv[programname], " String or String Number not correct!");
		}
		else {
			return k->play();
		}
	}
	//catch bad alloc error
	catch (bad_alloc& ba) {
		cerr << "bad_alloc caught: " << ba.what() << endl;
		return fail;
	}
	//catch other unknown errors
	catch (...) {
		cerr << "Unknown error catched" << endl;
		return fail;
	}
	return success;
}

