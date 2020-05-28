#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
enum results { success, failure, no_file_name , wrong_number_arguments};
int read(vector <string>& a, char* b);
int message(char* c);
bool isNumber(string k);
