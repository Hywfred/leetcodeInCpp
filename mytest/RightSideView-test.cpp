#include <iostream>
using namespace std;
#include "gtest/gtest.h"

int Abs(int x) {
	return x > 0 ? x : -x;
}

TEST(IsAbsTest, HandlerTrueReturn) {
	ASSERT_TRUE(Abs(1) == 1) << "Abs(1)=1";
	//ASSERT_TRUE期待结果是true,operator<<输出一些自定义的信息
	ASSERT_TRUE(Abs(-1) == 1) << "Abs(-1)=1";
	ASSERT_FALSE(Abs(-2) == -2); //期待结果是false
}
