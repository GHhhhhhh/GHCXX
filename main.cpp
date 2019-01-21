#include <iostream>
#include <algorithm>
#include "ghlib/gh.h"
#include "SwordToOffer/Interview.h"
#include "apue.h"
#include "unp.h"
using namespace std;
using namespace swordToOffer;
int main(int argc, char* argv[]) {
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

