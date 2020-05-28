#pragma once
#include <iostream>
#include <sstream>
#include "AbstractCommand.h"

using namespace std;
class CPCommand : public AbstractCommand {
public:
	CPCommand(AbstractFileSystem* fileSys);
	virtual int execute(std::string& CWD, std::string options) override;
	virtual void displayInfo() override;
	virtual ~CPCommand() = default;
private:
	AbstractFileSystem* fs;
};
