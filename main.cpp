#include <iostream>
#include <algorithm>
#include <dirent.h>
#include <thread>
#include <cstring>
#include <values.h>
#include "apueLearn.h"
#include "unpLearn.h"
#include <unordered_map>
#include "ghlib/gh.h"
#include "SwordToOffer/Interview.h"
#include "EchoServer.h"
#include <muduo/base/Logging.h>
#include <muduo/net/EventLoop.h>
#include <unp.h>

using namespace std;
using namespace swordToOffer;


const char *g_file = NULL;
string readFile(const char* filename) {
    string content;
    FILE* fp = ::fopen(filename, "rb");
    if (fp)
    {
        // inefficient!!!
        const int kBufSize = 1024*1024;
        char iobuf[kBufSize];
        ::setbuffer(fp, iobuf, sizeof iobuf);

        char buf[kBufSize];
        size_t nread = 0;
        while ( (nread = ::fread(buf, 1, sizeof buf, fp)) > 0)
        {
            content.append(buf, nread);
        }
        ::fclose(fp);
    }
    return content;
}
void onConnection(const muduo::net::TcpConnectionPtr& conn) {
    LOG_INFO << "EchoServer - " << conn->peerAddress().toIpPort() << " -> " <<conn->localAddress().toIpPort()
              << " is " <<(conn->connected() ? "UP" : "DOWN");
    if (conn->connected()) {
        LOG_INFO<< "fileServer - Sending file "<<g_file<<" to "<<conn->peerAddress().toIpPort();
        string fileContent = readFile(g_file);
        conn->send(fileContent);
        conn->shutdown();
        LOG_INFO<<"FileServer - done";
    }
}
int main(int argc, char* argv[], char** envp) {
    if (argc > 1) {
        g_file = argv[1];
        muduo::net::EventLoop loop;
        muduo::net::InetAddress listenAddr(2021);
        muduo::net::TcpServer server(&loop, listenAddr, "FileServer");
        server.setConnectionCallback(onConnection);
        server.start();
        loop.loop();
    }
}

//889##24##7##7## 89##2##
//
//[1  3  -1] -3  5  3  6  7       3
//1 [3  -1  -3] 5  3  6  7       3
//1  3 [-1  -3  5] 3  6  7       5
//1  3  -1 [-3  5  3] 6  7       5
//1  3  -1  -3 [5  3  6] 7       6
//1  3  -1  -3  5 [3  6  7]      7