//
// Created by GH on 2018/11/26.
//

#ifndef GH_CODE_INTERVIEW_H
#define GH_CODE_INTERVIEW_H

#include <iostream>
#include <stack>
#include <queue>
#include "../ghlib/gh.h"

namespace swordToOffer {
    struct BinaryTreeNode {
        int m_nValue;
        BinaryTreeNode* m_pLeft;
        BinaryTreeNode* m_pRight;
    };

    struct ListNode {
        int m_nValue;
        ListNode* m_pNext;
    };

    void addListNode(ListNode* pHead, ListNode* newlistNode);

    void addListNode(ListNode** pHead, int value);

    void printListNode(ListNode* pHead);

    void printListNode(ListNode** pHead);

    ListNode* newListNode(int value);

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

//?面试题7 给前序 中序遍历，给出二叉树 preorder{1,2,4,7,3,5,6,8} inorder{4,7,2,1,5,3,8,6}
    BinaryTreeNode* ConstructByFM(int *preorder, int *inorder, int length);

    BinaryTreeNode* ConstructByFMCore(int *stratPreorder, int *endPreorder,
                                      int *stratInorder, int *endInorder);
//面试题9  用两个栈实现队列
    template <typename T>
    class CQueue {
    public:
        void appendTail(const T& node);
        T deleteHead();
    private:
        std::stack<T> stack1;
        std::stack<T> stack2;
    };

    template<typename T>
    void CQueue<T>::appendTail(const T &node) {
        stack1.push(node);
    }

    template<typename T>
    T CQueue<T>::deleteHead() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
    }
//    if (stack2.empty())
//        throw new std::exception();
    T head = stack2.top();
    stack2.pop();
    return head;
    }

    //用两个队列实现栈
    template <typename T>
    class Cstack {
    public:
        void push (const T& node);
        T pop();

    private:
        std::queue<T> queue1;
        std::queue<T> queue2;
    };

    template<typename T>
    void Cstack<T>::push(const T &node) {
        queue1.push(node);
    }

    template<typename T>
    T Cstack<T>::pop() {
        if (queue1.empty())
            gh::print("queue empty");
        while (queue1.size() > 1) {
            queue2.push(queue1.front());
            queue1.pop();
        }
        T head = queue1.front();
        queue1.pop();
        queue1.swap(queue2);
        return head;
    }

    //面试题10 斐波那契数列
    //递归 最慢算法
    long long FibonacciByRecursion(unsigned int n);

    long long Fibonacci(unsigned int n);

    //快排
    int RandomInRange(int start, int end);

    int Partition(int data[], int length, int start, int end);

    void QuickSort(int data[], int length, int start, int end);

    //age sort
    void sortAges(int *ages, int length);

    //面试题11 旋转数组的最小数字
	int Min(int *numbers, int length);
	
    //12 judge have path
    bool hasPath(char *matrix, int rows, int cols, char *str);

    bool hasPathCore(char *matrix, int rows, int cols, int row, int col, char *str, bool *visit, int);

    //13 机器人移动多少格子
    int robotMoveCount(int threshold, int rows, int cols);
    int robotMoveCore(int rows, int cols, int row, int col, int threshold, bool *visited);
    bool computeThreshold(int row, int col, int threshold);

    // 14 cut line
    int maxProductAfterCutting_solution(int length);

    //15
    int NumberOf1(int n);

    int NumberOf1_new(int n);

    //16
    double Pow(double base, int exponent);

    //17
    void Print1ToMaxOfDigits(int n);

    void Print1ToMaxOfDigitsRecursively(char* number, int length, int index);

    void printNumber(char *number);

    // 18
    void DeleteNode(ListNode* pListHead, ListNode* pToBeDelete);

    void DeleteDuplication(ListNode **pHead);

    //19 match
    bool match(char* str, char* pattern);
    bool matchCore(char* str, char* pattern);
}





#endif //GH_CODE_INTERVIEW_H
