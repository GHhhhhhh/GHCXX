#include <iostream>
#include <algorithm>
#include <dirent.h>
#include <set>
#include "apueLearn.h"
#include "unpLearn.h"
#include "ghlib/gh.h"
#include "SwordToOffer/Interview.h"
using namespace std;
using namespace swordToOffer;

int main(int argc, char* argv[]) {
    std::multiset<int, greater<>> multiset1;
    std::vector<int> data;
    for (int i = 0; i < 100; ++i) {
        data.emplace_back(i);
    }
    GetLeastNumbers(data, multiset1, 4);
    for (auto i: multiset1)
        gh::print(i);




}

//889##24##7##7## 89##2##  1248##9##50##1##362##3##74##5##

