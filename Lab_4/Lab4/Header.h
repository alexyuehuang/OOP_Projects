#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <istream>
#include <vector>
using namespace std;
enum basic { programname = 0, gameName = 1, correctNumInput = 2, extraCreditFirst = 2, extraCreditSecond = 3, correctNumInputExtraCredit = 3, correctNumInputExtraArgument = 4, smallestdimension = 3, gomokudimension = 19};
enum sf { success = 0, fail = 1, quit = 2, tie = 3, needInput = 4, wrongInput = 5, notValidMove = 6, notMatchAutoPlayer = 7 };
