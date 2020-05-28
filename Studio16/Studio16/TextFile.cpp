#include "Visitor.h"
int TextFile::addChild(AbstractFile* a) {
	return 1;
}
int TextFile::removeChild(string a) {
	return 1;
}
AbstractFile* TextFile::getChild(string a) {
	return nullptr;
}
void TextFile::setParent(AbstractFile* a) {
	parent = a;
}
AbstractFile* TextFile::getParent() {
	return parent;
}
TextFile:: TextFile(string b):name(b){
	parent = nullptr;
};
unsigned int TextFile::getSize() {
	return contents.size();
}
string TextFile::getName() {
	return name;
}
vector<char> TextFile:: read() {
	return contents;
}
void TextFile::accept(AbstractFileVisitor* a) {
	if (a) { a->visit_Text(this); };
}
int TextFile::append(vector<char> a) {
	for (unsigned int i = 0; i < a.size(); ++i) {
		contents.push_back(a[i]);
	}
	return 0;
}
int TextFile:: write(vector<char> a) {
	contents = a;
	return 0;
}