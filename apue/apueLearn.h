//
// Created by gh on 19-1-22.
//

#ifndef GH_CODE_APUELEARN_H
#define GH_CODE_APUELEARN_H

#include <poll.h>
//#include <zconf.h>
#include <sys/msg.h>
#include <sys/socket.h>
#include <pthread.h>

#define NQ 3
#define MAXSZ 512
#define KEY 0x123
namespace apue {

    struct threadinfo {
        int qid;
        int fd;
    };

    struct mymesg {
        long mtype;
        char mtext[MAXSZ];
    };


    int ls(int argc, char* argv[]);

    void charatatime(char *str);

    void testFork();

    void *helper(void * arg);

    void recive();

    void send(int argc, char* argv[]);
}
#endif //GH_CODE_APUELEARN_H
