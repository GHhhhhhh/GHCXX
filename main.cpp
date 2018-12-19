#include <iostream>
#include <algorithm>
#include "ghlib/gh.h"
#include "SwordToOffer/Interview.h"
using namespace std;
using namespace swordToOffer;
int main() {
//    int a[10] = {2,3,4,5,6,7,8,9,0,1};
//    QuickSort(a,10,0,9);
//    Partition(a,10,0,9);
//    for (int i = 0; i < 10; ++i) {
//        cout<<a[i]<<" ";
//    }
//    int age[10] = {6,7,9,11,15,32,65,45,0,12};
    int numbers[5] = {1,0,1,1,1};
    int numbers2[5] = {1,1,1,0,1};
//    int numbers[10] = {6,7,8,9,1,2,3,4,5,6};
//    sortAges(age, 10);
    gh::print(Min(numbers,5));
//    for (int i = 0; i < 10; ++i) {
//        cout<<age[i]<<" ";
//    }
    return 0;
}

