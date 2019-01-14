#include <iostream>
#include <algorithm>
#include "ghlib/gh.h"
#include "SwordToOffer/Interview.h"
using namespace std;
using namespace swordToOffer;
int main() {
    int a[6] = {1,2,3,4,5,6};
    RecorderOddEven(a, 6);
    for (int i : a)
        gh::print(i);

    return 0;
}

