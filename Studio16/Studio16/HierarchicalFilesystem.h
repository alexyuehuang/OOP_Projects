#pragma once
#include "Directory.h"
class HierarchicalFileSystem :public AbstractFileSystem {
private:
	DirectoryFile* root;
	set<AbstractFile*> openFiles;
	AbstractFile* parsePath(string a);
public:
	HierarchicalFileSystem();
	~HierarchicalFileSystem();
	virtual int addFile(string a, AbstractFile* b) ;
	virtual int deleteFile(string a) ;
	virtual AbstractFile* openFile(string a) ;
	virtual int closeFile(AbstractFile* a) ;
};