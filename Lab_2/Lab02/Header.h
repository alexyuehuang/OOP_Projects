//things to include
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//use standard namespace
using namespace std;
//resuts in a enum
enum results { success, failure, wrong_dimension,no_file_name, wrong_number_arguments, notExtract, noPiecestoRead, notRead, notOpen
};
enum colors {red, blue, BLUE, black, white, no_color, invalid};
enum values{programName, fileName, numofArguments};
//functions to use
int message(char* c, char* d);
colors toEnum(string c);
char toLower(char* c);

