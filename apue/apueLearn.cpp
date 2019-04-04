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

    void charatatime(char *str) {
        char *ptr;
        int c;
        setbuf(stdout, NULL);
        for (ptr = str; (c = *ptr++)!=0;)
            putc(c, stdout);
    }

    void testFork() {
        pid_t  pid;
        TELL_WAIT();
        if ((pid = fork()) < 0) {
            err_sys("fork error");
        } else if(pid == 0) {
            WAIT_PARENT();
            apue::charatatime("output from child\n");
        } else {
            apue::charatatime("output from parent\n");
            TELL_CHILD(pid);
        }
        exit(0);
    }
}

//int globvar = 6;
//char buf[] = "a write to stdout\n";
//int main(int argc, char* argv[]) {
//    int var;
//    pid_t pid;
//    var = 88;
//    if (write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) -1)
//        err_sys("write error");
//    printf("before fork\n");
//    if ((pid = fork()) < 0) {
//        err_sys("fork error");
//    } else if (pid == 0) {
//        globvar++;
//        var++;
//    } else {
//        sleep(2);
//    }
//    printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);
//    exit(0);
//}