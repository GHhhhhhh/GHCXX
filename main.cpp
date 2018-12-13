#include <iostream>
#include <algorithm>
#include "ghlib/gh.h"
#include "SwordToOffer/Interview.h"
using namespace std;
using namespace swordToOffer;
int main() {
    int a[10] = {2,3,4,5,6,7,8,9,0,1};
    QuickSort(a,10,0,10);
    for (int i = 0; i < 10; ++i) {
        gh::print(i);
    }
    return 0;
}

