//
// Created by Hywfred on 2020/3/4.
//

#ifndef LEETCODEINCPP_TEST_H
#define LEETCODEINCPP_TEST_H

#include <ostream>
using std::cout;

class Another {
public:
	Another(){
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
