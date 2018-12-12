//
// Created by gh on 18-11-9.
//

#ifndef CPLUSPLUSLEETCODE_CONTAINERWITHMOSTWATER11_H
#define CPLUSPLUSLEETCODE_CONTAINERWITHMOSTWATER11_H
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        for (int i = 0; i < height.size(); i++) {
            for (int j = i + 1; j < height.size(); j++) {
                int h = height[i] > height[j] ? height[j] : height[i];
                max = max > (j - i) * h ? max : (j - i) * h;
            }
        }
        return max;
    }

    int maxArea2(vector<int>& height) {
        int maxarea = 0;
        int i = 0, j = height.size() - 1;
        while (i < j) {
            if (height[i] < height[j]) {
                maxarea = max(maxarea, (j - i) * height[i]);
                ++i;
            }
            else {
                maxarea = max(maxarea, (j - i) * height[j]);
                --j;
            }
        }
        return maxarea;
    }
};
#endif //CPLUSPLUSLEETCODE_CONTAINERWITHMOSTWATER11_H
