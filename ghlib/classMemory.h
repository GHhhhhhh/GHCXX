//
// Created by gh on 19-5-9.
//

#ifndef GH_CODE_CLASSMEMORY_H
#define GH_CODE_CLASSMEMORY_H

class X {
public:
    int x = 10;
//    virtual void Xfunc() { cout<<"X::Xfunc()" <<endl;}
//    virtual void func1() { cout<<"X::func1()" <<endl;}
};
class A : public virtual X{
public:
    int a = 2;
//    virtual void Xfunc() {cout<<"A::Xfunc()" <<endl;}
//    virtual void func2() {cout<<"A::func2()" <<endl;}
//    int a2 = 4;
};
class B : public virtual X{
public:
    int b = 3;
//    virtual void Xfunc() {cout<<"B::Xfunc()" <<endl;}
//    virtual void func3() {cout<<"B::func3()" <<endl;}
};
class C: public  A, public  B{
public:
    int c = 4;
//    virtual void Xfunc() {cout<<"C::Xfunc()" <<endl;}
//    virtual void func4() {cout<<"C::func4()" <<endl;}

/*
 *      NO VIRTUAL FUNCTION
 *      ------------
 *      |vptr(8)   |
 * A--->|int(4)    |  16
 *      |padding(4)|
 *      ------------
 *      ------------
 *      |vptr(8)   |  12
 * B--->|int(4)    |
 *      ------------
 *      ------------
 * C--->|int(4)    |  4
 *      ------------
 *      ------------
 * X--->|int(4)    |  8
 *      |padding(4)|
 *      ------------
 *      total: 36
 *
 *      VIRTUAL FUNCTION
 *
 *      ------------
 *      |vptr(8)   |
 * A--->|int(4)    |  16
 *      |padding(4)|
 *      ------------
 *      ------------
 *      |vptr(8)   |  12
 * B--->|int(4)    |
 *      ------------
 *      ------------
 * C--->|int(4)    |  4
 *      ------------
 *      ------------
 *      |vptr(8)   |
 * X--->|int(4)    |  16
 *      |padding(4)|
 *      ------------
 *      total: 48
 *
 * */

/*
 * test code
    cout<<"X: "<< sizeof(X)<<endl;
    cout<<"A: "<< sizeof(A)<<endl;
    cout<<"B: "<< sizeof(B)<<endl;
    cout<<"C: "<< sizeof(C)<<endl;
    C c;
    char *p = (char*)&c;
    cout<<"A--------------------------------------"<<endl;
    gh::visitVtbl((int**)*(int**)p, 0);
    p += sizeof(int **);

    cout<<*(int*)p <<endl;
    p += sizeof(int);
    cout<<"A padding 4"<<endl;
    p += sizeof(4);

    cout<<"B--------------------------------------"<<endl;
    gh::visitVtbl((int**)*(int**)p, 0);
    p += sizeof(int **);

    cout<<*(int*)p <<endl;
    p += sizeof(int);

    cout<<"C--------------------------------------"<<endl;
    cout<<*(int*)p <<endl;
    p += sizeof(int);

    cout<<"X--------------------------------------"<<endl;
//    gh::visitVtbl((int**)*(int**)p, 0);
//    p += sizeof(int **);
    cout<<*(int*)p <<endl;
 *
 * */

};





#endif //GH_CODE_CLASSMEMORY_H
