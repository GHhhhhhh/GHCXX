//
// Created by gh on 19-1-22.
//
#include "unpLearn.h"
#include "gh.h"
extern "C" {
    #include "unp.h"
}
namespace unp {
    int SimpleGetTimeClient(int argc, char* argv[]) {
        int sockfd, n;
        char recvline[MAXLINE + 1];

        if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
            gh::print("socket error");
        struct sockaddr_in servaddr;
        bzero(&servaddr, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_port = htons(13);

        if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
            gh::print("inet_pton error for", argv[1]);

        if (connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) < 0)
            gh::print("connect error");
        while ((n = read(sockfd, recvline, MAXLINE)) > 0) {
            recvline[n] = 0;
            if (fputs(recvline, stdout) == EOF)
                gh::print("fputs error");
        }
        if (n < 0)
            gh::print("read error");
        exit(0);
    }
    int SimpleGetTimeSever(int argc, char* argv[]) {
        int					listenfd, connfd;
        struct sockaddr_in	servaddr;
        char				buff[MAXLINE];
        time_t				ticks;

        listenfd = Socket(AF_INET, SOCK_STREAM, 0);

        bzero(&servaddr, sizeof(servaddr));
        servaddr.sin_family      = AF_INET;
        servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
        servaddr.sin_port        = htons(13);	/* daytime server */

        Bind(listenfd, (SA *) &servaddr, sizeof(servaddr));

        Listen(listenfd, LISTENQ);

        for ( ; ; ) {
            connfd = Accept(listenfd, (SA *) NULL, NULL);

            ticks = time(NULL);
            snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
            write(connfd, buff, strlen(buff));

            Close(connfd);
        }
    }
}
