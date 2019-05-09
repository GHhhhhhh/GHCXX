#include <iostream>
#include <algorithm>
#include <dirent.h>
#include <sys/wait.h>
#include <set>
#include <fcntl.h>
//#include "apueLearn.h"
//#include "unpLearn.h"
#include "ghlib/gh.h"
#include "SwordToOffer/Interview.h"
#include "apue.h"
using namespace std;
using namespace swordToOffer;


int main(int argc, char* argv[]) {
    std::string str = "abcdefg";
    LeftRotateString(str, 2);
    gh::print(str);
    return 0;

}


//889##24##7##7## 89##2##  1248##9##50##1##362##3##74##5##
