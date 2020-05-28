#pragma once
#include "Command.h"
class CommandPrompt  {
private:
	map<string, AbstractCommand*> theMap;
	string currentDir;
	AbstractFileSystem* fileSystem;
	AbstractFileFactory* fileFactory;
	void listCommands();
	string prompt();
public:
	CommandPrompt();
	~CommandPrompt()=default;
	void setFileSystem(AbstractFileSystem* a);
	void setFileFactory(AbstractFileFactory* a);
	int addCommand(std::string b, AbstractCommand* a);
	int run();
};
class TouchCommand :public AbstractCommand {
private:
	AbstractFileSystem* fileSystem;
	AbstractFileFactory* fileFactory;
public:
	TouchCommand(AbstractFileSystem* a,  AbstractFileFactory* b);
	~TouchCommand() = default;
	virtual int execute(std::string a, std::string b) ;
	virtual void displayInfo() ;
};