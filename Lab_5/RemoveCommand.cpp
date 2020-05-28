/*
Author: Jon Shidal
Purpose: CSE 332 lab 5
*/

#include "RemoveCommand.h"
#include "AbstractFile.h"
#include "DirectoryFile.h"
#include "AbstractCommand.h"
#include<iostream>
#include<sstream>

using namespace std;

RemoveCommand::RemoveCommand(AbstractFileSystem* fileSys) : fs(fileSys) {}

// removes a file from the current working directory
int RemoveCommand::execute(std::string& CWD, std::string options) {
	string fullPath = CWD;
	fullPath += '/';
	istringstream iss(options);
	string w1, w2;
	iss >> w1;
	if (iss >> w2) {
		fullPath += w1;
		int result = fs->deleteFile(fullPath);
		if (result == AbstractFileSystem::filedoesnotexist) {
			cout << "File does not exist" << endl;
			return filedoesnotexist;
		}
		else if (result == AbstractFileSystem::fileisopen) {
			cout << "File is currently in use" << endl;
			return fileinuse;
		}
		else if (result == AbstractFileSystem::dirfilenotempty&& w2=="-r") {
			DirectoryFile* thisDir = dynamic_cast<DirectoryFile*> (fs->openFile(fullPath));
			return removeDirFile(thisDir, fullPath);
		}
		return success;
	}
	else {
		fullPath += options;
		int result = fs->deleteFile(fullPath);
		if (result == AbstractFileSystem::filedoesnotexist) {
			cout << "File does not exist" << endl;
			return filedoesnotexist;
		}
		else if (result == AbstractFileSystem::fileisopen) {
			cout << "File is currently in use" << endl;
			return fileinuse;
		}
		return success;
	}
}

int RemoveCommand::removeDirFile(DirectoryFile* dir, string path) {
	vector<char> cont = dir->read();
	string contentstr;
	for (int i = 0; i < cont.size(); ++i) {
		contentstr += cont[i];
	}
	istringstream iss(contentstr);
	vector<string> newCont;
	string a;
	while (iss >> a) {
		newCont.push_back(a);
	}
	for (int i = 0; i < newCont.size(); ++i) {
		string place = path;
		place += "/";
		place += newCont[i];
		AbstractFile* anotherf = fs->openFile(place);
		fs->closeFile(anotherf);
		if (anotherf != nullptr) {
			if (dynamic_cast<DirectoryFile*>(anotherf)==nullptr) {
				int k = fs->deleteFile(place);
				if (k != 0) {
					return k;
				}
			}
			else {
				DirectoryFile* dirf = dynamic_cast<DirectoryFile*>(anotherf);
				cout << "size" << (anotherf->read()).size();
				if (anotherf->read().size() == 0) {
					int g = fs->deleteFile(place);
					cout << g;
					if (g != 0)
					{
						return g;
					}
				}
				else {
					int k = removeDirFile(dirf, place);
					if (k != 0) {
						return k;
					}
				}
			}
		}
	}
	fs->closeFile(dir);
	return fs->deleteFile(path);
}

void RemoveCommand::displayInfo() {
	cout << "touch removes a file from the file system and then deletes the file" << endl;
	cout << "Usage: rm <filename>" << endl;
}