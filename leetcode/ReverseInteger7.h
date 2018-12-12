//
// Created by 78455 on 2018/10/19.
//

#ifndef LEETCODECPLUSPLUS_REVERSEINTEGER7_H
#define LEETCODECPLUSPLUS_REVERSEINTEGER7_H

#include <iostream>
#include <climits>

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }

    int reverse2(int x)
    {

        int result(0);

        while (x != 0){
            if ( (INT_MAX/10) < result  || (INT_MIN/10) > result){
                return 0;
            }
            result = result*10 + x%10;
            x = x/10;
        }

        return result;
    }

};


#endif //LEETCODECPLUSPLUS_REVERSEINTEGER7_H

/*
 * Given a 32-bit signed integer, reverse digits of an integer.
Example 1:
Input: 123
Output: 321
Example 2:
Input: -123
Output: -321
Example 3:
Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
 * */