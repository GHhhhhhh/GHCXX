#include <iostream>
#include <algorithm>
#include "ghlib/gh.h"
#include "SwordToOffer/Interview.h"
using namespace std;
using namespace swordToOffer;
int main() {
    char *str = "aaa";
    char *pattern = "a.a";
    gh::print(match(str, pattern));
    return 0;
}

