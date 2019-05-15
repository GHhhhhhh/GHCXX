#include <iostream>
#include <algorithm>
#include <dirent.h>
#include <sys/wait.h>
#include <set>
#include <fcntl.h>
#include <Constructor.h>
#include <memory>
//#include "apueLearn.h"
//#include "unpLearn.h"
#include "ghlib/gh.h"
#include "SwordToOffer/Interview.h"
#include "apue.h"
using namespace std;
using namespace swordToOffer;

class A {
public:
    ~A() {gh::print("A");}
};

class B:public A{
public:
    ~B(){ gh::print("B"); }
};

int firstMissingPositive(vector<int>& nums) {
    int k = 1;
    for (auto &i : nums) {
        if (i <= 0)
            continue;
        else {
            k = i >= k ? i - 1 : k + 1;
        }
    }
    return k;
}


int main(int argc, char* argv[]) {
    vector<int> candidates = {3,4,-1,1};
    gh::print(firstMissingPositive(candidates));
    return 0;
}


//889##24##7##7## 89##2##  1248##9##50##1##362##3##74##5##
