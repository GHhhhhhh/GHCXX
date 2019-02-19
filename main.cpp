#include <iostream>
#include <algorithm>
#include <dirent.h>
#include "apueLearn.h"
#include "unpLearn.h"
#include "ghlib/gh.h"
#include "SwordToOffer/Interview.h"
using namespace std;
using namespace swordToOffer;

int main(int argc, char* argv[]) {
   StackMin <int>stackMin;
   stackMin.push(5);
   stackMin.push(2);
   stackMin.push(6);
   stackMin.push(1);

   gh::print(stackMin.top());
   gh::print(stackMin.min());
   stackMin.pop();
   gh::print(stackMin.top());
   gh::print(stackMin.min());
   stackMin.pop();
   gh::print(stackMin.top());
   gh::print(stackMin.min());
   stackMin.pop();
   gh::print(stackMin.top());
   gh::print(stackMin.min());
}

//889##24##7##7## 89##2##