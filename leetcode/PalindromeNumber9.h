//
// Created by gh on 18-11-2.
//

#ifndef CPLUSPLUSLEETCODE_PALINDROMENUMBER9_H
#define CPLUSPLUSLEETCODE_PALINDROMENUMBER9_H

#include <iostream>

using namespace std;
static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        int num[13] = {};
        int index = -1;
        while (x > 0) {
            num[++index] = x%10;
            x /= 10;
        }

        for(int i = 0; i <= index-i;++i) {
            if (num[i] == num[index-i]) continue;
            else return false;
        }
        return true;
    }

    bool isPalindrome2(int x) {
        if (x < 0)
            return false;
        int temp = x;
        int r_x = 0;
        while(temp > 0) {
            r_x = r_x*10 + temp%10;
            temp/=10;
        }
        cout<<r_x<<endl;
        cout<<x<<endl;
        return r_x == x;
    }
};
#endif //CPLUSPLUSLEETCODE_PALINDROMENUMBER9_H
