/*
Author: Jon Shidal
Purpose: CSE 332 lab 5
*/

#include "LSCommand.h"
#include "ReadFileVisitor.h"
#include "ReadMetadataFileVisitor.h"
#include<iostream>
#include<sstream>

using namespace std;

LSCommand::LSCommand(AbstractFileSystem * fileSys) : fs(fileSys) {}

int LSCommand::execute(std::string& CWD, std::string options) {
	AbstractFile* f = fs->openFile(CWD);
	if (f == nullptr) { // file creation failed
		cout << "failed to open directory" << endl;
		return directorydoesnotexist;
	}
	if (options == "") {
		ReadFileVisitor reader;
		f->accept(&reader);
	}
	else if(options =="-l") {
		ReadMetadataFileVisitor reader;
		vector<char> cont = f->read();
		string contentstr ;
		for (int i = 0; i < cont.size(); ++i) {
			contentstr += cont[i];
		}
		istringstream iss (contentstr);
		vector<string> newCont;
		string a;
		while (iss>>a) {
			newCont.push_back(a);
		}
		for (int i = 0; i < newCont.size(); ++i) {
			string place = CWD;
			place += "/";
			place += newCont[i];
			AbstractFile* anotherf = fs->openFile(place);
			if (anotherf != nullptr) {
				anotherf->accept(&reader);
			}
			fs->closeFile(anotherf);
		}
	}
	fs->closeFile(f);
	return success;
}
void LSCommand::displayInfo() {
	cout << "lists the contents of the current directory" << endl;
	cout << "Usage: ls" << endl;
}