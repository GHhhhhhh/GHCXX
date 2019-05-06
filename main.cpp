#include <iostream>
#include <algorithm>
#include <dirent.h>
#include <sys/wait.h>
#include <set>
#include <fcntl.h>
//#include "apueLearn.h"
//#include "unpLearn.h"
#include "ghlib/gh.h"
#include "SwordToOffer/Interview.h"
#include "apue.h"
using namespace std;
using namespace swordToOffer;

char buf[500000];

int main(int argc, char* argv[]) {
    int ntowrite, nwrite;
    printf("ntowrite: %d\n", ntowrite);
    char *ptr;
    ntowrite = read(STDIN_FILENO, buf, sizeof(buf));
    fprintf(stderr, "read %d bytes \n", ntowrite);
    set_fl(STDOUT_FILENO, O_NONBLOCK);
    ptr = buf;
    printf("ntowrite: %d\n", ntowrite);
    while (ntowrite > 0) {
        errno = 0;
        nwrite = write(STDOUT_FILENO, ptr, ntowrite);
        fprintf(stderr, "nwrite = %d, errno = %d\n", nwrite, errno);

        if (nwrite > 0) {
            ptr += nwrite;
            ntowrite -= nwrite;
        }
    }
    clr_fl(STDOUT_FILENO, O_NONBLOCK);
    exit(0);
}


//889##24##7##7## 89##2##  1248##9##50##1##362##3##74##5##

/*
 * class A {
public:
    int a;
//    char Ac1;
//    char Ac2;
//    char Ac3;
//    char Ac23;
    virtual ~A(){}
};
class B {
public:
    int b;
    virtual ~B(){}
};
class C: public A, public B{
public:
    int c;
//    int c2;
//    int c3;
//    virtual ~C(){}
};

class D: public A{
public:
    int d;
};






class E {
public:
    char e1;
    char e2;
//    char e3;
//    char e4;
};
class F:public E {};

class XX {};
class YY : public virtual XX {};
class ZZ : public virtual XX{};
class AA :public ZZ, public YY{};

class test{
    int a;
    int a2;
    int a23;
    double a123;
};

int main(void)
{
    printf("A::a %p\n", &A::a);
    printf("B::b %p\n", &B::b);
    printf("C::a %p\n", &C::a);
    printf("C::b %p\n", &C::b);
    printf("C::c %p\n", &C::c);
//    printf("C::c2 %p\n", &C::c2);
    printf("D::d %p\n", &D::d);
//    printf("E::e1 %p\n", &E::e1);
//    printf("E::e2 %p\n", &E::e2);
//    printf("E::e3 %p\n", &E::e3);
//    printf("E::e4 %p\n", &E::e4);


//
    std::cout<<"C: "<< sizeof(C)<<std::endl;
//    std::cout<<"D: "<< sizeof(D)<<std::endl;
//    std::cout<<"E: "<< sizeof(E)<<std::endl;
//    std::cout<<"F: "<< sizeof(F)<<std::endl;
//    std::cout<<"int: "<< sizeof(void *)<<std::endl;

//
//    std::cout<<"XX: "<< sizeof(XX)<<std::endl;
//    std::cout<<"YY: "<< sizeof(YY)<<std::endl;
//    std::cout<<"ZZ: "<< sizeof(ZZ)<<std::endl;
//    std::cout<<"AA: "<< sizeof(AA)<<std::endl;
//    std::cout<<"test: "<< sizeof(test)<<std::endl;
    return 0;
}
 * */