#pragma once
#include "SimpleFile.h"
class DirectoryFile;
class AbstractFileVisitor {
public:
	virtual void visit_Image(ImageFile*) = 0;
	virtual void visit_Text(TextFile*) = 0;
	virtual void visit_Directory(DirectoryFile*) = 0;
};
class BasicDisplayVisitor : public AbstractFileVisitor {
	virtual void visit_Image(ImageFile* a) ;
	virtual void visit_Text(TextFile* a);
	virtual void visit_Directory(DirectoryFile* a);
};