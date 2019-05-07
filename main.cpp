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

class A {
public:
    int a;
//    char Ac1;
//    char Ac2;
//    char Ac3;
//    char Ac23;
//    virtual ~A(){}
};
class B {
public:
    int b;
//    virtual ~B(){}
};
class C: public virtual A, public virtual B{
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



int main(int argc, char* argv[]) {
    FindContinuousSequence(15);
    std::string str = "I am a student.";
    ReverseSentence(str);
//    ReserveString(str, 0, str.size() - 1);
    cout<<str<<endl;
}


//889##24##7##7## 89##2##  1248##9##50##1##362##3##74##5##

/*
 *

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
//    std::cout<<"D: "<< sizeof(D)<<std::endl;7
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