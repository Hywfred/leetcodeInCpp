//
// Created by Hywfred on 2020/3/4.
//

#ifndef LEETCODEINCPP_TEST_H
#define LEETCODEINCPP_TEST_H
#include <ostream>
#include <initializer_list>
#include <vector>
#include <string>
using namespace std;
void testIORedirection() {
    string str;
    int i;
    cin >> str >> i;
    cout << "The string in the file is " << str << "." << endl
         << "The int in the file is " << i << "." << endl;
}

//extern const int b;
namespace test {
    const int a = 10;
    void testA(){
        cout << a << endl;
    }
    void testB(){
//        cout << b << endl;
    }
}
using namespace std;


class CTest {
public:
    void SetValue();

public:
    int m_iValue1;
    int m_iValue2;
    int data;
};

void CTest::SetValue() {
    m_iValue1 = 13;
    m_iValue2 = 13;
}

template <class T>
void f(){ T d; }

template <>
void f<int>(){ int d; }

/*
 * imperfect forwarding
 */

void process(int& a){
    cout << "process(int& a)" << endl;
}
void process(int&& a) {
    cout << "process(int&& a)" << endl;
}
void forward(int&& a) {
    cout << "forward(int&& a)" << endl;
    process(a);
}
/**
 * explicit for ctor with more than one param
 */
class P {
public:
    P(int a, int b) {
        cout << "int a, int b" << std::endl;
    }

    explicit P(std::initializer_list<int> il) {
        cout << "initializer list" << std::endl;
    }

    P(int a, int b, int c) {
        cout << "int a, int b, int c" << std::endl;
    }

    void fp(const P &p) {}

    // ~P() = delete;

};

class Another {
public:
    Another() {
        cout << "Another" << std::endl;
    }
};

class Father {
public:
    Father() {
        cout << "Father" << std::endl;
    }

private:
    Another another;
};


class Child : public Father {
public:
    Child() {
        cout << "Child" << std::endl;
    }

//private:
//	Another another;
};

#endif //LEETCODEINCPP_TEST_H
