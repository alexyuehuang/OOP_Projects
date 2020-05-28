#pragma once
#include "AbstractFile.h"
class TextFile : public AbstractFile {
private:
	vector<char> contents;
	AbstractFile* parent=nullptr;
	string name;
public:
	TextFile(string b);
	virtual vector<char> read() ;
	virtual int write(vector<char> a);
	virtual int append(vector<char> a) ;
	virtual unsigned int getSize() ;
	virtual string getName();
	virtual void accept(AbstractFileVisitor* a);
	virtual int addChild(AbstractFile* a) ;
	virtual int removeChild(string a) ;
	virtual AbstractFile* getChild(string a) ;
	virtual void setParent(AbstractFile* a);
	virtual AbstractFile* getParent() ;
};
