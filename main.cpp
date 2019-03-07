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

//   BinaryTreeNode *root = createBinaryTreeNodebyPre("1248##9##50##1##362##3##74##5##");
//   PrintFromTopToBottom3(root);
//    std::vector<int> number;
//    number.emplace_back(5);
//    number.emplace_back(7);
//    number.emplace_back(6);
//    number.emplace_back(9);
//    number.emplace_back(11);
//    number.emplace_back(10);
//    number.emplace_back(8);
//
//    std::vector<int> number2;
//    number2.emplace_back(7);
//    number2.emplace_back(4);
//    number2.emplace_back(6);
//    number2.emplace_back(5);
//    number[0] = 5;
//    number[1] = 7;
//    number[2] = 6;
//    number[3] = 9;
//    number[4] = 11;
//    number[5] = 10;
//    number[6] = 8;
//    gh::print(VerifySquenceOFBST(number));
//    gh::print(VerifySquenceOFBST(number2));
//   BinaryTreeNode *root = createBinaryTreeNodebyPre("134##2##5##");
//   FindPath(root, 6);
    ComplexListNode *pHead = new ComplexListNode();
    pHead->m_nValue = 1;
    ComplexListNode *p1 = new ComplexListNode();
    p1->m_nValue = 2;
    ComplexListNode *p2 = new ComplexListNode();
    p2->m_nValue = 3;
    ComplexListNode *p3 = new ComplexListNode();
    p3->m_nValue = 4;
    ComplexListNode *p4 = new ComplexListNode();
    p4->m_nValue = 5;
    pHead->m_pNext = p1;
    p1->m_pNext = p2;
    p2->m_pNext = p3;
    p3->m_pNext = p4;
    ComplexListNode * pCopy = Clone(pHead);
    while (pHead != nullptr) {
        printf("%d ", pHead->m_nValue);
        pHead = pHead->m_pNext;
    }
    printf("\n");
    while (pCopy != nullptr) {
        printf("%d ", pCopy->m_nValue);
        pCopy = pCopy->m_pNext;
    }


}

//889##24##7##7## 89##2##  1248##9##50##1##362##3##74##5##

