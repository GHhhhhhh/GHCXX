#include <iostream>
#include <algorithm>
#include "ghlib/gh.h"
#include "SwordToOffer/Interview.h"
using namespace std;
int main() {
    int *a;
    int b[10] = {0,1,2,3,4,5,6,7,8,9};
    a = b;
    a++;
    gh::print(a[2]);
    gh::print("hello guest! I am iron man!");
    return 0;
}

