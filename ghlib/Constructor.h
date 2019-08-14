//
// Created by gh on 5/11/19.
//

#ifndef GH_CODE_CONSTRUCTOR_H
#define GH_CODE_CONSTRUCTOR_H

#include <iostream>
#include <vector>

using namespace std;

class GH {
public:
    int x;
    GH(int x): x(x) {
        cout<< "Constructor" <<endl;
    }

    GH(GH& a): x(a.x) {
        cout<< "Copy Constructor" <<endl;
    }

    GH& operator=(GH& a) {
        x = a.x;
        cout<< "Copy Assignment Constructor" <<endl;
        return *this;
    }

    GH(GH&& a) : x(a.x) {
        cout<<"Move Constructor"<<endl;
    }

    GH& operator=(GH&& a) {
        x = a.x;
        cout<<"Move Assignment operator"<<endl;
        return *this;
    }

    GH GetGH() {
        return GH(1);
    }

    GH&& MoveGH() {
        return GH(1);
    }

    void test() {
        cout<<"-----------------------------1 GH a(1);-----------------------------"<<endl;
        GH a(1);
        cout<<"-----------------------------2 GH b = a-----------------------------"<<endl;
        GH b = a;
        cout<<"-----------------------------3 GH c(a)-----------------------------"<<endl;
        GH c(a);
        cout<<"-----------------------------4 b = a-----------------------------"<<endl;
        b = a;
        cout<<"-----------------------------5 GH d = GH(1)-----------------------------"<<endl;
        GH d = GH(1);
        cout<<"-----------------------------6 GH e = std::move(a)-----------------------------"<<endl;
        GH e = std::move(a);
        cout<<"-----------------------------7 GH f = GetGH()-----------------------------"<<endl;
        GH f = GetGH();
        cout<<"-----------------------------8 GH&& g = MoveGH()-----------------------------"<<endl;
        GH&& g = MoveGH();
        cout<<"-----------------------------9 d = GH(1)-----------------------------"<<endl;
        d = GH(1);
    }
};



class K{
public:
    int x;
    K(){}
    K(int x): x(x) {
        cout<< "Constructor" <<endl;
    }

    K(const K& a): x(a.x) {
        cout<< "Copy Constructor" <<endl;
    }

    K& operator=(K& a) {
        x = a.x;
        cout<< "Copy Assignment Constructor" <<endl;
        return *this;
    }

    K(K&& a) : x(a.x) {
        cout<<"Move Constructor"<<endl;
    }

    K& operator=(K&& a) {
        x = a.x;
        cout<<"Move Assignment operator"<<endl;
        return *this;
    }

};

/*
   void TestK() {
    vector<K > vector_emplace;
    vector<K > vector_push;
    std::string str1 = "asdasd";
    std::string str2 = "asdasd";


    K k2(1);
//    vector_emplace.emplace_back(k2);
    vector_push.push_back(k2);
    cout<<"------------------------------------------------------------------------"<<endl;
    double time1 = gh::current_time();
    for (int i = 0; i < 1; ++i)
        vector_push.push_back(K(1));
    double time2 = gh::current_time();

    cout<<"------------------------------------------------------------------------"<<endl;
    double time3 = gh::current_time();
    for (int i = 0; i < 1; ++i)
        vector_emplace.emplace_back(1);

    double time4 = gh::current_time();

    cout<<"push_back time:" << time2 -time1 << "\n" << "emplace_back: "<<time4 - time3<<endl;
    return 0;

}*/


/*
Constructor
Copy Constructor
------------------------------------------------------------------------
Constructor
Move Constructor
Copy Constructor
------------------------------------------------------------------------
Constructor
push_back time:1.21593e-05
emplace_back: 3.09944e-06*/
#endif //GH_CODE_CONSTRUCTOR_H
