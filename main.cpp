#include <iostream>
#include <algorithm>
#include <dirent.h>
#include <thread>
#include <cstring>
#include <values.h>
#include "apueLearn.h"
#include "unpLearn.h"
#include <unordered_map>
#include "ghlib/gh.h"
#include "SwordToOffer/Interview.h"
using namespace std;
using namespace swordToOffer;


int main(int argc, char* argv[], char** envp) {

}

//889##24##7##7## 89##2##
//
//[1  3  -1] -3  5  3  6  7       3
//1 [3  -1  -3] 5  3  6  7       3
//1  3 [-1  -3  5] 3  6  7       5
//1  3  -1 [-3  5  3] 6  7       5
//1  3  -1  -3 [5  3  6] 7       6
//1  3  -1  -3  5 [3  6  7]      7