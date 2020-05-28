#include "ImageFile.h"
#include "Visitor.h"
int ImageFile::addChild(AbstractFile* a) {
	return 1;
}
int ImageFile::removeChild(string a) {
	return 1;
}
AbstractFile* ImageFile::getChild(string a) {
	return nullptr;
}
void ImageFile::setParent(AbstractFile* a) {
	parent = a;
}
AbstractFile* ImageFile::getParent() {
	return parent;
}
ImageFile::ImageFile(string b) :name(b), size(0) {
	parent = nullptr;
}
unsigned int ImageFile::getSize() {
	return size;
}
string ImageFile::getName() {
	return name;
}
int ImageFile::write(vector<char> a) {
	if (a.size()==0) {
		return sizewrong;
	}
	int b = (int)a[a.size() - 1];
	a.pop_back();
	if ((a.size()) != b * b) {
		return sizewrong;
	}
	vector<char> c;
	for (unsigned int i = 0; i < a.size(); ++i) {
		if (a[i] == ' ' || a[i] == 'X') {
			c.push_back(a[i]);
		}
		else {
			size = 0;
			return charwrong;
		}
	}
	size = b;
	contents = c;
	return success;
}
void ImageFile::accept(AbstractFileVisitor* a) {
	if (a) {a->visit_Image(this); };
}
int ImageFile:: append(vector<char> a) {
	return notsupported;
}
vector<char> ImageFile::read() {
	return contents;
}