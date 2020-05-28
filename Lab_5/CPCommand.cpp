#include"CPCommand.h"
#include "AbstractCommand.h"
#include<iostream>
#include<sstream>
#include"ImageFile.h"
#include"TextFile.h"
#include <cmath>
#include "DirectoryFile.h"


CPCommand::CPCommand(AbstractFileSystem* fileSys) : fs(fileSys) {}

int CPCommand::execute(std::string& CWD, std::string options) {
	string fullPath = CWD;
	fullPath += '/';
	istringstream iss(options);
	string w1, w2;
	iss >> w1;
	if (!(iss >> w2)) {
		cout << "Invalid: path invalid" << endl;
		return failtocopy;
	}
	fullPath += w1;
	AbstractFile* f = fs->openFile(fullPath);
	if (f == nullptr) {
		cout << "Invalid: not found" << endl;
		return AbstractCommand::invalidcommand;
	}
	fs->closeFile(f);
	vector<char> cont = f->read();
	AbstractFile* copy = f->clone();
	if (copy == nullptr) {
		return failtocopy;
	}
	AbstractFile* dir = fs->openFile(w2);
	fs->closeFile(dir);
	DirectoryFile* dirn= dynamic_cast<DirectoryFile*>(dir);
	if (dirn != nullptr) {
		fs->addFile(w2+"/"+copy->getName(), copy);
		return success;
	}
	return failtocopy;
	
}
void CPCommand::displayInfo() {
	cout << "cp copies the file to another location" << endl;
	cout << "Usage: ds <filetocpoy> <full path to destination>" << endl;
}

