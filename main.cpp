#include <iostream>
#include <algorithm>
#include <dirent.h>
#include <sys/wait.h>
#include <set>
#include <fcntl.h>
#include <Constructor.h>
#include <memory>
#include <netdb.h>
#include <values.h>
//#include "apueLearn.h"
//#include "unpLearn.h"
#include "ghlib/gh.h"
#include "SwordToOffer/Interview.h"
#include "apue.h"
#include "LeetCode.h"
using namespace std;
using namespace swordToOffer;


string cheng(string &str, int num) {
    string res;
    int shiwei = 0;
    for (int i = 0; i < str.size(); ++i) {
        int re = num * (str[i] - '0');
        shiwei = re / 10;
        res += (re % 10) + '0';
    }
}
int main(int argc, char* argv[]) {
    string sy = "12345";
    string str = cheng(sy, 5);
    return 0;
}


//889##24##7##7## 89##2##  1248##9##50##1##362##3##74##5##
