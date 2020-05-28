#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
class AbstractFileVisitor;
class HierarchicalFileSystem;
using namespace std;
class AbstractFile {
public:
	virtual vector<char> read() = 0;
	virtual int write(vector<char> a) = 0;
	virtual int append(vector<char> a) = 0;
	virtual unsigned int getSize() = 0;
	virtual string getName() = 0;
	virtual ~AbstractFile() = default;
	virtual void accept(AbstractFileVisitor*) = 0;
protected:
	virtual int addChild(AbstractFile* a) = 0;
	virtual int removeChild(string a) = 0;
	virtual AbstractFile* getChild(string a) = 0;
	virtual void setParent(AbstractFile* a) = 0;
	virtual AbstractFile* getParent() = 0;
	friend class AbstractFileSystem;
	friend class HierarchicalFileSystem;
};
class AbstractFileSystem {
public:
	virtual int addFile(string a, AbstractFile *b) = 0;
	virtual int deleteFile(string a) = 0;
	virtual AbstractFile * openFile(string a) = 0;
	virtual int closeFile(AbstractFile * a) = 0;
};