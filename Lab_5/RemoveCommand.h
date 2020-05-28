/*
Author: Jon Shidal
Purpose: CSE 332 lab 5
*/
#pragma once
#include "AbstractCommand.h"
#include "DirectoryFile.h"
#include<string>


class RemoveCommand : public AbstractCommand {
public:
	RemoveCommand(AbstractFileSystem* filesys);
	virtual int execute(std::string& CWD, std::string options) override;
	virtual void displayInfo() override;
	virtual ~RemoveCommand() = default;
	int removeDirFile(DirectoryFile* dir, std::string path);
private: 
	AbstractFileSystem* fs;
};