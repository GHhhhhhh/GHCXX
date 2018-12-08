#include <iostream>
#include <algorithm>
#include "ghlib/gh.h"
#include "SwordToOffer/Interview.h"
using namespace std;
using namespace swordToOffer;
int main() {
    CQueue<int> cQueue;
    Cstack<int> cstack;
    cstack.push(1);
    cstack.push(2);
    cstack.push(3);
    gh::print(cstack.pop());
    gh::print(cstack.pop());
    gh::print(cstack.pop());
    return 0;
}

