Studio 16
1. Alex Huang, Xiaowen Ma
2. a. Design a class, declearing a bunch of functions and make them virtual, =0 and public
3. a. example of interface inheritance
b. private, we don't want other classes to freely access that
4. the functions work well. I imputed the classes a name and wrote a vector to it. It then is able to read it successfully
Furthermore, I can append a vector to it. I also tried to print the size and name, and it worked.
5. Instead of declearing TextFile, I declear a pointer to AbstractFile. 
It will detect the actual class in run time. This solution works well. 


Studio 17
1. Same
2. I tested by creating a vector of chars and wrote it into the ImageFile variable I initialized;
Then I print it out, and prints out the output of getName(); It worked perfectly. 
3. It is easy to include a lot of implementations and use different implementations different times
4. Not very hard, but need to change createfile, but most others do not change

Studio 18
1. same
2. The factory method allows me to define and override the create function each time I have a new derived class, which
is great for polymorphism. Also, there are code dependencies between a concrete file system class 
and the concrete file classes it creates objects of, as mentioned in description. 
3. Advantage: the filesystem will no longer need to be in charge of creating the file, making the system easier to read and understand
DisAdvantage: a lot more codes, which might be redundant at some point. 
If new file type, only modify this method(createfile)
4. I tested to add, open, delete and close files. They worked well. I also tried to print out stuffs. 

Studio 19
1. same
2. I tried creating a few file classes and print the output of read() funciton. It worked well. 
3. When you call accept, the respetive visit function is called and the input v was put in. The visitor provides 
a kind of interface for us to visit, and the interface is not related to the class itself. 
4. delegation in this case means outsourcing the old read method to the Visitor class. 
5. We need to change all the functions in the Visitor.h. It will take a lot of work if we have a lot of visitors.

Studio 20
1. same
2. No question for this one
3. Both Imagefile and Textfile has the same definition for those functions, it makes sense to make a class to 
define those functions, like directoryfile. 
4. We need to modify visitor file, but other than that not a lot is needed. I don't think we need new files apart 
from direcotryfile
5. I created a simple directory and tried to open, close, delete and retrive files a couple times. It worked. 

Studio 21
1. same
2. It doesn't return error, just returns 1;
3. a. should use visitors, since file types are fixed and we can construct the visitors one by one
b. should not, since we need to change our visitors with each new file type. 
4. The advantage of this implementation is that we don't need to have previous information on the several classes
like the file system. We don't need to know the exact file types and the exact implementation. Therefore, 
we can reuse the code on other file systems. 
5. I ran the file and tried to create, or type help, or quit the command system. It worked well in all the cases. 