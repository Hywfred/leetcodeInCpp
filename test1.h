//
// Created by Hywfred on 2020/3/20.
//

#ifndef LEETCODEINCPP_TEST1_H
#define LEETCODEINCPP_TEST1_H

#include <string>

class A {
public:
    virtual void foo() {
        cout << "A foo" << endl;
    }
};
class B : public A {
public:
    virtual  void foo() {
        cout << "B foo" << endl;
    }
};

extern const int b = 1;
namespace test1{
    const int a = 20;
    void testA(){
        cout << a << endl;
    }
    void testB(){
        cout << b << endl;
    }
    void testOverwrite(int a, string b) {
        cout << a << " " << b << endl;
    }
    void testOverwrite(string a, int b) {
        cout << a << " " << b << endl;
    }
}

#endif //LEETCODEINCPP_TEST1_H
