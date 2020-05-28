#include "Proxy.h"
#include <iostream>
using namespace std;

Proxy::Proxy(AbstractFile* a) : name(a->getName()), contents(a->read()),parent(a->getParent()), file(a), count(new int(1)) {
	parent->removeChild(a->getName());
	parent->addChild(this);
	a->setParent(nullptr);

}

Proxy::Proxy(Proxy* a):name(a->name),contents(a->contents),parent(nullptr),children(a->children),file(a->file),count(a->count) {
	(*count)++;
}

Proxy::~Proxy() {
	if ((*count) == 1) {
		delete file;
		delete count;
	}
	else {
		(*count)--;
	}
}

AbstractFile* Proxy::getFile() {
	return file;
}
int* Proxy::getInt() {
	return count;
}

std::vector<char> Proxy::read() {
	return file->read();
}
int Proxy::write(std::vector<char> a) {
	return file->write(a);
}
int Proxy::append(std::vector<char> a) {
	return file->append(a);
}
unsigned int Proxy::getSize() {
	return file->getSize();
}
std::string Proxy::getName() {
	return file->getName();
}
void Proxy::accept(AbstractFileVisitor* a) {
	file->accept(a);
}
AbstractFile* Proxy::clone() {
	Proxy *copy = new Proxy(*this);
	count++;
	return copy;
}

int Proxy::addChild(AbstractFile* a) {
	return notacomposite;
}
int Proxy::removeChild(std::string name) {
	return notacomposite;
}
void Proxy::setParent(AbstractFile* a) {
	parent = a;
}
AbstractFile* Proxy::getChild(std::string name) {
	return nullptr;
}
AbstractFile* Proxy::getParent() {
	return parent;
}