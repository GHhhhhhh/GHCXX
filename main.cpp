#include <iostream>
#include <algorithm>
#include "ghlib/gh.h"
#include "SwordToOffer/Interview.h"
using namespace std;
using namespace swordToOffer;
int main() {
//    char matrix[12] = {'a','b','t','g','c','f','c','s','j','d','e','h'};
//    gh::print(hasPath(matrix, 3,4,"bfce"));
//    gh::print(hasPath(matrix, 3,4,"abfb"));
//    gh::print(maxProductAfterCutting_solution(8));
//    Print1ToMaxOfDigits(3);
    ListNode **phead = new ListNode*();
    addListNode(phead,1);
    addListNode(phead,1);
    addListNode(phead,2);
    addListNode(phead,2);
    addListNode(phead,3);
    addListNode(phead,3);
    printListNode(phead);
//    ListNode *head = newListNode(10);
//    addListNode(head, newListNode(1));
//    addListNode(head, newListNode(1));
//    addListNode(head, newListNode(2));
//    addListNode(head, newListNode(2));
//    addListNode(head, newListNode(3));
//    addListNode(head, newListNode(4));
//    printListNode(head);

//    ListNode *pToBeDelete = head->m_pNext;
//    DeleteNode(head, pToBeDelete);
//    *phead = head;
    DeleteDuplication(phead);
    printListNode(phead);

    return 0;
}

