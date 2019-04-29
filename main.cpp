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

    BinaryTreeNode *p = createBinaryTreeNodebyPre("532##4##76##8##");
    gh::print(KthNode(p, 3)->m_nValue);
    gh::print(IsBalanced(p));

}


//889##24##7##7## 89##2##  1248##9##50##1##362##3##74##5##

