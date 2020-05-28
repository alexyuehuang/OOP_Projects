#pragma once
#include "Visitor.h"

class HierarchicalFileSystem;
class DirectoryFile : public AbstractFile {
private:
	string name;
	vector<char > contents;
	AbstractFile* parent=nullptr;
	map<string, AbstractFile*> children;
public:
	DirectoryFile(string a);
	~DirectoryFile();
	virtual vector<char> read() ;
	virtual int write(vector<char> a) ;
	virtual int append(vector<char> a) ;
	virtual unsigned int getSize();
	virtual string getName();
	virtual void accept(AbstractFileVisitor*);
protected:
	virtual int addChild(AbstractFile* a);
	virtual int removeChild(string a);
	virtual AbstractFile* getChild(string a) ;
	virtual void setParent(AbstractFile* a) ;
	virtual AbstractFile* getParent() ;
	friend class HierarchicalFileSystem;
};