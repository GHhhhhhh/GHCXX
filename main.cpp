#include <iostream>
#include <algorithm>
#include <dirent.h>
#include <sys/wait.h>
#include <set>
#include <fcntl.h>
#include <Constructor.h>
#include <memory>
//#include "apueLearn.h"
//#include "unpLearn.h"
#include "ghlib/gh.h"
#include "SwordToOffer/Interview.h"
#include "apue.h"
using namespace std;
using namespace swordToOffer;


int main(int argc, char* argv[]) {
    int n;
    int fd[2];
    pid_t pid;
    char line[MAXLINE];
    if (pipe(fd) < 0)
        err_sys("pipe error");
    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid > 0) {
        close(fd[1]);
        n = read(fd[0], line, MAXLINE);
        printf("father: ");
        write(STDOUT_FILENO, line, n);

    } else if (pid == 0){
        close(fd[0]);
        printf("child: ");
        write(fd[1], "hello world\n", 12);
        printf("write finished\n");
    }
    exit(0);
}


//889##24##7##7## 89##2##  1248##9##50##1##362##3##74##5##
