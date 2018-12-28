//
// Created by GH on 2018/11/26.
//

#include <unistd.h>
#include <cstdlib>
#include "Interview.h"
using namespace swordToOffer;

namespace swordToOffer {

    bool duplicate(int numbers[], int length, int *duplicate) {
        if (numbers == nullptr || length <= 0)
            return false;

        for (int i = 0; i < length; ++i) {
            if (numbers[i] < 0 || numbers[i] >= length)
                return false;
        }

        for (int i = 0; i < length; ++i) {
            while (numbers[i] != i) {
                if (numbers[i] == numbers[numbers[i]]) {
                    *duplicate = numbers[i];
                    return true;
                }
                int temp = numbers[i];
                numbers[i] = numbers[temp];
                numbers[temp] = temp;
            }
        }
        return false;
    }

    int getDuplication(const int* numbers, int length) {
        if (numbers == nullptr || length <= 0)
            return -1;
        int start = 1;
        int end = length - 1;
        while(start <= end) {
            int middle = (end + start) / 2;
            int count = countRange(numbers, length, start, middle);
            if (end == start) {
                if (count > 1)
                    return start;
                else
                    break;
            }
            if (count > (middle - start + 1))
                end = middle;
            else
                start = middle + 1;
        }
        return -1;
    }

    int countRange(const int* numbers, int length, int start, int end) {
        if (numbers == nullptr || length <= 0)
            return 0;
        int count = 0;
        for (int i = 0; i < length; ++i) {
            if (numbers[i] <= end && numbers[i] >= start)
                ++count;
        }
        return count;
    }

    bool Find(int matrix[][4], int rows, int columns, int number) {
        if (matrix == nullptr || rows <= 0 || columns <= 0)
            return false;
        for (int i = columns - 1; i >= 0; --i) {
            for (int j = 0; j < rows; ++j) {
                if (matrix[j][i] == number)
                    return true;
                if (matrix[j][i] > number)
                    break;
                else
                    continue;
            }
            ++matrix;
        }
        return false;
    }

    bool Find(int *matrix, int rows, int columns, int number) {
        if (matrix == nullptr || rows <=0 || columns <= 0)
            return false;
        int row = 0;
        int column = columns - 1;
        while(row < rows && column >= 0) {
            if (matrix[row * columns + column] == number)
                return true;
            if (matrix[row * columns + column] > number)
                --column;
            else
                ++row;
        }
        return false;
    }

    void ReplaceBlank(char string[], int length) {
        if (string == nullptr || length <= 0)
            return;
        int stringLength = 0;
        int blankCount = 0;
        while (string[stringLength] != '\0') {
            if (string[stringLength] == ' ')
                ++blankCount;
            ++stringLength;
        }
        int newLength = stringLength + blankCount * 2;
        if (newLength > length)
            return;
        int indexp2 = newLength;
        int indexp1 = stringLength;
        while (indexp1 != indexp2) {
            if (string[indexp1] != ' ') {
                string[indexp2--] = string[indexp1--];
            } else {
                string[indexp2--] = '0';
                string[indexp2--] = '2';
                string[indexp2--] = '%';
                --indexp1;
            }
        }
    }

    void MergeArray(int *numbers1, int length1, int *numbers2, int length2) {
        if (numbers1 == nullptr || numbers2 == nullptr || length2 <= 0)
            return;
        if (length1 <= 0) {
            int nb2 = length2 - 1;
            while (nb2 >= 0)
                numbers1[nb2] = numbers2[nb2--];
            return;
        }
        int newLength = length1 + length2 - 1;
        int nb1 = length1 - 1;
        int nb2 = length2 - 1;
        while (newLength >= 0 && nb1 >= 0 && nb2 >= 0) {
            if (numbers1[nb1] > numbers2[nb2])
                numbers1[newLength--] = numbers1[nb1--];
            else
                numbers1[newLength--] = numbers2[nb2--];
        }
    }

    BinaryTreeNode* ConstructByFM(int *preorder, int *inorder, int length) {
        if (preorder == nullptr || inorder == nullptr || length <= 0 )
            return nullptr;
        return  ConstructByFMCore(preorder, preorder + length - 1, inorder, preorder + length - 1);
    }

    BinaryTreeNode* ConstructByFMCore(int *startPreorder, int *endPreorder,
                                      int *startInorder, int *endInorder) {
        int rootValue = startPreorder[0];
        BinaryTreeNode* root = new BinaryTreeNode();
        root->m_nValue = rootValue;
        root->m_pLeft = root->m_pRight = nullptr;
        if (startPreorder == endPreorder) {
            if (startInorder == endInorder && *startPreorder == *startInorder)
                return root;
            else
                throw std::exception();
        }
        int *rootInorder = startPreorder;
        while (rootInorder <= endInorder && *rootInorder != rootValue )
            ++rootInorder;
        if (rootInorder == endInorder && *rootInorder != rootValue)
            throw std::exception();
        int leftLength = rootInorder - startInorder;
        int * leftPreorderEnd = startPreorder + leftLength;
        if (leftLength > 0) {
            root->m_pLeft = ConstructByFMCore(leftPreorderEnd + 1, leftPreorderEnd,
                                              startInorder, rootInorder - 1);
        }
        if (leftLength < endPreorder - startPreorder) {
            root->m_pRight = ConstructByFMCore(leftPreorderEnd + 1, endPreorder,
                                               rootInorder + 1, endInorder);
        }
        return root;
    }

    long long FibonacciByRecursion(unsigned int n) {
        if (n <= 0)
            return 0;
        if (n == 1)
            return 1;
        return FibonacciByRecursion(n - 1) + FibonacciByRecursion(n - 2);
    }

    long long Fibonacci(unsigned int n) {
        long long firstNumber = 0;
        long long secondNumber = 1;
        if (n == 0)
            return firstNumber;
        if (n == 1)
            return secondNumber;
        long long fibonacci = 0;
        for (int i = 2; i <= n; ++i) {
            fibonacci = firstNumber + secondNumber;
            firstNumber = secondNumber;
            secondNumber = fibonacci;
        }
        return fibonacci;
    }

    int RandomInRange(int start, int end) {
        if (end > start) {
            srand(time(NULL));
            return start + rand() % ((end - start));
        }
        return 0;
    }

    void swap_element(int *a, int *b) {
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
    }

    int Partition(int data[], int length, int start, int end) {
        if (data == nullptr || length <= 0 || start < 0 || end >= length)
            gh::print("ERROR");
//            throw new std::exception();
        int index = RandomInRange(start, end);
//        gh::print("index: ", index, "index data: ", data[index]);
        std::swap(data[index], data[end]);
        int small = start - 1;
        for (index = start; index < end; ++index) {
            if (data[index] < data[end]) {
                ++small;
                if (small != index)
                    std::swap(data[index], data[small]);
            }
        }
        ++small;
        std::swap(data[small], data[end]);
        return small;
    }

    void QuickSort(int data[], int length, int start, int end) {
        if (start == end)
            return;
        int index = Partition(data, length, start, end);
        if (index > start)
            QuickSort(data, length, start, index - 1);
        if (index < end)
            QuickSort(data, length, index + 1, end);
    }

    void sortAges(int *ages, int length) {
        if (ages == nullptr || length < 0)
            gh::print("exception");
        int maxage = 99;
        int ageCount[maxage + 1];
        for (int i = 0; i < 100; ++i) {
            ageCount[i] = 0;
        }
        for (int i = 0; i < length; ++i) {
            int age = ages[i];
            if (age > 99 || age < 0)
                gh::print("exception");
            ++ageCount[age];
        }
        int k = 0;
        for (int i = 0; i <= maxage; ++i) {
            for (int j = 0; j < ageCount[i]; ++j) {
                ages[k++] = i;
            }
        }
    }

	int Min(int *numbers, int length) {
        if (numbers == nullptr || length <= 0)
            throw new std::exception();
        int indexP1 = 0;
        int indexP2 = length - 1;
        int indexMiddle;
        while (indexP2 - indexP1 > 1) {
            indexMiddle = (indexP1 + indexP2) / 2;
            //当三个值相等
            if (numbers[indexP1] == numbers[indexMiddle] and numbers[indexMiddle] == numbers[indexP2]) {
                int min = numbers[indexP2];
                for (int i = indexP1; i < indexP2; ++i) {
                    if (numbers[i] < min)
                        min = numbers[i];
                }
                return min;
            }

            if (numbers[indexP1] <= numbers[indexMiddle]) {
                indexP1 = indexMiddle;
                continue;
            }
            if (numbers[indexP2] >= numbers[indexMiddle]) {
                indexP2 = indexMiddle;
            }
        }
        return numbers[indexP1] < numbers[indexP2] ? numbers[indexP1] : numbers[indexP2];
    }

    bool hasPath(char *matrix, int rows, int cols, char *str) {
        if (matrix == nullptr || rows <= 0 || cols <= 0 || str == nullptr)
            return false;
        bool visit[rows * cols];
        for (int i = 0; i < cols * rows; ++i)
            visit[0] = false;

        int pathLength = 0;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (hasPathCore(matrix, rows, cols, row, col, str, visit, pathLength))
                    return true;
            }
        }
        return false;
    }

    bool hasPathCore(char *matrix, int rows, int cols, int row, int col, char *str, bool *visited, int pathLength) {
        if (str[pathLength] == '\0')
            return true;
        bool hasPath = false;
        if (row >= 0 and col >= 0 and row < rows and col < cols and matrix[row * cols + col] == str[pathLength] and !visited[row * cols + col]) {
            ++pathLength;
            visited[row * cols + col] = true;
            hasPath = hasPathCore(matrix, rows, cols, row - 1, col, str, visited, pathLength) ||
                      hasPathCore(matrix, rows, cols, row, col - 1, str, visited, pathLength) ||
                      hasPathCore(matrix, rows, cols, row + 1, col, str, visited, pathLength) ||
                      hasPathCore(matrix, rows, cols, row, col + 1, str, visited, pathLength);
            if (!hasPath) {
                visited[row * cols + col] = false;
            }
        }
        return hasPath;
    }

    int robotMoveCount(int threshold, int rows, int cols) {
        if (rows < 0 || cols < 0)
            return 0;
        bool visited[rows * cols];
        for (int i = 0; i < cols * rows; ++i) {
            visited[i] = false;
        }
        return robotMoveCore(rows, cols, 0, 0, threshold, visited);
    }

    int robotMoveCore(int rows, int cols, int row, int col, int threshold, bool *visited) {
        int counts = 0;
        if (row < rows && col < cols && row >= 0 && col >= 0 && computeThreshold(row, col, threshold) && !visited[row * cols + col]) {
            visited[row * cols + col] = true;
            counts = 1 +
            robotMoveCore(rows, cols, row - 1, col, threshold, visited) +
            robotMoveCore(rows, cols, row, col - 1, threshold, visited) +
            robotMoveCore(rows, cols, row, col + 1, threshold, visited) +
            robotMoveCore(rows, cols, row + 1, col, threshold, visited);
        }
        return counts;
    }

    bool computeThreshold(int row, int col, int threshold) {
        if (row < 0 || col < 0 || threshold < 0 )
            return false;
        int thresholdTemp = 0;
        while (row % 10 != 0) {
            thresholdTemp += row % 10;
            row /= 10;
        }
        while (col % 10 != 0) {
            thresholdTemp += col % 10;
            col /= 10;
        }
        return thresholdTemp < threshold;
    }

    int maxProductAfterCutting_solution(int length) {
        if (length < 2)
            return 0;
        if (length == 2)
            return 2;
        if (length == 3)
            return 1;
        int *products = new int[length + 1];
        products[0] = 0;
        products[1] = 0;
        products[2] = 2;
        products[3] = 3;
        int max = 0;
        for(int i = 4; i <= length; ++i) {
            max = 0;
            for (int j = 1; j <= i/2; ++j) {
                int product = products[j] * products[i - j];
                if (product > max)
                    max = product;
            }
            products[i] = max;
        }
        max = products[length];
        delete[] products;
        return max;
    }

    int NumberOf1(int n) {
        int count = 0;
        unsigned int flag = 1;
        while (flag) {
            if (flag & n)
                ++count;
            flag = flag << 1;
        }
        return count;
    }

    int NumberOf1_new(int n) {
        int count = 0;
        while (n) {
            ++count;
            n = (n - 1) & n;
        }
        return count;
    }

}



