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

//    void testFork() {
//        pid_t  pid;
//        TELL_WAIT();
//        if ((pid = fork()) < 0) {
//            err_sys("fork error");
//        } else if(pid == 0) {
//            WAIT_PARENT();
//            apue::charatatime("output from child\n");
//        } else {
//            apue::charatatime("output from parent\n");
//            TELL_CHILD(pid);
//        }
//        exit(0);
//    }

//    void *helper(void * arg) {
//        int n;
//        struct mymesg m;
//        struct threadinfo *tip = static_cast<threadinfo *>(arg);
//        for(;;) {
//            memset(&m, 0, sizeof(m));
//            if ((n = msgrcv(tip->qid, &m, MAXSZ, 0, MSG_NOERROR)) < 0)
//                err_sys("msgrcv error");
//            if (write(tip->fd, m.mtext, n) < 0)
//                err_sys("write error");
//        }
//    }
//
//    void recive() {
//        int i, n, err;
//        int fd[2];
//        int qid[NQ];
//        struct pollfd pfd[NQ];
//        struct threadinfo ti[NQ];
//        pthread_t tid[NQ];
//        char buf[MAXSZ];
//
//        for (i = 0; i < NQ; i++) {
//            if ((qid[i] = msgget((KEY+i), IPC_CREAT|0666)) < 0)
//                err_sys("msgget error");
//            printf("queue ID %d is %d\n", i, qid[i]);
//
//            if (socketpair(AF_UNIX, SOCK_DGRAM, 0, fd) < 0)
//                err_sys("socketpair error");
//            pfd[i].fd = fd[0];
//            pfd[i].events = POLLIN;
//            ti[i].qid = qid[i];
//            ti[i].fd = fd[1];
//            if ((err = pthread_create(&tid[i], NULL, helper, &ti[i])) != 0)
//                err_exit(err, "pthread_create error");
//        }
//
//        for (;;) {
//            if (poll(pfd, NQ, -1) < 0)
//                err_sys("poll error");
//            for(i = 0; i < NQ; i++) {
//                if (pfd[i].revents & POLLIN) {
//                    if ((n = read(pfd[i].fd, buf, sizeof(buf))) < 0)
//                        err_sys("read error");
//                    buf[n] = 0;
//                    printf("queue id %d, message %s\n", qid[i], buf);
//                }
//            }
//        }
//    }
//
//    void send(int argc, char* argv[]) {
//        key_t key;
//        long qid;
//        size_t nbytes;
//        struct mymesg m;
//
//        if (argc != 3) {
//            fprintf(stderr, "usage: sendmsg KEY message\n");
//            exit(1);
//        }
//
//        key = strtol(argv[1], NULL, 0);
//        if ((qid = msgget(key, 0)) < 0)
//            err_sys("can't open queue key %s", argv[1]);
//        memset(&m, 0, sizeof(m));
//        strncpy(m.mtext, argv[2], MAXSZ - 1);
//        nbytes = strlen(m.mtext);
//        m.mtype = 1;
//        if (msgsnd(qid, &m, nbytes, 0) < 0)
//            err_sys("can't send message");
//        exit(0);
//    }
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