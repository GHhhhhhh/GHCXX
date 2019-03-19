//
// Created by GH on 2018/11/26.
//

#ifndef GH_CODE_INTERVIEW_H
#define GH_CODE_INTERVIEW_H

#include <iostream>
#include <stack>
#include <algorithm>
#include <queue>
#include <array>
#include <set>
#include "../ghlib/gh.h"

namespace swordToOffer {
    struct BinaryTreeNode {
        int m_nValue;
        BinaryTreeNode* m_pLeft;
        BinaryTreeNode* m_pRight;
    };

    struct ComplexListNode {
        int m_nValue;
        ComplexListNode *m_pNext;
        ComplexListNode *m_pSlibling;
    };

    struct ListNode {
        int m_nValue;
        ListNode* m_pNext;
    };
    void PreBinaryTree(BinaryTreeNode* pRoot);

    BinaryTreeNode* createBinaryTreeNodebyPre();

    BinaryTreeNode* createBinaryTreeNodebyPre(char *str);

    BinaryTreeNode* createBinaryTreeNodebyPreCore(char *str, int *index);

    void addListNode(ListNode* pHead, ListNode* newlistNode);

    ListNode* newListNode(int* numbers, int length);

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

    //20
    bool isNumberic(const char* str);
    bool scanInteger(const char** str);
    bool scanUnsignedInteger(const char** str);
    //21
    void RecorderOddEven(int *pData, int length);
    //22
    ListNode* FindKthToTail(ListNode* pListNode, unsigned int k);
    //23
    ListNode* MeetNode(ListNode* pHead);
    ListNode* EntryNodeLoop(ListNode* pHead);

    //24
    ListNode* ReverseList(ListNode *pHead);

    //25
    ListNode* mergeListNode(ListNode* pHead1, ListNode* pHead2);
    ListNode* mergeListNodeByRecursion(ListNode* pHead1, ListNode* pHead2);

    //26
    bool HasSubtree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2);
    bool coreHasSubtree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2);

    //27
    void MirrorRecursively(BinaryTreeNode* pRoot);

    //28
    bool isSymmetrical(BinaryTreeNode* pRoot);
    bool isSymmetrical(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2);

    //29
    void PrintMatrixClockwisely(int **numbers, int cols, int rows);
    void PrintMatrixCircle(int **numbers, int cols, int rows, int start);

    //30
    template <typename T>
    class StackMin {
    public:
        void push(const T &t);
        void pop();
        T top();
        T min();
    private:
        std::stack<T> m_data;
        std::stack<T> m_min;
    };

    template<typename T>
    void StackMin<T>::push(const T &t) {
        m_data.push(t);
        if (m_min.empty())
            m_min.push(t);
        else {
            m_min.push(m_min.top() > t ? t : m_min.top());
        }
    }

    template<typename T>
    void StackMin<T>::pop() {
        m_data.pop();
        m_min.pop();
    }

    template<typename T>
    T StackMin<T>::min() {
        return m_min.top();
    }

    template<typename T>
    T StackMin<T>::top() {
        return m_data.top();
    }

    //31
    bool isStackOrder(const int *pPush, const int *pPop, int length);

    //32
    void PrintFromTopToBottom(BinaryTreeNode *pTreeRoot);

    //32 (2)
    void PrintFromTopToBottom2(BinaryTreeNode *pTreeRoot);

    //32 (3)
    void PrintFromTopToBottom3(BinaryTreeNode *pTreeRoot);

    //33
    bool VerifySquenceOFBST(std::vector<int> &number);

    //34
    void FindPath(BinaryTreeNode* root, int expectNumber);
    void FindPathCore(BinaryTreeNode* root, int expectNumber, std::vector<int> &);

    //35
    void CloneNodes(ComplexListNode *pHead);
    void ConnectSiblingNodes(ComplexListNode *pHead);
    ComplexListNode* ReconnectNodes(ComplexListNode *pHead);
    ComplexListNode* Clone(ComplexListNode *pHead);

    //36
    BinaryTreeNode *Convert(BinaryTreeNode* pRootOfTree);
    void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList);

    //37
    std::string Serialize(BinaryTreeNode* pRoot);
    void Serialize(BinaryTreeNode* pRoot, std::string& tree);

    BinaryTreeNode* Deserialize(BinaryTreeNode**, std::string& tree);
    void Deserialize(BinaryTreeNode** pRoot, std::list<std::string> &treeNode);

    //38
//    void Permutation(std::string& str);
//    void Permutation(std::string& str, int &index);

    void Permutation(char *pStr);
    void Permutation(char *pStr, char* pBegin);

    void Permutation(std::string& str);
    void Permutation(std::string& str, int &i);

    void Combination(char* str);
    void Combination(char* str, int i, std::vector<char> &vector);

    //39
    int MoreThanHalfNum(int *numbers, int length, int& result);

    //40
    void GetLeastNumbers(const std::vector<int> &data, std::multiset<int, std::greater<>> & lastNumbers, int k);

}





#endif //GH_CODE_INTERVIEW_H
