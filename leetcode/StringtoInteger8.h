//
// Created by gh on 18-11-2.
//

#ifndef CPLUSPLUSLEETCODE_STRINGTOINTEGER8_H
#define CPLUSPLUSLEETCODE_STRINGTOINTEGER8_H

#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int result = 0;
        int temp = 0;
        if (str.size() == 0) return 0;
        for(auto i : str) {
            if (i == 32)
                ++temp;
            else
                break;
        }
        if (temp == str.size()) return 0;
        if (str.at(temp) > 57 || (str.at(temp) < 48 && str.at(temp) != 43 && str.at(temp) != 45 && str.at(temp) != 32))
            return 0;
        if (str.at(temp) < 57 && str.at(temp) > 48) {
            if(str.at(temp) == 45)
                result = -(str.at(temp) - 48);
            else
                result = (str.at(temp) - 48);
        }


        for (int i = temp + 1; i < str.size(); ++i) {
            if (str.at(i) <= 57 && str.at(i) >= 48) {
                if (result > INT_MAX/10 || (result == INT_MAX / 10 && str.at(i) - 48 > 7)) return INT_MAX;
                if (result < INT_MIN/10 || (result == INT_MIN / 10) && 48 - str.at(i) < -8) return INT_MIN;
                if (str.at(temp) == 45)
                    result = result * 10 - str.at(i) + 48;
                else
                    result = result * 10 + str.at(i) - 48;
            }
            else
                break;
        }

        return result;
    }

    int myAtoi2(string str) {
        int result = 0;
        int temp = 0;
        if (str.size() == 0) return 0;
        while(str[temp] == ' ' && temp < str.size()) ++temp;
        if (str[temp] == ' ') return 0;

        if (str.at(temp) > 57 || (str.at(temp) < 48 && str.at(temp) != 43 && str.at(temp) != 45 && str.at(temp) != 32))
            return 0;
        if (str.at(temp) < 57 && str.at(temp) > 48) {
            if(str.at(temp) == 45)
                result = -(str.at(temp) - 48);
            else
                result = (str.at(temp) - 48);
        }


        for (int i = temp + 1; i < str.size(); ++i) {
            if (str.at(i) <= 57 && str.at(i) >= 48) {
                if (result > INT_MAX/10 || (result == INT_MAX / 10 && str.at(i) - 48 > 7)) return INT_MAX;
                if (result < INT_MIN/10 || (result == INT_MIN / 10) && 48 - str.at(i) < -8) return INT_MIN;
                if (str.at(temp) == 45)
                    result = result * 10 - str.at(i) + 48;
                else
                    result = result * 10 + str.at(i) - 48;
            }
            else
                break;
        }

        return result;
    }
};

#endif //CPLUSPLUSLEETCODE_STRINGTOINTEGER8_H
