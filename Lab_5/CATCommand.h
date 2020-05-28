#pragma once
#include "AbstractCommand.h"
#include "DirectoryFile.h"
#include<string>


class CATCommand : public AbstractCommand {
public:
	CATCommand(AbstractFileSystem* filesys);
	virtual int execute(std::string& CWD, std::string options) override;
	virtual void displayInfo() override;
	virtual ~CATCommand() = default;
private:
	AbstractFileSystem* fs;
};