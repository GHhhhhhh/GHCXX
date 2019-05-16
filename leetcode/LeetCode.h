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
    void combinationSumCore(vector<int>& candidates, vector<int>& visit, int index, int &sumNum, int target, vector<vector<int>>& res) {
        for (int i = index; i < candidates.size(); ++i) {

            sumNum += candidates[i];
            visit.emplace_back(candidates[i]);

            if (sumNum == target) {
                res.emplace_back(visit);
                sumNum -= candidates[i];
                visit.pop_back();
                return;
            } else if (sumNum > target){
                sumNum -= candidates[i];
                visit.pop_back();
                return;
            }

            combinationSumCore(candidates, visit, i, sumNum, target, res);
            sumNum -= candidates[i];
            visit.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> visit;
        vector<vector<int>> res;
        int sum = 0;
        combinationSumCore(candidates, visit, 0, sum, target, res);
        return res;
    }

    //40
    void combinationSumCore2(vector<int>& candidates, vector<int>& visit, int index, int &sumNum, int target, vector<vector<int>>& res) {
        for (int i = index; i < candidates.size(); ++i) {

            sumNum += candidates[i];
            visit.emplace_back(candidates[i]);

            if (sumNum == target) {
                for (auto &result: res) {
                    if (result.size() == visit.size()) {
                        int j = 0;
                        while (j < result.size() && result[j] == visit[j]) {
                            j++;
                        }
                        if (j == result.size()) {
                            sumNum -= candidates[i];
                            visit.pop_back();
                            return;
                        }

                    }
                }
                res.emplace_back(visit);
                sumNum -= candidates[i];
                visit.pop_back();
                return;
            } else if (sumNum > target){
                sumNum -= candidates[i];
                visit.pop_back();
                return;
            }
            combinationSumCore(candidates, visit, i + 1, sumNum, target, res);
            sumNum -= candidates[i];
            visit.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> visit;
        vector<vector<int>> res;
        int sum = 0;
        combinationSumCore(candidates, visit, 0, sum, target, res);
        return res;
    }

    //42
    int trap(vector<int>& height) {

    }

    //43
    string multiply(string num1, string num2) {
//        if (num1.size() < 1 || num2.size() < 1 || num1[0] == '0' || num2[0] == '0')
//            return string("0");
//
//        string res;
//        string add;
//        int leght1 = num1.size();
//        int leght2 = num2.size();
//
//        for (auto n1: num1) {
//
//            for (auto n2: num2) {
//                int sum = atoi(n2) * atoi(n1);
//            }
//        }
    }
}

#endif //GH_CODE_LEETCODE_H
