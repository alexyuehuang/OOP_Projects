Student Name: Alice Wang, Alex Huang, Xuyan Qin

Test Cases:
//create a new directory
//create a new file
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ touch a
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ touch zz.txt
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ touch image.img
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ls
a
zz.txt
image.img

//try adding same name file
root $ touch image.img
File Already Exists!
failed to add file to file system, deleting file

//cat command: read & write - append (txt file)
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cat zz.txt -a
root/zz.txt
Hello World!
:wq
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ds zz.txt
Hello World!


//cat command: read and write (img file)
root $ cat image.img
X X X X X3
:wq
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ds image.img
X X
 X
X X

//make sym link
root $ sym zz.txt root/a
root $ cd a
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/a $ ls
zz.txt

//ensure that editing one sym of file updates it 
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/a $ cat zz.txt -a
root/a/zz.txtHello World!
Hello there, General Kenobi!
:wq
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/a $ cd ..
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ds zz.txt
Hello World!Hello there, General Kenobi!

//remove file and directory
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ rm image.img
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ rm zz.txt


//quit
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ q

H:\Lab5\x64\Debug>