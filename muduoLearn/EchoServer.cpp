//
// Created by gh on 2019/8/1.
//

#include <syslog.h>
#include <iostream>
#include "EchoServer.h"

EchoServer::EchoServer(muduo::net::EventLoop *loop, const muduo::net::InetAddress &listenAddr):
                    loop_(loop), server_(loop, listenAddr, "EchoServer"){
    server_.setConnectionCallback(std::bind(&EchoServer::onConnection, this, std::placeholders::_1));
    server_.setMessageCallback(std::bind(&EchoServer::onMessage, this, std::placeholders::_1,
                                         std::placeholders::_2, std::placeholders::_3));
}

void EchoServer::start() {
    server_.start();
}

void EchoServer::onConnection(const muduo::net::TcpConnectionPtr &conn) {
    std::cout << "EchoServer - " << conn->peerAddress().toIpPort() << " -> " <<conn->localAddress().toIpPort()
        << " is " <<(conn->connected() ? "UP" : "DOWN");
}

void EchoServer::onMessage(const muduo::net::TcpConnectionPtr &conn, muduo::net::Buffer *buf, muduo::Timestamp time) {
    muduo::string msg(buf->retrieveAllAsString());
    std::cout<<conn->name()<<" echo "<<msg.size()<<" bytes, "<<" data receive at "<<time.toString()<<std::endl;
    conn->send(msg);
}
