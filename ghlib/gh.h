//
// Created by GH on 2018/11/25.
//

#ifndef GH_CODE_GH_H
#define GH_CODE_GH_H

#include <iostream>
#include <sys/time.h>
#include <fstream>
namespace gh{
    void print();
    template <typename T, typename... Types>
    void print(const T& firstArg, const Types&... args)
    {
        std::cout<<firstArg<<" ";
        print(args...);
    }

    double current_time();

    std::string get_datetime();

    void executeCMD(const char *cmd, char *result);
}

#endif //GH_CODE_GH_H
