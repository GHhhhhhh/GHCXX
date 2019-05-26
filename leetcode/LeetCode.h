//
// Created by gh on 5/15/19.
//

#ifndef GH_CODE_LEETCODE_H
#define GH_CODE_LEETCODE_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class LeetCode {

};

namespace LC {
    //39
    void combinationSumCore(vector<int>& candidates, vector<int>& visit, int index, int &sumNum, int target, vector<vector<int>>& res);
    vector<vector<int>> combinationSum(vector<int>& candidates, int target);

    //40
    void combinationSumCore2(vector<int>& candidates, vector<int>& visit, int index, int &sumNum, int target, vector<vector<int>>& res);
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target);


    //41
    int firstMissingPositive(vector<int>& nums);
    //42
    int trap(vector<int>& height);

    //43
    string multiply(string num1, string num2);

    string strMultiplication(string &str, int num);

    string strAdd(string &str1, string &str2);

    int jump(vector<int>& nums);

    vector<vector<int>> permute(vector<int>& nums);

}


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums);
    void permuteT(vector<int>& nums, int index);
    //47
    vector<vector<int>> permuteUnique(vector<int>& nums);
    void permuteT2(vector<int> nums, int index);
    vector<vector<int>> permuteRes;

    void rotate(vector<vector<int>>& matrix);

    //49
    vector<vector<string>> groupAnagrams(vector<string>& strs);
};
#endif //GH_CODE_LEETCODE_H
