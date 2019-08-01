//
// Created by gh on 2019/8/1.
//

#ifndef GH_CODE_ECHOSERVER_H
#define GH_CODE_ECHOSERVER_H

#include <muduo/net/TcpServer.h>

class EchoServer {
public:
    EchoServer(muduo::net::EventLoop *loop,
               const muduo::net::InetAddress& listenAddr);
    void start();

private:
    void onConnection(const muduo::net::TcpConnectionPtr& conn);

    void onMessage(const muduo::net::TcpConnectionPtr& conn,
                    muduo::net::Buffer *buf,
                    muduo::Timestamp time);

    muduo::net::EventLoop* loop_;
    muduo::net::TcpServer server_;
};


#endif //GH_CODE_ECHOSERVER_H
