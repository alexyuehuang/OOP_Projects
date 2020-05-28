#include <iostream>
using namespace std;
class Rect {
private: int length=1; const int parameter=1;
public:
	int width=1; 
	Rect() :length(0), width(0), parameter(0)
	{}
//	Rect( Rect &n) :length(n.getlength()), width(n.getwidth()), parameter(0)
	//{}
	int getlength() {
		return length;
	}
	int getwidth() {
		return width;
	}
	void changewidth(int a) {
		width = a;
	}
	void changelength(int a) {
		length = a;
	}
	/*void parameter(int a) {
		parameter = a;
	}*/
	int getparameter() {
		return parameter;
	}

};
