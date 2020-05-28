#include "HierarchicalFilesystem.h"
HierarchicalFileSystem::HierarchicalFileSystem():root(new DirectoryFile("root")) {
	root->setParent(root);
}
HierarchicalFileSystem::~HierarchicalFileSystem() {
	delete root;
}
AbstractFile* HierarchicalFileSystem::parsePath(string a) {
	if (a == "root/") {
		return root;
	}
	AbstractFile* current = root;
	for (unsigned int i = 0; i < a.size(); ++i) {
		if (a[i] == '/') {
			a[i] = ' ';
		}
	}
	istringstream iss(a);
	string nextArg;
	iss >> nextArg;
	if (nextArg != "root") {
		return nullptr;
	}
	while (iss >> nextArg) {
		current = current->getChild(nextArg);
		if (current== nullptr) {
			return nullptr;
		}
	}
	return current;
}
int HierarchicalFileSystem::addFile(string a, AbstractFile* b) {
	string lastArg;
	string arg;
	int lastpos=0;
	for (int i = a.size() - 1; i >= 0; --i) {
		if (a[i] == '/') {
			lastpos = i;
			break;
		}
		lastArg += a[i];
	}
	reverse(lastArg.begin(), lastArg.end());
	for (int i = 0; i < lastpos; ++i) {
		arg += a[i];
	}
	AbstractFile* current = parsePath(arg);
	if (current == nullptr) {
		return 1;
	}
	if (!current->addChild(b)) {
		b->setParent(current);
		return 0;
	}
	return 1;
}
int HierarchicalFileSystem:: deleteFile(string a) {
	AbstractFile* current = parsePath(a);
	if (current == nullptr) {
		return 1;
	}
	for (set<AbstractFile* >::iterator it = openFiles.begin(); it != openFiles.end(); ++it) {
		if (*it == current) {
			return 1;
		}
	}
	if (current->getParent() == current) {
		return 1;
	}
	current->getParent()->removeChild(current->getName());
	return 0;
}
AbstractFile* HierarchicalFileSystem:: openFile(string a) {
	AbstractFile* current = parsePath(a);
	if (current != nullptr) {
		openFiles.insert(current);
	}
	return current;
}
int HierarchicalFileSystem::closeFile(AbstractFile* a) {
	for (set<AbstractFile* >::iterator it = openFiles.begin(); it != openFiles.end(); ++it) {
		if (*it == a) {
			openFiles.erase(a);
			return 0;
		}
	}
	return 1;
}