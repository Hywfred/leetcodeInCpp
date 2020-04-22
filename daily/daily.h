#pragma once
#ifndef _DAILY_H
#define _DAILY_H

#include <string>
#include <vector>
#include "../util/TreeNode.h"

class Solution {
public:
	int strStr(std::string haystack, std::string needle);

	// ¶ş²æÊ÷ÓÒÊÓÍ¼
	std::vector<int> rightSideView(TreeNode *root);
};

#endif // _DAILY_H
