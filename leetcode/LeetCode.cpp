//
// Created by gh on 5/15/19.
//

#include <gh.h>
#include "LeetCode.h"
//39
void LC::combinationSumCore(vector<int>& candidates, vector<int>& visit, int index, int &sumNum, int target, vector<vector<int>>& res) {
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
vector<vector<int>> LC::combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<int> visit;
    vector<vector<int>> res;
    int sum = 0;
    combinationSumCore(candidates, visit, 0, sum, target, res);
    return res;
}

//40
void LC::combinationSumCore2(vector<int>& candidates, vector<int>& visit, int index, int &sumNum, int target, vector<vector<int>>& res) {
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
vector<vector<int>> LC::combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<int> visit;
    vector<vector<int>> res;
    int sum = 0;
    combinationSumCore(candidates, visit, 0, sum, target, res);
    return res;
}

//41
int LC::firstMissingPositive(vector<int>& nums) {
    if (nums.empty())
        return 1;
    for (int i = 0; i < nums.size(); ++i) {
        while (nums[i] > 0 && nums[i] < nums.size()&& nums[i] != nums[nums[i] - 1])
            swap(nums[nums[i] - 1], nums[i]);
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != i + 1)
            return i + 1;
    }
    return nums.size() + 1;

}
//42
int LC::trap(vector<int>& height) {

}

//43
string LC::multiply(string num1, string num2) {
        if (num1.size() < 1 || num2.size() < 1 || num1[0] == '0' || num2[0] == '0')
            return string("0");

        string res = "0";
        string add;
        int leght1 = num1.size();
        int k = 0;
        for (int i = leght1 - 1; i >= 0; i--) {
            string temp = strMultiplication(num2, num1[i]- '0');
            int kk = k;
            while (kk--) {
                temp += '0';
            }
//            gh::print("temp: ", temp);
//            gh::print("multiply: ", res);
            res = strAdd(res, temp);
            k++;
        }
    return res;
}

string LC::strMultiplication(string &str, int num) {
    string res;
    int shiwei = 0;
    for (int i = str.size() - 1; i >= 0 ; --i) {
        int re = num * (str[i] - '0') + shiwei;
        shiwei = re / 10;
        res += (re % 10) + '0';
    }
    res += shiwei + '0';
    int left = 0;
    int right = res.size() - 1;
    while (res[right] == '0') {
        right--;
        res.pop_back();
    }
    while (left < right) {
        swap(res[left++], res[right--]);
    }
//    gh::print("mut: ", res);
    return res;
}

string LC::strAdd(string &str1, string &str2) {
    if (str1.size() == 0)
        return str2;
    if (str2.size() == 0)
        return str1;

    string res;
    int str1Count = str1.size() -1;
    int str2Count = str2.size() -1;
    int jin = 0;
    while (str1Count >=0 && str2Count >=0) {
        int temp = str1[str1Count--] - '0' + str2[str2Count--] - '0';
        temp = temp + jin;
        jin = temp / 10;
        temp %= 10;
        res += to_string(temp);
    }

    while(str1Count >=0 ) {
        int temp = str1[str1Count--] - '0';
        temp = temp + jin;
        jin = temp / 10;
        temp %= 10;
        res += to_string(temp);
    }

    while(str2Count >=0 ) {
        int temp = str2[str2Count--] - '0';
        temp = temp + jin;
        jin = temp / 10;
        temp %= 10;
        res += to_string(temp);
    }

    res += to_string(jin);

    int left = 0;
    int right = res.size() - 1;
    while (res[right] == '0') {
        right--;
        res.pop_back();
    }

    while (left < right) {
        swap(res[left++], res[right--]);
    }

    return res;
}
