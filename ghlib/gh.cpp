//
// Created by GH on 2018/11/25.
//

#include <cstring>
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