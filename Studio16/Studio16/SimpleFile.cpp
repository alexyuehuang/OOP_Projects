#include "Directory.h"

int SimpleFileSystem::addFile(string a, AbstractFile* b) {
	map<string, AbstractFile*>::iterator it = myMap.find(a);
	if (it != myMap.end()) {
		return 1;
	}
	if (b == nullptr) {
		return 2;
	}
	myMap.insert({a, b});
	
	return 0;
}
int SimpleFileSystem::deleteFile(string a) {
	map<string, AbstractFile*>::iterator it = myMap.find(a);
	if (it == myMap.end()) {
		return 1;
	}
	set<AbstractFile* >::iterator it2 = open.find((*it).second);
	if (it2 != open.end()) {
		return 2;
	}
	AbstractFile* g = (*it).second;
	myMap.erase(a);
	delete g;
	return 0;
}
AbstractFile* SimpleFileSystem::openFile(string a) {
	map<string, AbstractFile*>::iterator it = myMap.find(a);
	if (it != myMap.end()) {
		set<AbstractFile* >::iterator it2 = open.find((*it).second);
		if (it2 != open.end()) {
			return (*it).second;
		}
	}
	return nullptr;
}
int SimpleFileSystem::closeFile(AbstractFile* a) {
	set<AbstractFile* >::iterator it2 = open.find(a);
	if (it2 != open.end()) {
		open.erase(a);
		return 0;
	}
	return 1;
}
AbstractFile* SimpleFileFactory::createFile(string a) {
	string b = a.substr(a.length() - 3, 3);
	if (b == "txt") {
		TextFile* k = new TextFile(a);
		return k;
	}
	if (b == "img") {
		ImageFile* k = new ImageFile(a);
		return k;
	}
	return nullptr;
}
AbstractFile* HierarchicalFileFactory::createFile(string a) {
	for (unsigned int i = 0; i < a.size(); ++i) {
		if (a[i] == '.') {
			SimpleFileFactory b;
			return b.createFile(a);
		}
	}
	return new DirectoryFile(a);
}