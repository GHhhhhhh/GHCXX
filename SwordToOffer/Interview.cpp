//
// Created by GH on 2018/11/26.
//

#include "Interview.h"

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

}

BinaryTreeNode* ConstructByFMCore(int *stratPreorder, int *endPreorder,
                                  int *stratInorder, int *endInorder) {

}