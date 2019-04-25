#include <iostream>
#include <algorithm>
#include <dirent.h>
#include <sys/wait.h>
#include <set>
//#include "apueLearn.h"
//#include "unpLearn.h"
#include "ghlib/gh.h"
#include "SwordToOffer/Interview.h"
#include "apue.h"
using namespace std;
using namespace swordToOffer;

void getArray(long *array, int length);
long com(int n);
int main(int argc, char* argv[]) {
//    int p[17] = {1,10,3,8,12,2,9,6,6,7,4,11,3,7,16,5};
//    std::string str = "hchzvfrkmlnozjk";
//    std::string str2 = "abaccdeff";
//    gh::print(FirstNotRepeating(str2));

    int a1[4] = {1,2,3,4};
    int a2[6] = {1,2,3,4,5,6};
    ListNode *p1 = newListNode(a1, 4);
    ListNode *p2 = newListNode(a2, 6);
    ListNode *p3 = newListNode(10);
    addListNode(p1, p3);
    addListNode(p2, p3);

    ListNode *pre = FindFirstCommonNode(p1, p2);
    gh::print(pre->m_nValue);



}


//889##24##7##7## 89##2##  1248##9##50##1##362##3##74##5##

