//
// Created by gh on 19-1-22.
//

#include "apueLearn.h"
#include <dirent.h>
extern "C" {
#include "apue.h"
}
namespace apue {
    int ls(int argc, char* argv[]) {
        DIR *dp;
        struct dirent *dirp;
        if (argc!=2)
            err_quit("usage: ls directory_name");
        if((dp = opendir(argv[1])) == nullptr)
            err_sys("cant open %s", argv[1]);
        while ((dirp = readdir(dp)) != nullptr)
            printf("%s\n", dirp->d_name);
        closedir(dp);
        exit(0);
    }
}