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
}





#endif //GH_CODE_INTERVIEW_H
