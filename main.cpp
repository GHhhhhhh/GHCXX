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
#include <muduo/net/TcpServer.h>
#include <muduo/net/TcpConnection.h>
#include <unp.h>
#include "Constructor.h"
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

class A{
public:
    A(){g();}
    virtual ~A(){cout<<"~A()"<<endl;}
    void f() {cout<<"A::f()"<<endl;}
    virtual void g() {cout<<"A::g()"<<endl;}
};

class B:public A{
public:
    B(){g();};
    ~B(){cout<<"~B()"<<endl;}
    void f(){cout<<"B::f()"<<endl;}
    virtual void g(){cout<<"B::g()"<<endl;}
};
void quickSort(vector<int > &vec, int left, int right) {
    if (left > right)
        return;
    int temp = vec[left];
    int i = left, j = right;
    while (i != j) {
        while (i < j && temp <= vec[j])
            --j;
        while (i < j && temp >= vec[i])
            ++i;
        if (i < j) {
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[left], vec[i]);
    quickSort(vec, left, i - 1);
    quickSort(vec, i + 1, right);
}
class Test{
public:
    Test(int a) {cout<<"constructor"<<endl;}
    ~Test() {cout<<"delete"<<endl;}
    Test(Test&& a) {
        cout<<"Move Constructor"<<endl;
    }
    Test& operator=(Test&& a) {
        cout<<"Move Assignment operator"<<endl;
        return *this;
    }
};

class GHString {
public:
    GHString() { _p = new char[9];
                _size = 0;
                _cap = 8;}
    void append(char c) {
        if (_size < _cap) {
            _p[_size] = c;
            _p[_size + 1] = '\n';
            ++_size;
        } else {
            char *del = _p;
            _p = new char[_cap*2 + 1];
            strcpy(_p, del);
            delete[] del;
            _cap *= 2;
            _p[_size] = c;
            _p[_size + 1] = '\n';
            ++_size;
        }
    }
    GHString (GHString& str) {
        if (str._p == this->_p)
            return ;
        if (str._size <= this->_cap) {
            strcpy(this->_p, str._p);
        } else {
            char *del = this->_p;
//            delete[] del;
            this->_p = new char[str._size + 1];
            strcpy(this->_p, str._p);
        }
    }

    char *_p;
private:
    int _size;
    int _cap;
};

int binSearch(vector<int >& nums, int left, int right, int target) {
    while (left <= right) {
        int mid = (left + right) >> 1;
        if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] <= target) {
            left = mid + 1;
        }
    }
    return nums[right] == target ? right : -1;
}

template <typename T>
class SmartPtr{
public:
    explicit SmartPtr(T *p = nullptr) : _p(p){
        if (p) {
            _count = new size_t(1);
        } else {
            _count = new size_t(0);
        }
    }

    SmartPtr(const T& ptr) {
        if (&ptr != this) {
            this->_p = ptr._p;
            this->_count = ptr._count;
            *_count++;
        }
    }

    SmartPtr& operator=(const T& ptr) {
        if (&ptr == this)
            return *this;

        if (this->_p) {
            *this->_count--;
            if (*_count == 0) {
                delete(_p);
                delete(_count);
            }
        }

        this->_p = ptr._p;
        this->_count = ptr._count;
        *_count++;
    }

    T*operator->() {
        assert(_p);
        return _p;
    }

    T&operator*() {
        assert(_p);
        return *_p;
    }
    ~SmartPtr(){
        *_count--;
        if (*_count == 0) {
            delete(_p);
            delete(_count);
        }
    }
private:
    T *_p;
    size_t *_count;
};

class Test2{
public:
    Test2(){*p = 2;}
    void print(){
        cout<<*p<<endl;
        cout<<*this->p<<endl;
    }
private:
    int *p = new int;
};

void func1(int i) {
    cout<<"func1"<<endl;
}

void func2(int i) {
    cout<<"func2"<<endl;
}

class testFunc{
public:
    typedef std::function<void()> func;
    void callback(const func &callback) {
        callback();
    }
    void print(){cout<<"Hahaha\n";}
};
typedef std::function<void(int)> functor;
int g_int = 0;
void print1(){
    cout<<"1\n";
    sleep(2);
    g_int = 1;
}
void newConnection(int sockfd, const muduo::net::InetAddress& peerAddr) {
    printf("newConnection(): accepted a new connection from %s\n", peerAddr.toIpPort().c_str());
    ::write(sockfd, "How are you?\n", 13);
    ::close(sockfd);
}
void preTreeNode(BinaryTreeNode* root) {
    if (root == nullptr)
        return;
    stack<BinaryTreeNode* > stackTrees;
    BinaryTreeNode *p = root;
    while (p || !stackTrees.empty()) {
        while (p->m_pLeft) {
            cout<<p->m_nValue<<endl;
            stackTrees.push(p);
            p = p->m_pLeft;
        }
        if (!stackTrees.empty()) {
            p = stackTrees.top();
            stackTrees.pop();
            stackTrees.push(p->m_pRight);
        }
    }
}


void LastTreeNode(BinaryTreeNode* root) {
    if (root == nullptr)
        return;
    stack<BinaryTreeNode* > stack1;
    BinaryTreeNode *p = root;
    BinaryTreeNode *visitedTreeNode;

    while (p) {
        stack1.push(p);
        p = p->m_pLeft;
    }
    while (!stack1.empty()) {
        p = stack1.top();
        stack1.pop();
        if (p->m_pRight == nullptr || p == visitedTreeNode) {
            cout<<p->m_nValue<<endl;
            visitedTreeNode = p;
        } else {
            stack1.push(p);
            p = p->m_pRight;
            while (p) {
                stack1.push(p);
                p = p->m_pLeft;
            }
        }

    }
}

void levelTravel(BinaryTreeNode* root) {
    if (root == nullptr)
        return;
    deque<BinaryTreeNode*> deque1;
    BinaryTreeNode *p = root;
    deque1.emplace_back(p);
    while (!deque1.empty()) {
        p = *deque1.begin();
        deque1.pop_front();
        cout<<p->m_nValue<<endl;
        if (p->m_pLeft)
            deque1.emplace_back(p->m_pLeft);
        if (p->m_pRight)
            deque1.emplace_back(p->m_pRight);
    }
}

int main(int argc, char* argv[], char** envp) {
    vector<int > vec;
    for (int i = 0; i < 5; ++i) {
        int j;
        cin>>j;
        vec.emplace_back(j);
    }
    for (auto i: vec) {
        cout<<i<<" ";
    }
//    using namespace muduo;
//    using namespace net;
//    printf("main(): pid = %d\n", getpid());
//    muduo::net::InetAddress listenAddr(9981);
//    muduo::net::EventLoop loop;

//    muduo::net::Acceptor acceptor(&loop, listenAddr);
//    acceptor.se



//    if (argc > 1) {
//        g_file = argv[1];
//        muduo::net::EventLoop loop;
//        muduo::net::InetAddress listenAddr(2021);
//        muduo::net::TcpServer server(&loop, listenAddr, "FileServer");
//        server.setConnectionCallback(onConnection);
//        server.start();
//        loop.loop();
//    }
}
