#include <iostream>
using namespace std;
#include "gtest/gtest.h"

int Abs(int x) {
	return x > 0 ? x : -x;
}

TEST(IsAbsTest, HandlerTrueReturn) {
	ASSERT_TRUE(Abs(1) == 1) << "Abs(1)=1";
	//ASSERT_TRUE�ڴ������true,operator<<���һЩ�Զ������Ϣ
	ASSERT_TRUE(Abs(-1) == 1) << "Abs(-1)=1";
	ASSERT_FALSE(Abs(-2) == -2); //�ڴ������false
}
