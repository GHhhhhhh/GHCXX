#include <iostream>
#include <algorithm>
#include <dirent.h>
#include <sys/wait.h>
#include <set>
#include "apueLearn.h"
#include "unpLearn.h"
#include "ghlib/gh.h"
#include "SwordToOffer/Interview.h"
#include "apue.h"
using namespace std;
using namespace swordToOffer;
char *env_init[] = {"USER=gh", "PATH=/home/gh/Desktop/gh_code/GHCXX/cmake-build-debug/", NULL};
int main(int argc, char* argv[]) {
//    pid_t pid;
//    if ((pid = fork()) < 0) {
//        err_sys("fork error");
//    } else if (pid == 0) {
//        if (execle("/home/gh/Desktop/gh_code/GHCXX/cmake-build-debug/echoall", "echoall", "myarg1", "MY ARG2", (char*)0, env_init) < 0) {
//            err_sys("execle error");
//        }
//    }
//
//    if (waitpid(pid, NULL, 0) < 0)
//        err_sys("wait error");
//    if ((pid = fork()) < 0) {
//        err_sys("fork error");
//    } else if (pid == 0) {
//        if (execlp("echoall", "echoall", "only 1 arg", (char*)0) < 0)
//            err_sys("execlp error");
//    }
//    exit(0);
    char *p;
    p = getlogin();
    if (p == nullptr) {
        err_sys("getlogin error");
    }
    gh::print(p);

}

//889##24##7##7## 89##2##  1248##9##50##1##362##3##74##5##

