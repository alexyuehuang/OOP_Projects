#pragma once
#include <iostream>
#include <sstream>
#include "AbstractCommand.h"
using namespace std;
class SYMCommand : public AbstractCommand {
public:
	SYMCommand(AbstractFileSystem* fileSys);
	virtual int execute(std::string& CWD, std::string options) override;
	virtual void displayInfo() override;
	virtual ~SYMCommand() = default;
private:
	AbstractFileSystem* fs;
};