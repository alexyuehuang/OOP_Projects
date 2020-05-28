#include "DirectoryFile.h"
#include"CATCommand.h"
#include "AbstractFile.h"
#include "ReadFileVisitor.h"
#include "AbstractCommand.h"
#include<iostream>
#include<sstream>
#include "TextFile.h"
#include"Proxy.h"
using namespace std;

CATCommand::CATCommand(AbstractFileSystem* fileSys) : fs(fileSys) {}

// removes a file from the current working directory
int CATCommand::execute(std::string& CWD, std::string options) {
	string fullPath = CWD;
	fullPath += '/';
	istringstream iss(options);
	string w1, w2;
	iss >> w1;
	fullPath += w1;
	AbstractFile* f = fs->openFile(fullPath);
	if (f == nullptr) {
		cout << "Invalid: not found" << endl;
		return AbstractCommand::invalidcommand;
	}
	fs->closeFile(f);
	if ((dynamic_cast<Proxy*>(f)) != nullptr) {
		f = (dynamic_cast<Proxy*>(f))->getFile();
	}
	fs->closeFile(f);
	if (dynamic_cast<DirectoryFile*>(f) != nullptr) {
		cout << "Invalid: this is a directory"<<endl;
		return AbstractFile::wrongtype;
	}
	
	if (iss >> w2) {
		//append
		if (w2 == "-a") {
			cout << fullPath;
			ReadFileVisitor reader;
			f->accept(&reader);
			string w3;
			vector<char> cont;
			while (getline(cin, w3)) {
				if (w3 == ":q") {
					return success;
				}
				if (w3 == ":wq") {
					return f->append(cont);
				}
				
				//cont.push_back('\n');
				for (int i = 0; i < w3.size(); ++i) {
					cont.push_back(w3[i]);
				}
			}
		}
		cout << "wrong arguments!" << endl;
		return AbstractCommand::invalidcommand;
	}
	string w3;
	vector<char> cont;
	while (getline(cin, w3)) {
		if (w3 == ":q") {
			return success;
		}
		if (w3 == ":wq") {
			return f->write(cont);
		}
		//start a new line
		if (dynamic_cast<TextFile*>(f) != nullptr) {
			cont.push_back('\n');
		}
		if (w3!=" ") {
			for (int i = 0; i < w3.size(); ++i) {
				cont.push_back(w3[i]);
			}
		}
	}
}

void CATCommand::displayInfo() {
	cout << "cat allows the user to edit the contents of the file" << endl;
	cout << "Usage: cat <filename> [-a]" << endl;
}
