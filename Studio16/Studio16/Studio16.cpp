// Studio16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CommandPrompt.h"
int main()
{
	vector<char> j;
	j.push_back(' ');
	j.push_back('X');
	j.push_back('X');
	vector<char> i;
	i.push_back('a');
	i.push_back('c');
	i.push_back('b');
	TextFile* a= new TextFile ("sd.txt");
	a->write(i);
	j.push_back('X');
	j.push_back(2);
	ImageFile b("sds.img");
	b.write(j);
	DirectoryFile* dir1 = new DirectoryFile("sd");
	HierarchicalFileFactory* hier = new HierarchicalFileFactory();
	HierarchicalFileSystem* sys = new HierarchicalFileSystem();
	TouchCommand* touch = new TouchCommand(sys, hier);
	CommandPrompt* command = new CommandPrompt();
	command->setFileFactory(hier);
	command->setFileSystem(sys);
	command->addCommand("touch", touch);
	cout<<command->run() << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
