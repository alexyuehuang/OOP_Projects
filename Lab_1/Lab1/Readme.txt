Alex Huang 465329 Lab1 
1. Eventually I don't have any warnings, but in the process I had several null pointer errors
2. I ran the test with input: program name and test.txt, the latter of which contains a bunch of strings mixed with number, 
and it printed all the values, first string then int
I also rant the test with input three strings, and it return the usage message.

Extra credit
ec1 
[alex.huang@shell ~]$ ls
CSE 332  Desktop  Downloads  Music  My Documents  perl5  Pictures  Public  Templates  Videos  WINDOWS  winprofile
ec2 
encountered warnings on comparison between signed and unsigned integer expressions:
[alex.huang@linuxlab007 Lab1]$ make
g++ -o Lab1 -DUNIX   -Wall -W -g -pedantic Lab1.cpp -lnsl
Lab1.cpp: In function ‘int main(int, char**)’:
Lab1.cpp:26:29: warning: comparison between signed and unsigned integer expressions [-Wsign-compare]
  for (int i = 0; i < a.size(); ++i) {
                             ^
Lab1.cpp:39:36: warning: comparison between signed and unsigned integer expressions [-Wsign-compare]
  for (int i = 0; i < integers.size(); ++i) {
                                    ^
Lab1.cpp: In function ‘bool isNumber(std::string)’:
Lab1.cpp:47:31: warning: comparison between signed and unsigned integer expressions [-Wsign-compare]
  for (int i = 0; i < k.length(); ++i) {

In the end, I tested my program on linux and it successfully read my readme file and printed all the values, first string then also numbers. 
