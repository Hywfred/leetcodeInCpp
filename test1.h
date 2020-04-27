//
// Created by Hywfred on 2020/3/20.
//

#ifndef LEETCODEINCPP_TEST1_H
#define LEETCODEINCPP_TEST1_H

#include <string>
#include <vector>

using namespace std;

/*
 * 快排降序
 */
void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void quickSort(vector<int> &input, int left, int right) {
    if (left < right) {
        int target = input[left];
        int l = left, r = right + 1;
        while (true) {
            while (input[--r] < target);
            while (l < r && input[++l] > target);
            if (l < r) {
                swap(input[l], input[r]);
            } else {
                break;
            }
        }
        if (l != left) {
            swap(input[l], input[left]);
        }
        quickSort(input, left, l - 1);
        quickSort(input, l + 1, right);
    }
}

void Quick(vector<int> &input) {
    quickSort(input, 0, input.size() - 1);
}

class A {
public:
    virtual void foo() {
        cout << "A foo" << endl;
    }
};

class B : public A {
public:
    virtual void foo() {
        cout << "B foo" << endl;
    }
};

extern const int b = 1;
namespace test1 {
    const int a = 20;

    void testA() {
        cout << a << endl;
    }

    void testB() {
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
