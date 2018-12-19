#include <iostream>
#include <algorithm>
#include "ghlib/gh.h"
#include "SwordToOffer/Interview.h"
using namespace std;
using namespace swordToOffer;
int main() {
    char matrix[12] = {'a','b','t','g','c','f','c','s','j','d','e','h'};
    gh::print(hasPath(matrix, 3,4,"bfce"));
    gh::print(hasPath(matrix, 3,4,"abfb"));
    return 0;
}

