#pragma once
#include "TextFile.h"
enum outcomes { success, sizewrong, charwrong, notsupported };
class ImageFile : public AbstractFile {
private:
	vector<char> contents;
	string name;
	AbstractFile* parent=nullptr;
	char size;
public:
	ImageFile(string b);
	virtual unsigned int getSize();
	virtual string getName();
	virtual vector<char> read();
	virtual int write(vector<char> a);
	virtual int append(vector<char> a);
	virtual void accept(AbstractFileVisitor* a);
	virtual int addChild(AbstractFile* a);
	virtual int removeChild(string a);
	virtual AbstractFile* getChild(string a);
	virtual void setParent(AbstractFile* a);
	virtual AbstractFile* getParent();
};