#include <iostream>
#include <algorithm>
#include <dirent.h>
#include <thread>
#include <cstring>
#include <values.h>
#include "apueLearn.h"
#include "unpLearn.h"
#include <unordered_map>
#include "ghlib/gh.h"
#include "SwordToOffer/Interview.h"
using namespace std;
using namespace swordToOffer;

int beibao(vector<int > &weights, vector<int > &values, int bag) {
    vector<int > dp(bag + 1, 0);
    for (int i = 0; i < weights.size(); ++i) {
        for (int j = bag; j >= weights[i]; --j) {
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
        }
    }
    return dp[bag];
}
int main(int argc, char* argv[], char** envp) {
//    gh::GHsingle *gHsingle = gh::GHsingle::getInstance();
    vector<int> v{0, 8, 10, 6, 3, 7, 2};  //价值
    vector<int> w{0, 4, 6, 2, 2, 5, 1};
    gh::print(beibao(w, v, 12));
}

//889##24##7##7## 89##2##
//
//[1  3  -1] -3  5  3  6  7       3
//1 [3  -1  -3] 5  3  6  7       3
//1  3 [-1  -3  5] 3  6  7       5
//1  3  -1 [-3  5  3] 6  7       5
//1  3  -1  -3 [5  3  6] 7       6
//1  3  -1  -3  5 [3  6  7]      7