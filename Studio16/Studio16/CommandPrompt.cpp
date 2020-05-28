#include "CommandPrompt.h"
void CommandPrompt::listCommands() {
	for (auto it = theMap.begin(); it != theMap.end(); ++it) {
		cout << it->first << endl;
	}
}
string CommandPrompt::prompt() {
	cout << "please enter a command:" << endl;
	string i;
	getline(cin, i);
	cout << currentDir << '$' << endl;
	return i;
}
CommandPrompt::CommandPrompt() {
	currentDir = "root";
	fileSystem = nullptr;
	fileFactory = nullptr;
}
void CommandPrompt::setFileSystem(AbstractFileSystem* a) {
	fileSystem = a;
}
void CommandPrompt::setFileFactory(AbstractFileFactory* a) {
	fileFactory = a;
}
int CommandPrompt::addCommand(std::string b, AbstractCommand* a) {
	return theMap.insert(pair<string, AbstractCommand*>(b, a)).second;
}
int CommandPrompt::run() {
	while (1) {
		string str = prompt();
		if (str== "q") {
			cout << "quitted" << endl;
			return 1;
		}
		if (str == "help") {
			cout << "help requested" << endl;
			listCommands();
		}
		else if (str.find(' ') == string::npos) {
			int k = 0;
			for (auto it = theMap.begin(); it != theMap.end(); ++it) {
				if (it->first == str) {
					try {
						it->second->execute(currentDir, "");
					}
					catch (...) {
						cout << "command failed" << endl;
						
					}
					k = 1;
				}
			}
			if (k == 0) {
				cout << "command not exist" << endl;
			}
		}
		if (str.find(' ') != string::npos) {
			istringstream iss(str);
			string w1, w2;
			iss >> w1;
			if (w1 == "help") {
				iss >> w2;
				int k = 0;
				for (auto it = theMap.begin(); it != theMap.end(); ++it) {
					if (it->first == w2) {
						k = 1;
						it->second->displayInfo();
					}
				}
				if (k == 0) {
					cout << "no command found" << endl;
				}
			}
			else {
				int k = 0;
				for (auto it = theMap.begin(); it != theMap.end(); ++it) {
					if (it->first == w1) {
						string w3;
						while (iss >> w2) {
							w3 += w2;
							try {
								it->second->execute(currentDir, w3);
							}
							catch (...) {
								cout << "command returned error" << endl;
							}
							k = 1;
						}
					}
				}
				if (k == 0) {
					cout << "no command found" << endl;
				}
			}
		}
	}
}
TouchCommand::TouchCommand(AbstractFileSystem* a, AbstractFileFactory* b) {
	fileSystem = a;
	fileFactory = b;
}
int TouchCommand::execute(std::string a, std::string b) {
	AbstractFile* ptr= fileFactory->createFile(b);
	if (ptr == nullptr) {
		throw 1;
	}
	string str = a + "/" + b;
	if (fileSystem->addFile(str, ptr)==1) {
		delete ptr;
		return 1;
	}
	return 0;
}
void TouchCommand::displayInfo() {
	cout << "touch creates a file, touch can be invoked with the command : touch <filename>"<< endl;
}