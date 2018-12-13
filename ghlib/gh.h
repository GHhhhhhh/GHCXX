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

    template <typename returnType, typename func, typename... args>
    returnType functime(func _func, args... _args) {
        double time1 = gh::current_time();
        returnType returnType1 = _func(_args...);
        double time2 = gh::current_time();
        gh::print("function time: ", time2 - time1);
        return returnType1;
    }


    template <typename func, typename... args>
    void functime(func _func, args... _args) {
        double time1 = gh::current_time();
        _func(_args...);
        double time2 = gh::current_time();
        gh::print("function time: ", time2 - time1);
    }

}

#endif //GH_CODE_GH_H
