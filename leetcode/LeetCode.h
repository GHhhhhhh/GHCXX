//
// Created by gh on 5/15/19.
//

#ifndef GH_CODE_LEETCODE_H
#define GH_CODE_LEETCODE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class LeetCode {

};
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
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

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums);
    void permuteT(vector<int>& nums, int index);
    //47 全排列
    vector<vector<int>> permuteUnique(vector<int>& nums);
    void permuteT2(vector<int> &nums, int index);
    vector<vector<int>> permuteRes;

    void rotate(vector<vector<int>>& matrix);

    //49
    vector<vector<string>> groupAnagrams(vector<string>& strs);

    //50
    double myPowCore(double x, unsigned int n);
    double myPow(double x, int n);

    //51 N 皇后
    vector<vector<string>> solveNQueens(int n);

    vector<vector<int>> solveNQueensPermute(vector<int>& nums);
    void solveNQueensPermuteCore(vector<vector<int>> &result, vector<int> &nums, int index);

    //52 N皇后
    int totalNQueens(int n);

    int totalNQueens2(int n);

    void dfs52(int n, int row, int col, int ld, int rd, int &res);

    //53 最大子序和
    int maxSubArray(vector<int>& nums);

    //55跳跃游戏
    bool canJump(vector<int>& nums);

    //56 合并空间
    static bool cmp(const vector<int>&a,const vector<int>&b )
    {
        if(a[0]==b[0])
            return a[1]>b[1];
        return a[0]<b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<int > visit;
        vector<vector<int>> result;
        for (int i = 0; i < intervals.size(); ++i)
            visit.emplace_back(0);
        int index;
        sort(intervals.begin(),intervals.end(),cmp);
        while ((index = ifEnd(visit)) != -1) {
            vector<int > tempVector = intervals[index];
            visit[index] = 1;
            for (int i = 0; i < intervals.size(); ++i) {
                if (visit[i] == 0 && tempVector[1] >= intervals[i][0]) {
                    tempVector[0] = min(tempVector[0], intervals[i][0]);
                    tempVector[1] = max(tempVector[1], intervals[i][1]);
                    visit[i] = 1;
                }
            }
            result.emplace_back(tempVector);
        }
        return result;
    }

    int ifEnd(vector<int > &visit) {
        for (int i = 0; i < visit.size(); ++i)
            if (visit[i] == 0)
                return i;
        return -1;
    }

    //57 第k个全排列
    string getPermutation(int n, int k) {
        // vector<int > vec;
        string res;
        for (int i = 1; i <= n; ++i) {
            res += i + '0';
        }
        k--;
        while (k--) {
            next_permutation(res.begin(), res.end());
        }
        return res;
    }

    //62 不同路径
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0)
            return 0;
        if (m == 1 || n == 1)
            return 1;
        vector<vector<int >> dp(m, vector<int>(n, 1));

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }

        return dp[m-1][n-1];
    }

    //63 不同路径带障碍
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = 0;

        if (m > 0)
            n = obstacleGrid[0].size();

        if (m == 0 || n == 0)
            return 0;

        if (m == 1) {
            for (int i = 0; i < n; ++i)
                if (obstacleGrid[0][i] == 1)
                    return 0;
            return 1;

        }

        if (obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1)
            return 0;
        if (n == 1) {
            for (int i = 0; i < m; ++i) {
                if (obstacleGrid[i][0] == 1)
                    return 0;
            }
            return 1;

        }
        vector<vector<long long >> dp(m, vector<long long>(n, 0));
        for (int i = 0; i < m; ++i)
            if (obstacleGrid[i][0]!=1) {
                dp[i][0] = 1;
            } else
                break;

        for (int i = 0; i < n; ++i)
            if (obstacleGrid[0][i]!=1) {
                dp[0][i] = 1;
            } else
                break;

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j)
                if (obstacleGrid[i][j] == 0) {
                    if (obstacleGrid[i-1][j] == 1)
                        dp[i][j] = dp[i][j - 1];
                    else if (obstacleGrid[i][j-1] == 1)
                        dp[i][j] = dp[i - 1][j];
                    else
                        dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                }
        }

        return dp[m-1][n-1];
    }

    //64 最小路径
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = 0;
        if (m > 0)
            n = grid[0].size();
        if (m == 0 || n == 0)
            return 0;

        if (m == 1) {
            int min = 0;
            for (int i = 0; i < n; ++i)
                min += grid[0][i];
            return min;
        }

        if (n == 1) {
            int min = 0;
            for (int i = 0; i < m; ++i)
                min += grid[i][0];
            return min;
        }


        vector<vector<int>> dp(m, vector<int >(n, 0));
        dp[0][0] = grid[0][0];

        for (int i = 1; i < m; ++i) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }

        for (int i = 1; i < n; ++i) {
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }

    //66 数组加一
    vector<int> plusOne(vector<int>& digits) {
        int pre = 0;
        for (int i = digits.size() - 1; i >= 0; --i) {
            int temp;
            if (i == digits.size() - 1)
                temp = digits[i] + 1 + pre;
            else
            {
                temp = digits[i] + pre;
            }

            if (temp >= 10) {
                digits[i] = temp % 10;
                pre = 1;
            } else {
                digits[i] = temp;
                pre = 0;
                break;
            }
        }
        if (pre == 1) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }

    //67 二进制求和
    string addBinary(string a, string b) {
        string res;
        char jin = '0';
        int indexA = a.size() - 1;
        int indexB = b.size() - 1;
        while (indexA >= 0 && indexB >= 0) {
            char temp;
            if (a[indexA] == '0' && b[indexB] == '0') {
                if (jin == '0')
                    res+='0';
                else {
                    res += '1';
                    jin = '0';
                }
            }
            else if (a[indexA] == '1' && b[indexB] == '1') {
                if (jin == '0') {
                    jin = '1';
                    res += '0';
                } else {
                    res += '1';
                }
            } else {
                if (jin == '0')
                    res += '1';
                else
                    res += '0';
            }
            indexA--;
            indexB--;
        }

        while (indexA >= 0 ) {
            if (jin == '0') {
                res += a[indexA];
            } else {
                if (a[indexA] == '0') {
                    res += '1';
                    jin = '0';
                } else {
                    res += '0';
                }
            }
            indexA--;
        }

        while (indexB >= 0 ) {
            if (jin == '0') {
                res += b[indexB];
            } else {
                if (b[indexB] == '0') {
                    res += '1';
                    jin = '0';
                } else {
                    res += '0';
                }
            }
            indexB--;
        }

        if (jin == '1')
            res += '1';
        int left = 0, right = res.size() - 1;
        while (left < right)
        {
            swap(res[left++], res[right--]);
        }
        return res;
    }

    //69 X的平方跟
    int mySqrt(int x) {
        if (x == 1)
            return 1;
        long long y = x;
        long long left = 0, right = y;
        while (left * left < y && right * right > y && left < right) {
            long long  middle = (left + right) / 2;
            if (middle * middle < y)
                left = middle;
            else if(middle * middle > y)
                right = middle;
            else
                return (int)middle;
            if ((left + 1) == right)
                break;
        }
        return left;
    }

    //70 爬楼梯
    int climbStairs(int n) {
        // vector<int > vec(n);
        // vec[0] = 1;
        // vec[1] = 2;
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;

        int preOne = 2, preTwo = 1, res = 0;
        for (int i = 0; i < n - 2; ++i) {
            res = preOne + preTwo;
            preTwo = preOne;
            preOne = res;
        }
        return res;
    }

    //74 搜索二维矩阵
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if (rows <= 0)
            return false;
        int cols = matrix[0].size();
        if (cols <= 0)
            return false;
        if (matrix[0][0] == target)
            return true;
        int up = 0, down = rows;
        while ((up + 1) < down) {
            int middle = (up + down) / 2;
            if (target < matrix[middle][0])
                down = middle;
            else if (target > matrix[middle][0])
                up = middle;
            else
                return true;
        }
        int left = 0, right = cols;
        while ((left + 1) < right) {
            int middle = (left + right) / 2;
            if (target < matrix[up][middle])
                right = middle;
            else if (target > matrix[up][middle])
                left = middle;
            else
                return true;
        }
        return false;
    }

    //75 颜色分类
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, cur = 0;
        while (cur <= right) {
            if (nums[cur] == 0)
                swap(nums[cur++], nums[left++]);
            else if (nums[cur] == 1)
                ++cur;
            else if (nums[cur] == 2)
                swap(nums[cur], nums[right--]);
        }
    }

    //76 最小覆盖字串
    string minWindow(string s, string t) {
        vector<int> charHash(128, 0);
        for (int i = 0; i < t.size(); ++i) {
            charHash[t[i]]++;
        }

        int i = 0, j = 0, left = 0, right = t.size() - 1, minLen = s.size() + 1, count = t.size();
        while (j < s.size()) {
            if (charHash[s[j]] > 0) {
                count--;
            }
            charHash[s[j]]--;
            j++;
            while (count == 0) {
                if (j - i <= minLen) {
                    minLen = j - i;
                    right = j;
                    left = i;
                }
                charHash[s[i]]++;
                if (charHash[s[i]] > 0)
                    count++;
                i++;
            }
        }
        string res;
        for (int i = left; i < right; ++i)
            res += s[i];
        cout<<"left: "<<left<<" "<<"right: "<<right<<" minLen: "<<minLen<<endl;
        return minLen == s.size() + 1 ? "" : res;
    }

    //77 组合
    vector<vector<int>> combine(int n, int k) {
        vector<int > nums;
        for(int i = 1; i <= n; ++i)
            nums.emplace_back(i);
        vector<int > bin(n, 0);
        for (int i = n - 1, j = 0; j < k; --i, j++)
            bin[i] = 1;
        vector<vector<int>> res;
        do  {
            vector<int > resTemp;
            for (int i = 0; i < bin.size(); ++i) {
                if (bin[i] == 1)
                    resTemp.emplace_back(nums[i]);
            }
            res.emplace_back(resTemp);
        } while (next_permutation(bin.begin(), bin.end()));
        return res;
    }

    //78 子集
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        for (int i = 0; i < (1 << nums.size()); ++i) {
            vector<int > temp;
            for (int j = 0; j < nums.size(); ++j) {
                if ((i & (1 << j)) != 0)
                    temp.emplace_back(nums[j]);
            }
            res.emplace_back(temp);
        }
        return res;
    }

    //79 单词搜索
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = 0;
        if (row > 0)
            col = board[0].size();
        vector<vector<int>> visit(row, vector<int>(col, 0));
        bool res = false;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == word[0]) {
                    res = exist(board, visit, word, 0, i, j);
                }
                if (res)
                    return true;
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, vector<vector<int>>& visit, string& word, int index, int i, int j) {
        if (index == word.size()) {
            return true;
        }
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
            return false;
        bool res = false;
        if (visit[i][j] == 0 && board[i][j] == word[index]) {
            visit[i][j] = 1;
            res = exist(board, visit, word, index + 1, i, j + 1) ||
                  exist(board, visit, word, index + 1, i + 1, j) ||
                  exist(board, visit, word, index + 1, i, j - 1) ||
                  exist(board, visit, word, index + 1, i - 1, j);
            visit[i][j] = 0;
        }
        return res;
    }

    //80 删除数组中重复序列
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (auto num: nums) {
            if (i < 2 || nums[i - 2] != num)
                nums[i++] = num;
        }
        return i;
    }

    //81 搜索旋转数组
    bool search(vector<int>& nums, int target) {
        if (nums.empty())
            return false;
        int index = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target)
                return true;
            if (i - 1 >= 0 && nums[i - 1] < nums[i])
                index = i;
        }

        int left = index + 1, right = nums.size() - 1;

        while (left + 1 < right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target)
                right = mid;
            else if (nums[mid] < target)
                left = mid;
            else
                return true;
        }
        return false;

    }

    //82 删除链表中重复元素 (重复的全不要啦)
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        ListNode* pHead = new ListNode(-1);
        pHead->next = head;
        ListNode *p = head;
        ListNode *pPre = pHead;
        while (p != nullptr && p->next != nullptr) {
            ListNode *pTemp = pPre;
            bool same = false;
            while (p != nullptr && p->next != nullptr && p->val == p->next->val) {
                p = p->next;
                same = true;
            }
            // pPre = p;
            if (same) {
                p = p->next;
                pPre->next = p;
            } else {
                pPre = p;
                p = p->next;
            }

        }
        return pHead->next;
    }

    //83 删除链表中重复元素 (重复的留一个)
    ListNode* deleteDuplicates2(ListNode* head) {
        ListNode* pHead = head;
        while (pHead != nullptr) {
            while (pHead->next != nullptr && pHead->val == pHead->next->val) {
                pHead->next = pHead->next->next;
            }
            pHead = pHead->next;
        }
        return head;
    }

    //84 柱状图最大矩形
    int largestRectangleArea2(vector<int>& heights) {
        if(heights.size()==0) return 0;
        int s[heights.size()+1] = {};
        int top = -1;
        int ret = 0;
        s[++top] = -1;//放入一个 -1 是为了方便栈里面只有一个元素的情况。
        for(int i = 0;i<heights.size();++i){
            if(top==0){
                s[++top] = i;
                continue;
            }
            while(top!=0&&heights[i]<heights[s[top]]){
                int n = heights[s[top--]];//要出栈的数字
                int res = n * (i - 1 - s[top]);//计算得到的高度
                ret  = max (ret , res);
            }
            s[++top] = i;
        }
        while(top!=0){//处理栈中剩余的元素。。这里当前下标应该为 heights .size()
            int n = heights[s[top--]];
            int res = n * (heights.size() - 1 - s[top]);
            ret  = max (ret , res);
        }
        return ret;
    }

    //85 最大矩形
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = 0;
        if (rows > 0)
            cols = matrix[0].size();
        vector<int > heights(cols, 0);
        int maxR = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '0')
                    heights[j] = 0;
                else
                    heights[j]++;
            }
            // for (auto i: heights)
            //     cout<<i<<" ";
            // cout<<"------";
            maxR = max(largestRectangleArea(heights), maxR);
        }


        return maxR;
    }

    int largestRectangleArea(vector<int>& heights) {
        return largestRectangleAreaCore(heights, 0, heights.size() - 1);
    }

    int largestRectangleAreaCore(vector<int>& heights, int left, int right) {
        if (left > right)
            return 0;

        int minIndex = left;
        for (int i = left + 1; i <= right; ++i) {
            if (heights[minIndex] > heights[i]) {
                minIndex = i;
            }
        }

        int maxCur = (right - left + 1) * heights[minIndex];
        int maxLeft = largestRectangleAreaCore(heights, left, minIndex - 1);
        int maxRight = largestRectangleAreaCore(heights, minIndex + 1, right);

        return max(maxCur, max(maxLeft, maxRight));
    }

    //86 分割链表
    ListNode* partition(ListNode* head, int x) {
        ListNode *first = new ListNode(-1);
        first->next = head;
        ListNode *pHead = head;
        ListNode *lessThanX = first;
        ListNode *pPre = first;
        while (pHead) {
            while (pHead && pHead->val >= x) {
                pPre = pHead;
                pHead = pHead->next;
            }
            while (pHead && pHead->val < x) {
                ListNode *gh = head;
                if (lessThanX->next == pHead) {
                    lessThanX = pHead;
                    pPre = pHead;
                    pHead = pHead->next;
                } else {
                    ListNode *pTemp = pHead;
                    pHead = pHead->next;
                    pPre->next = pHead;
                    if (lessThanX->next == head) {
                        head = pTemp;
                    }
                    pTemp->next = lessThanX->next;
                    lessThanX->next = pTemp;
                    lessThanX = lessThanX->next;
                }
            }
        }
        return head;
    }

    //88. 合并两个有序数组
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m == 0) {
            nums1 = nums2;
            return;
        }
        if (n == 0)
            return;
        int end = m + n - 1;
        int nums1End = m - 1;
        int nums2End = n - 1;
        while (nums1End >= 0 && nums2End >= 0) {
            if (nums1[nums1End] > nums2[nums2End]) {
                nums1[end--] = nums1[nums1End--];
            } else {
                nums1[end--] = nums2[nums2End--];
            }
        }
        while (nums2End >= 0) {
            nums1[end--] = nums2[nums2End--];
        }
    }

    //90 子集 有重复
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < (1 << nums.size()); ++i) {
            vector<int > temp;
            for (int j = 0; j < nums.size(); ++j) {
                if ((i & (1 << j)) != 0) {
                    if (j > 0 && nums[j] == nums[j - 1] && ((1 << (j - 1)) & i) == 0 ) {
                        temp.clear();
                        break;
                    }
                    temp.emplace_back(nums[j]);
                }
            }
            if (!temp.empty())
                res.emplace_back(temp);
        }
        res.emplace_back(vector<int >());
        return res;
    }

    //91 解码方法
    int numDecodings(string s) {
        int cnt = 0;
        if(s.size() == 0 || (s.size() == 1 && s[0] == '0')) return 0;
        if(s.size() == 1) return 1;
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < s.size(); ++i){
            dp[i+1] = s[i] == '0' ? 0 : dp[i];
            if(i > 0 && (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6'))){
                dp[i+1] += dp[i-1];
            }
        }
        return dp.back();
    }

    //92 反转链表
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == nullptr || (m == n))
            return head;
        ListNode *pHead = new ListNode(-1);
        ListNode *pPre = pHead;
        pHead->next = head;

        for (int i = 1; i < m; ++i) {
            pPre = pPre->next;
        }

        head = pPre->next;
        for (int i = m; i < n; ++i) {
            ListNode *temp = head->next;
            head->next = temp->next;
            temp->next = pPre->next;
            pPre->next = temp;

        }
        return pHead->next;
    }

    //93 二叉树非递归遍历
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr)
            return res;
        std::stack<TreeNode* > stack;
        TreeNode* cur = root;
        while (cur || !stack.empty()) {
            if (cur->left) {
                stack.emplace(cur);
                cur = cur->left;
            } else {
                res.emplace_back(cur->val);
                cur = cur->right;
                while (!cur && !stack.empty()) {
                    cur = stack.top();
                    res.emplace_back(cur->val);
                    stack.pop();
                    cur = cur->right;
                }
            }
        }
        return res;
    }

    //95 不同的二叉搜索树
    int numTrees(int n) {
        vector<int > dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i < n + 1; ++i) {
            for (int j = 1; j < i + 1; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }

    //97. 交错字符串
    bool isInterleave(string s1, string s2, string s3) {
        if ((s1.size() + s2.size()) != s3.size())
            return false;

        vector<vector<bool >> dp(s1.size() + 1, vector<bool >(s2.size() + 1));
        for (int i = 0; i <= s1.size(); ++i) {
            for (int j = 0; j <= s2.size(); ++j) {
                if (i == 0 && j == 0)
                    dp[i][j] = true;
                else if (i == 0 && j != 0)
                    dp[i][j] = dp[i][j - 1] && s3[i + j - 1] == s2[j - 1];
                else if (j == 0 && i != 0)
                    dp[i][j] = dp[i - 1][j] && s3[i + j - 1] == s1[i - 1];
                else
                    dp[i][j] = (dp[i][j - 1] && s3[i + j - 1] == s2[j - 1]) || (dp[i - 1][j] && s3[i + j - 1] == s1[i - 1]);
            }
        }

        return dp[s1.size()][s2.size()];

    }

    //98. 验证二叉搜索树
    bool isValidBST(TreeNode* root) {
        if (root == nullptr)
            return true;
        vector<int > vec;
        isValidBSTCore(root, vec);
        int tmp = vec[0];
        for (int i = 1; i < vec.size(); ++i) {
            if (vec[i] > tmp) {
                tmp = vec[i];
            } else
                return false;
        }
        return true;
    }

    void isValidBSTCore(TreeNode* root, vector<int > &vec) {
        if (root == nullptr)
            return;
        isValidBSTCore(root->left, vec);
        vec.emplace_back(root->val);
        isValidBSTCore(root->right, vec);
    }

    //99. 恢复二叉搜索树
    TreeNode* pre, *t1, *t2;
    void recoverTree(TreeNode* root) {
        if (root == nullptr)
            return;
        recoverTreeCore(root);
        // pre = t1;
        // t1 = t2;
        // t2 = pre;
        int tmp = t1->val;
        t1->val = t2->val;
        t2->val = tmp;
    }

    void recoverTreeCore(TreeNode* root) {
        if (root == nullptr)
            return;
        recoverTreeCore(root->left);
        if (pre != nullptr && pre->val > root->val) {
            if (t1 == nullptr)
                t1 = pre;
            t2 = root;
        }
        pre = root;
        recoverTreeCore(root->right);
    }

    //100. 相同的树
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return isSameTreeCore(p, q);
    }

    bool isSameTreeCore(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr)
            return true;

        if ((p == nullptr || q == nullptr) || p->val != q->val)
            return false;

        return isSameTreeCore(p->left, q->left) &&
               isSameTreeCore(p->right, q->right);
    }

    //101. 对称二叉树
    bool isSymmetric(TreeNode* root) {
        return isSymmetricCore(root, root);
    }

    bool isSymmetricCore(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr)
            return true;
        if (left == nullptr || right == nullptr)
            return false;
        return left->val == right->val &&
               isSymmetricCore(left->left, right->right) && isSymmetricCore(left->right, right->left);
    }

    //102. 二叉树的层次遍历
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(TreeNode* root) {
        levelOrderCore(root, 0);
        return res;
    }

    void levelOrderCore(TreeNode* root, int depth) {
        if (root == nullptr)
            return;
        if (depth >= res.size())
            res.emplace_back(vector<int >());
        res[depth].emplace_back(root->val);
        levelOrderCore(root->left, ++depth);
        --depth;
        levelOrderCore(root->right, ++depth);
    }

    //103 二叉树的锯齿形层次遍历
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        levelOrderCore2(root, 0);
        for (int i = 0; i < res.size(); ++i) {
            if (i & 1 == 1) {
                reverse(res[i].begin(), res[i].end());
            }
        }
        return res;
    }

    void levelOrderCore2(TreeNode* root, int depth) {
        if (root == nullptr)
            return;
        if (depth >= res.size())
            res.emplace_back(vector<int >());
        res[depth].emplace_back(root->val);
        levelOrderCore2(root->left, ++depth);
        --depth;
        levelOrderCore2(root->right, ++depth);
    }

    //104. 二叉树的最大深度
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return max(leftDepth, rightDepth) + 1;
    }

    //105. 从前序与中序遍历序列构造二叉树
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return pre_order(0, preorder.size() - 1, 0, inorder.size() - 1, preorder, inorder);
    }

    TreeNode* pre_order(int pre_left, int pre_right, int in_left, int in_right,
                        vector<int > &preorder, vector<int > &inorder) {
        if (pre_left > pre_right || in_left > in_right)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[pre_left]);
        int root_in_in = in_left;
        while (root_in_in < in_right && inorder[root_in_in] != preorder[pre_left])
            ++root_in_in;
        int left = root_in_in - in_left;
        root->left = pre_order(pre_left + 1, pre_left + left, in_left, root_in_in - 1, preorder, inorder);
        root->right = pre_order(pre_left + left + 1, pre_right, root_in_in + 1, in_right, preorder, inorder);
        return root;
    }

    //106. 从中序与后序遍历序列构造二叉树
    TreeNode* buildTree2(vector<int>& inorder, vector<int>& postorder) {
        return pre_order(0, inorder.size() - 1, 0, postorder.size() - 1, inorder, postorder);
    }

    TreeNode* pre_order2(int in_left, int in_right, int post_left, int post_right,
                        vector<int > &inorder, vector<int > &postorder) {
        if (post_left > post_right || in_left > in_right)
            return nullptr;
        TreeNode *root = new TreeNode(postorder[post_right]);
        int root_in_in = in_left;
        while (root_in_in < in_right && inorder[root_in_in] != postorder[post_right])
            ++root_in_in;
        int left = root_in_in - in_left;
        int right = in_right - root_in_in;

        //right
        // root->left = pre_order(in_left, root_in_in - 1, post_left, post_right - right - 1, inorder, postorder);
        // root->right = pre_order(root_in_in + 1, in_right, post_right - right, post_right - 1, inorder, postorder);

        //left
        root->left = pre_order2(in_left, root_in_in - 1, post_left, post_left + left - 1, inorder, postorder);
        root->right = pre_order2(root_in_in + 1, in_right, post_left + left, post_right - 1, inorder, postorder);

        return root;
    }

    //108. 将有序数组转换为二叉搜索树
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTCore(nums, 0, nums.size() - 1);
    }

    TreeNode* sortedArrayToBSTCore(vector<int>& nums, int left, int right) {
        if (left > right)
            return nullptr;
        int middle = (left + right) / 2;
        TreeNode* root = new TreeNode(nums[middle]);
        root->left = sortedArrayToBSTCore(nums, left, middle - 1);
        root->right = sortedArrayToBSTCore(nums, middle + 1, right);
        return root;
    }

    //109. 有序链表转换二叉搜索树
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode *p = head;
        vector<int> nums;
        while(p) {
            nums.emplace_back(p->val);
            p = p->next;
        }
        return sortedArrayToBSTCore(nums, 0, nums.size() - 1);
    }

    //110. 判断平衡二叉树
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;
        // int left = depth(root->left);
        // int right = depth(root->right);
        // if (left == -1 || right == -1)
        // return false;
        return depth(root) != -1;
    }

    int depth(TreeNode* root) {
        if (root == nullptr)
            return 1;
        int left = depth(root->left);
        int right = depth(root->right);

        if ((abs(left - right) > 1) || left == -1 || right == -1)
            return -1;
        else
            return max(left, right) + 1;
    }

    //111. 二叉树的最小深度
    int minlevel = -1;
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        minDepthCore(root, 1);
        return minlevel;
    }

    void minDepthCore(TreeNode* root, int depth) {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr) {
            if (minlevel == -1)
                minlevel = depth;
            else
                minlevel = min(minlevel, depth);
        }
        minDepthCore(root->left, depth + 1);
        minDepthCore(root->right, depth + 1);
    }

    //112. 路径总和
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr)
            return false;

        if (root->left == nullptr && root->right == nullptr) {
            return sum - root->val == 0;
        }

        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
    //113. 路径总和 II 要结果
    vector<vector<int>> res113;
    vector<int> temp;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        pathSumCore(root, sum);
        return res113;
    }

    void pathSumCore(TreeNode* root, int sum) {
        if (root == nullptr)
            return;
        temp.emplace_back(root->val);
        if (root->left == nullptr && root->right == nullptr && sum - root->val == 0) {
            res113.emplace_back(temp);
        }
        pathSumCore(root->left, sum - root->val);
        pathSumCore(root->right, sum - root->val);
        temp.pop_back();
    }

    //114. 二叉树展开为链表
    TreeNode* last = nullptr;
    void flatten(TreeNode* root) {
        if (root == nullptr)
            return;
        if (last != nullptr) {
            last->left = nullptr;
            last->right = root;
        }
        last = root;
        TreeNode* tempRight = root->right;
        flatten(root->left);
        flatten(tempRight);
    }

    //115. 不同的子序列
    int numDistinct(string s, string t) {
        vector<vector<long >> dp(t.size() + 1, vector<long >(s.size() + 1, 0));

        for (int i = 0; i <= s.size(); ++i)
            dp[0][i] = 1;

        for (int i = 1; i <= t.size(); ++i) {
            for (int j = 1; j <= s.size(); ++j) {
                dp[i][j] = dp[i][j - 1];
                if (s[j-1] == t[i-1])
                    dp[i][j] += dp[i - 1][j - 1];
            }
        }
        return dp[t.size()][s.size()];
    }

    //116. 填充每个节点的下一个右侧节点指针
    vector<vector<Node*>> res116;
    Node* connect(Node* root) {
        if (root == nullptr)
            return nullptr;
        connectCore(root, 0);
        for (auto tree: res116) {
            for (int i = 0; i < tree.size() - 1; ++i)
                tree[i]->next = tree[i + 1];
        }
        return root;
    }
    void connectCore(Node* root, int level) {
        if (root == nullptr)
            return;
        if (level >= res116.size())
            res116.emplace_back(vector<Node*>());
        res116[level].emplace_back(root);
        connectCore(root->left, level + 1);
        connectCore(root->right, level + 1);
    }

    Node* connect2(Node* root) {
        if (!root || !root->left) {
            return root;
        }
        root->left->next = root->right;
        if (root->next) {
            root->right->next = root->next->left;
        }
        connect(root->left);
        connect(root->right);
        return root;
    }

    //117. 填充每个节点的下一个右侧节点指针 II
    vector<vector<Node*>> res117;
    Node* connect3(Node* root) {
        if (root == nullptr)
            return nullptr;
        connectCore(root, 0);
        for (auto tree: res117) {
            for (int i = 0; i < tree.size() - 1; ++i)
                tree[i]->next = tree[i + 1];
        }
        return root;
    }

    //118. 杨辉三角
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int > n1 = {1};
        vector<int > n2 = {1,1};
        if (numRows == 0)
            return res;
        if (numRows == 1) {
            res.emplace_back(n1);
            return res;
        }
        if (numRows == 2) {
            res.emplace_back(n1);
            res.emplace_back(n2);
            return res;
        }
        res.emplace_back(n1);
        res.emplace_back(n2);

        for (int i = 0; i < numRows - 2; ++i) {
            vector<int > temp(3+i);
            temp[0] = 1;
            temp[2 + i] = 1;
            for (int j = 1; j < 2 + i; ++j) {
                temp[j] = res.back()[j - 1] + res.back()[j];
            }
            res.emplace_back(temp);
        }
        return res;
    }

    //119. 杨辉三角 II
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> res;
        vector<int > n1 = {1};
        vector<int > n2 = {1,1};
        if (rowIndex == 0)
            return n1;
        if (rowIndex == 1) {
            return n2;
        }
        res.emplace_back(n1);
        res.emplace_back(n2);

        for (int i = 0; i < rowIndex - 1; ++i) {
            vector<int > temp(3+i);
            temp[0] = 1;
            temp[2 + i] = 1;
            for (int j = 1; j < 2 + i; ++j) {
                temp[j] = res.back()[j - 1] + res.back()[j];
            }
            res.emplace_back(temp);
        }
        return res.back();
    }

    //120. 三角形最小路径和
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0)
            return 0;
        int size = triangle.size();
        vector<int > dp(triangle[size - 1].size());
        cout<<triangle[size - 1].size();
        for (int i = size - 1; i >= 0; --i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                if (i == size - 1)
                    dp[j] = triangle[i][j];
                else {
                    dp[j] = min(triangle[i][j] + dp[j], triangle[i][j] + dp[j + 1]);
                }
            }
        }
        return dp[0];
    }

    //121. 买卖股票的最佳时机
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if (size == 0)
            return 0;
        int res = 0;
        int dp = 0;
        dp = prices[0];
        for (int i = 1; i < size; ++i) {
            dp = min(dp, prices[i]);
            res = max(prices[i] - dp, res);
        }
        return res;

    }

};
#endif //GH_CODE_LEETCODE_H
