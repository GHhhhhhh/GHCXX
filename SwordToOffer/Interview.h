//
// Created by GH on 2018/11/26.
//

#ifndef GH_CODE_INTERVIEW_H
#define GH_CODE_INTERVIEW_H

#include <iostream>

struct BinaryTreeNode {
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

struct ListNode {
    int m_nValue;
    ListNode* m_pNext;
};

//面试题3     int numbers[8] = {2,3,5,4,3,2,6,7};
bool duplicate(int numbers[], int length, int *duplicate);

int getDuplication(const int* numbers, int length);

int countRange(const int* numbers, int length, int start, int end);

//面试题4
//int matrix[4][4] = {{1,2,8,9},
//                    {2,4,9,12},
//                    {4,7,10,13},
//                    {6,8,11,15}};
//int matrix2[16] = {1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15};
bool Find(int matrix[][4], int rows, int columns, int number);

bool Find(int *matrix, int rows, int columns, int number);

//面试题5 把字符串的空格替换成 %20 从后往前移动
void ReplaceBlank(char string[], int length);

void MergeArray(int *numbers1, int length1, int *numbers2, int length2);

//面试题7 给前序 中序遍历，给出二叉树
BinaryTreeNode* ConstructByFM(int *preorder, int *inorder, int length);

BinaryTreeNode* ConstructByFMCore(int *stratPreorder, int *endPreorder,
                                  int *stratInorder, int *endInorder);


#endif //GH_CODE_INTERVIEW_H
