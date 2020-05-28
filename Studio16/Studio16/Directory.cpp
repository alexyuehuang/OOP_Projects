#include "Directory.h"

DirectoryFile::DirectoryFile(string a) :name(a), parent(nullptr){
}
DirectoryFile::~DirectoryFile() {
	for (std::map<string, AbstractFile*>::iterator it = children.begin(); it != children.end(); ++it) {
		delete it->second;
	}
}
vector<char> DirectoryFile::read() {
	return contents;
}
int DirectoryFile::write(vector<char> a) {
	return 1;
}
int DirectoryFile::append(vector<char> a) {
	 return 1;
}
unsigned int DirectoryFile::getSize() {
	return contents.size();
}
string DirectoryFile::getName() {
	return name;
}
void DirectoryFile::accept(AbstractFileVisitor* a) {
	if (a) { a->visit_Directory(this); };
}
int DirectoryFile::addChild(AbstractFile* a) {
	for (std::map<string, AbstractFile*>::iterator it = children.begin(); it != children.end(); ++it) {
		if (it->second == a) {
			return 1;
		 }
	}
	string nameThis = a->getName();
	children.insert(std::pair<string, AbstractFile*>(nameThis, a));
	for (unsigned int i = 0; i < nameThis.size(); ++i) {
		contents.push_back(nameThis[i]);
	}
	contents.push_back('\n');
	return 0;
}
int DirectoryFile::removeChild(string a) {
	for (std::map<string, AbstractFile*>::iterator it = children.begin(); it != children.end(); ++it) {
		if (it->first == a) {
			string c;
			for (unsigned int i = 0; i < contents.size(); ++i) {
				c+= contents[i];
			}
			istringstream iss (c);
			contents.clear();
			string b;
			while (iss >> b) {
				if (b != a) {
					for (unsigned int i = 0; i < b.size(); ++i) {
						contents.push_back(b[i]);
					}
					contents.push_back('\n');
				}
			}
			return 0;
		}
	}
	
	return 1;
}
AbstractFile* DirectoryFile::getChild(string a) {
	for (std::map<string, AbstractFile*>::iterator it = children.begin(); it != children.end(); ++it) {
		if (it->first == a) {
			return it->second;
		}
	}
	return nullptr;
}
void DirectoryFile::setParent(AbstractFile* a) {
	parent = a;
}
AbstractFile* DirectoryFile::getParent() {
	return parent;
}