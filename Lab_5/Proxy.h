#pragma once
#include"AbstractCommand.h"
#include"AbstractFile.h"
#include "TextFile.h"
#include "ImageFile.h"
#include"DirectoryFile.h"
#include "Abstractfile.h"
class Proxy:public AbstractFile {
public:
	Proxy(AbstractFile* a);
	Proxy(Proxy* a);
	~Proxy();
	friend class SimpleFileSystem;
	friend class HierarchicalFileSystem;
	virtual std::vector<char> read() override;
	virtual int write(std::vector<char>) override;
	virtual int append(std::vector<char>) override;
	virtual unsigned int getSize() override;
	virtual std::string getName() override;
	virtual void accept(AbstractFileVisitor*) override;
	AbstractFile* clone();
	AbstractFile* getFile();
	int* getInt();
	virtual AbstractFile* getParent() override;

protected:
	virtual int addChild(AbstractFile*) override;
	virtual int removeChild(std::string name) override;
	virtual void setParent(AbstractFile*) override;
	virtual AbstractFile* getChild(std::string name) override;

private:
	std::string name;
	std::vector<char> contents;
	AbstractFile* parent;
	std::map<std::string, AbstractFile*> children;
	AbstractFile* file;
	int* count;
};