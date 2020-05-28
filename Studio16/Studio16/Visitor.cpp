#include "Directory.h"
void BasicDisplayVisitor::visit_Image(ImageFile* a) {
	int size = a->getSize();
	vector<char> contents = a->read();
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			int index = i * size + j;
			cout << contents[index];
		}
		cout << endl;
	}
}
void BasicDisplayVisitor::visit_Text(TextFile* a) {
	vector<char> contents = a->read();
	for (unsigned int i = 0; i < contents.size(); ++i) {
		cout << contents[i];
	}
	cout << endl;
}
void BasicDisplayVisitor::visit_Directory(DirectoryFile* a) {
	cout << "name:" << a->getName() << endl;
	cout << "size:" << a->getSize() << endl;
	cout << "type: directory" << endl;
}

