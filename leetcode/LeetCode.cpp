//
// Created by gh on 5/15/19.
//

#include <gh.h>
#include <map>
#include <cmath>
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
    int left = 0, right = height.size() - 1;
    int ans = 0;
    int left_max = 0, right_max = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
            ++left;
        }
        else {
            height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
            --right;
        }
    }
    return ans;
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
    while (str1Count >= 0 && str2Count >= 0) {
        int temp = str1[str1Count--] - '0' + str2[str2Count--] - '0';
        temp = temp + jin;
        jin = temp / 10;
        temp %= 10;
        res += to_string(temp);
    }

    while(str1Count >= 0 ) {
        int temp = str1[str1Count--] - '0';
        temp = temp + jin;
        jin = temp / 10;
        temp %= 10;
        res += to_string(temp);
    }

    while(str2Count >= 0 ) {
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

int LC::jump(vector<int>& nums) {
    if (nums.size() <= 1)
        return 0;
    int start = 0, step = 0, reach = 0;
    while (reach < nums.size() - 1) {
        int farest = 0;
        for (int i = start; i <= reach; ++i) {
            farest = max(farest, nums[i] + i);
        }
        start = reach + 1;
        reach = farest;
        ++step;
    }
    return step;
}

vector<vector<int>> permute(vector<int>& nums) {

}

vector<vector<int>> Solution::permute(vector<int> &nums) {
    if (!nums.empty())
        permuteT(nums, 0);
    return permuteRes;
}

void Solution::permuteT(vector<int> &nums, int index) {
    if (index == nums.size()) {
        permuteRes.emplace_back(nums);
        return;
    }

    for (int i = index; i < nums.size(); ++i) {
        swap(nums[index], nums[i]);
        permuteT(nums, index + 1);
        swap(nums[index], nums[i]);
    }
}

vector<vector<int>> Solution::permuteUnique(vector<int> &nums) {
    if (!nums.empty()) {
        sort(nums.begin(), nums.end());
        permuteT2(nums, 0);
    }
    return permuteRes;
}

void Solution::permuteT2(vector<int> &nums, int index) {
    if (index == nums.size()) {
        permuteRes.emplace_back(nums);
        return;
    }
    for (int i = index; i < nums.size(); ++i) {
        if (i != index && nums[index] == nums[i]) {
            continue;
        }
        swap(nums[index], nums[i]);
        permuteT2(nums, index + 1);
        swap(nums[index], nums[i]);
    }
}

void Solution::rotate(vector<vector<int>> &matrix) {
    int size = matrix.size();
    for (int i = 0; i < size; ++i) {
        int left = 0, right = size - 1;
        while (left < right)
            swap(matrix[i][left++], matrix[i][right--]);

    }

    int j = size - 2;
    while (j >= 0) {
        int interI = 0, interJ = j;
        while (interI < size / 2 && interI < size - interJ - 1)
            swap(matrix[interI++][interJ++], matrix[size - interJ - 1][size - interI - 1]);
        j--;
    }

    int i = 1;
    while (i < size - 1) {
        int interI = i, interJ = 0;
        while (interI < size - 1 && interI < size - interJ - 1)
            swap(matrix[interI++][interJ++], matrix[size - interJ - 1][size - interI - 1]);
        i++;
    }
}

vector<vector<string>> Solution::groupAnagrams(vector<string> &strs) {
    map<string,vector<string>> dict;
    vector<vector<string>> res;
    string tmp;
    for (int i = 0; i < strs.size(); ++i){
        tmp = strs[i];
        sort(tmp.begin(), tmp.end());
        dict[tmp].push_back(strs[i]);
    }

    for (auto i: dict)
        res.push_back(i.second);

    return res;
}

double Solution::myPow(double x, int n) {
    if ((fabs(x - 0.0) < 10E-6) && n < 0)
        return 0.0;
    bool neg = false;
    if (n < 0) {
        n = (unsigned int)-n;
        neg = true;
    }
    double result = myPowCore(x, n);
    if (neg)
        return 1 / result;
    return result;
}

double Solution::myPowCore(double x, unsigned int n) {
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    double result = myPowCore(x, n >> 1);
    result *= result;
    if (n & 1 == 1)
        result *= x;
    return result;
}

vector<vector<string>> Solution::solveNQueens(int n) {
    vector<int > nums;
    vector<vector<string>> result;
    for (int i = 0; i < n; ++i)
        nums.emplace_back(i);
    double time1, time2;
    time1 = gh::current_time();
    vector<vector<int>> resNum = solveNQueensPermute(nums);
    gh::print("count: ", gh::current_time() - time1);
    time1 = gh::current_time();
    for (auto &i: resNum) {
        vector<string> temp;
        for (int j = 0; j < i.size(); ++j) {
            string str;
            for (int k = 0; k < i.size(); ++k) {
                if (k == i[j])
                    str += 'Q';
                else
                    str += '.';
            }
            temp.emplace_back(str);
        }
        result.emplace_back(temp);
    }
    gh::print("ser: ", gh::current_time() - time1);
    return result;
}

vector<vector<int>> Solution::solveNQueensPermute(vector<int> &nums) {
    if (nums.empty())
        return vector<vector<int>>();
    vector<vector<int>> result;
    solveNQueensPermuteCore(result, nums, 0);
    return result;
}

void Solution::solveNQueensPermuteCore(vector<vector<int>> &result,vector<int> &nums, int index) {

    if (index == nums.size()) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (((i - j) == (nums[i] - nums[j])) || ((j - i) == (nums[i] - nums[j]))) {
                    return;
                }
            }
        }
        result.emplace_back(nums);
        return;
    }
    for (int i = index; i < nums.size(); ++i) {
//        bool b1 = (i != index);
//        bool b2 = ((i - index) == (nums[i] - nums[index])) || ((index - i) == (nums[i] - nums[index]));
        swap(nums[index], nums[i]);
//        if (i != index && (((i - index) == (nums[i] - nums[index])) || ((index - i) == (nums[i] - nums[index])))) {
//            continue;
//        }
        solveNQueensPermuteCore(result, nums, index + 1);
        swap(nums[index], nums[i]);
    }
}

int Solution::totalNQueens(int n) {
    if (n == 1)
        return 1;
    if (n < 4)
        return 0;
    vector<int > nums;
    for (int i = 0; i < n; ++i)
        nums.emplace_back(i);
    vector<vector<int>> resNum = solveNQueensPermute(nums);
    return resNum.size();
}

int Solution::totalNQueens2(int n) {
    int res;
    dfs52(n, 0, 0, 0, 0, res);
    return res;
}

void Solution::dfs52(int n, int row, int col, int ld, int rd, int &res) {
    if (row >= n) { res++; return; }
    // 将所有能放置 Q 的位置由 0 变成 1，以便进行后续的位遍历
    int bits = ~(col | ld | rd) & ((1 << n) - 1);
    while (bits > 0) {
        int pick = bits & -bits; // 注: x & -x
        dfs52(n, row + 1, col | pick, (ld | pick) << 1, (rd | pick) >> 1, res);
        bits &= bits - 1; // 注: x & (x - 1)
    }
}

