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

   BinaryTreeNode *root = createBinaryTreeNodebyPre("1248##9##50##1##362##3##74##5##");
   PrintFromTopToBottom3(root);
}

//889##24##7##7## 89##2##  1248##9##50##1##362##3##74##5##

