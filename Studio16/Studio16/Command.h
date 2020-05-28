#pragma once
#include "HierarchicalFilesystem.h"
class AbstractCommand {
public:
	virtual ~AbstractCommand() = default;
	virtual int execute(std::string, std::string) = 0;
	virtual void displayInfo()=0;
};