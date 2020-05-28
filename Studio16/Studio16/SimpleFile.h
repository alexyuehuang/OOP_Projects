#pragma once
#include "ImageFile.h"
#include <map>
#include <set>
class SimpleFileSystem : public AbstractFileSystem {
private:
	map<string, AbstractFile*> myMap;
	set<AbstractFile*> open;
public:
	int addFile(string a, AbstractFile* b) ;
	int deleteFile(string a);
	AbstractFile* openFile(string a);
	int closeFile(AbstractFile* a) ;
	~SimpleFileSystem() = default;
};
class AbstractFileFactory {
public:
	virtual AbstractFile* createFile(string a)=0;
};
class SimpleFileFactory:public AbstractFileFactory {
public:
	AbstractFile* createFile(string a);
};
class HierarchicalFileFactory :public AbstractFileFactory {
public:
	AbstractFile* createFile(string a);
};