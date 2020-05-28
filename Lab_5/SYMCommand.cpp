#include "SYMCommand.h"
#include"DirectoryFile.h"
#include"AbstractFile.h"

#include"Proxy.h"
SYMCommand::SYMCommand(AbstractFileSystem* fileSys) : fs(fileSys) {
	cout << "debug";
}

int SYMCommand::execute(std::string& CWD, std::string options) {
	string fullPath = CWD;
	fullPath += '/';
	istringstream iss(options);
	string w1, w2;
	iss >> w1;
	if (!(iss >> w2)) {
		cout << "wrong argument";
		return 1;
	}
	fullPath += w1;
	AbstractFile* f = fs->openFile(fullPath);
	fs->closeFile(f);
	if (f == nullptr) {
		cout << "invalid file!";
		return 2;
	}
	if (dynamic_cast<DirectoryFile*>(f) != nullptr) {
		cout << "invalid file!";
		return 2;
	}
	Proxy* prox= dynamic_cast<Proxy*>(f);
	if (dynamic_cast<Proxy*>(f) != nullptr) {
		AbstractFile* pro = new Proxy(dynamic_cast<Proxy*>(f));
		
		w2 += '/';
		fs->addFile(w2, pro);
	}
	else {
		AbstractFile* pro = new Proxy(f);
		AbstractFile* added = new Proxy(dynamic_cast<Proxy*>(pro));
		w2 += '/';
		fs->addFile(w2, added);
	}
	return success;
}




void SYMCommand::displayInfo() {
	cout << "sym create symbolic link and add to file system" << endl;
	cout << "Usage: sym <filename> <full path to destination>" << endl;
}
