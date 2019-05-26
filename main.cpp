#include <iostream>
#include <algorithm>
#include <dirent.h>
#include <sys/wait.h>
#include <set>
#include <fcntl.h>
#include <Constructor.h>
#include <memory>
#include <netdb.h>
#include <values.h>
#include <poll.h>
#include <sys/msg.h>
#include <sys/socket.h>
//#include "apueLearn.h"
//#include "unpLearn.h"
#include "ghlib/gh.h"
#include "SwordToOffer/Interview.h"
#include "apue.h"
#include "LeetCode.h"
using namespace std;
using namespace swordToOffer;
using namespace LC;

class A {
public:
    ~A() {gh::print("A");}
    int i;
    void func() {gh::print("Hahahaha");}
};

void say(A &a) {}

int func(int left, int i) {
    int miun = left - i;
    if (miun == 0) {
        return i;
    }
    int k1 = i, k2 = i;
    if (miun >= i * 2)
        k1 = func(miun, i * 2);
    if (miun >= i * 2 + 1)
        k2 = func(miun, i * 2 + 1);

    return k2 > k1 ? k2: k1;

}
//100 382 1 12345




int main(int argc, char* argv[]) {
    Solution solution;
//    vector<int > vec = {2,2,1,1};
//    vector<vector<int >> matrix = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
//    vector<vector<int >> matrix2 = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
//    vector<string> vec = {"", "eat", "tea", "tan", "ate", "nat", "bat", ""};
//    vector<string> vec = {"tea","","eat","","tea",""};
    vector<string> vec = {"ray","cod","abe","ned","arc","jar","owl","pop","paw","sky","yup","fed","jul","woo","ado","why","ben","mys","den","dem","fat","you","eon","sui","oct","asp","ago","lea","sow","hus","fee","yup","eve","red","flo","ids","tic","pup","hag","ito","zoo"};
    auto xx = solution.groupAnagrams(vec);
//    gh::print(jump(vector1));
    cout<<endl;
}


//889##24##7##7## 89##2##  1248##9##50##1##362##3##74##5##
