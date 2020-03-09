//
// Created by Hywfred on 2020/3/4.
//

#ifndef LEETCODEINCPP_TEST_H
#define LEETCODEINCPP_TEST_H

#include <ostream>
#include <initializer_list>

using std::cout;

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
