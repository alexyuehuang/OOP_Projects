#include"DSCommand.h"
#include<iostream>
#include<sstream>
#include"ImageFile.h"
#include"Proxy.h"
#include"TextFile.h"
#include"AbstractFileSystem.h"
#include "AbstractCommand.h"
#include <cmath>
#include "DirectoryFile.h"
using namespace std;

DSCommand::DSCommand(AbstractFileSystem* fileSys) : fs(fileSys) {}

int DSCommand::execute(std::string& CWD, std::string options) {
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
	vector<char> cont = f->read();
	if (iss >> w2) {
		if (w2 != "-d") {
			cout << "Invalid: wrong command" << endl;
			return AbstractCommand::invalidcommand;
		}
		if ((dynamic_cast<ImageFile*>(f)) != nullptr) {
			for (int i = 0; i < cont.size() ; ++i) {
				cout << cont[i];
			}
		}
		if ((dynamic_cast<TextFile*>(f)) != nullptr) {
			for (int i = 0; i < cont.size(); ++i) {
				if (cont[i] != '/n') {
					cout << cont[i];
				}
			}
		}
		if ((dynamic_cast<DirectoryFile*>(f)) != nullptr) {
			for (int i = 0; i < cont.size(); ++i) {
				cout << cont[i];
			}
		}
		cout << endl;
		return success;
	}
	if ((dynamic_cast<ImageFile*>(f)) != nullptr) {
		int k = sqrt(cont.size() );
		
		for (int i = 0; i < k; ++i) {			
			for (int j = 0; j < k; ++j) {			
				int g = k * i + j;
				cout << cont[g];
			}
			cout << endl;
		}
	}
	if ((dynamic_cast<TextFile*>(f)) != nullptr) {
		for (int i = 0; i < cont.size(); ++i) {
			cout << cont[i];
		}
	}
	if ((dynamic_cast<DirectoryFile*>(f)) != nullptr) {
		for (int i = 0; i < cont.size(); ++i) {
			cout << cont[i];
		}
	}
	cout << endl;
	return success;
}
void DSCommand::displayInfo() {
	cout << "ds displays the content of that file" << endl;
	cout << "Usage: ds <filename> [-d]" << endl;
}