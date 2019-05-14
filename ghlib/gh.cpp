//
// Created by GH on 2018/11/25.
//

#include <cstring>
#include <assert.h>
#include "gh.h"

void gh::print() { std::cout<<std::endl;}

double gh::current_time() {
    struct timeval time{};
    if (gettimeofday(&time, nullptr)){
        return 0;
    }
    return (double)time.tv_sec + (double)time.tv_usec * .000001;
}

std::string gh::get_datetime() {
        char char_time[255];
        time_t Today;
        tm* Time;
        time(&Today);
        Time = localtime(&Today);
        strftime(char_time, 255, "%Y-%m-%d %H:%M:%S",Time);
        std::string time(char_time);
        return time;
}

void gh::executeCMD(const char *cmd, char *result) {
        char buf_ps[1024];
        char ps[1024]={0};
        FILE *ptr;
        strcpy(ps, cmd);
        if((ptr=popen(ps, "r"))!=NULL)
        {
            while(fgets(buf_ps, 1024, ptr)!=NULL)
            {
                strcat(result, buf_ps);
                if(strlen(result)>1024)
                    break;
            }
            pclose(ptr);
            ptr = NULL;
        }
        else
        {
            printf("popen %s error\n", ps);
        }
}


std::list<std::string> gh::split(const std::string& str, const std::string& delim) {
    std::list <std::string> res;
    if ("" == str)
        return res;
    //先将要切割的字符串从string类型转换为char*类型
    char *strs = new char[str.length() + 1]; //不要忘了
    strcpy(strs, str.c_str());

    char *d = new char[delim.length() + 1];
    strcpy(d, delim.c_str());

    char *p = strtok(strs, d);
    while (p) {
        std::string s = p; //分割得到的字符串转换为string类型
        res.push_back(s); //存入结果数组
        p = strtok(NULL, d);
    }

    return res;
}

void* gh::memoryCopy(const void *pSrc, void *pdest, int length) {
    assert(pSrc);
    assert(pdest);
    void *ret = pdest;
    if (pdest <= pSrc || (char*)pdest >= (char*)pSrc + length) {
        while (length--) {
            *(char*)pdest = *(char*)pSrc;
            pdest++;
            pSrc++;
        }
    } else {
        pdest = pdest + length - 1;
        pSrc = pSrc + length - 1;
        while (length--) {
            *(char*)pdest = *(char*)pSrc;
            pdest--;
            pSrc--;
        }
    }
    return ret;
}

void gh::visitVtbl(int **vtbl, int count) {
    using namespace std;
    cout<<vtbl<<endl;
    cout<<"\t[-1]: "<<(long)vtbl[-1]<<endl;

    typedef void (*FuncPtr)();
    for (int i = 0; vtbl[i] && i < count; ++i) {
        cout<<"\t[" << i << "]: " << vtbl[i] << " -> ";
        FuncPtr func = (FuncPtr)vtbl[i];
        func();
    }
}
