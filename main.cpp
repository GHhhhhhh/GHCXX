#include <iostream>
#include <algorithm>
#include <dirent.h>
#include <thread>
#include "apueLearn.h"
#include "unpLearn.h"
#include "ghlib/gh.h"
#include "SwordToOffer/Interview.h"
using namespace std;
using namespace swordToOffer;
int a = 0;
void func() {
    for (int i = 0; i <=2; ++i)
        a+= i*(i%2?1:-1);
}

int main(int argc, char* argv[]) {
    char *c = "889##24##7##7##";
    // BinaryTreeNode *pRoot1 = createBinaryTreeNodebyPre(c, 15);
    // PreBinaryTree(pRoot1);
//    BinaryTreeNode *pRoot2 = createBinaryTreeNodebyPre();
//    PreBinaryTree(pRoot2);
//    gh::print(HasSubtree(pRoot1, pRoot2));
//    gh::print("Hello vscode!");
     std::thread t1(func);
     std::thread t2(func);
    t1.detach();
    t2.join();
    cout<<a<<endl;


}

//889##24##7##7## 89##2##