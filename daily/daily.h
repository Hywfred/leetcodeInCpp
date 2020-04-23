#pragma once
#ifndef _DAILY_H
#define _DAILY_H

#include <string>
#include <vector>
#include <TreeNode.h>

class Solution {
public:
	int strStr(std::string haystack, std::string needle);

	std::vector<int> rightSideView(TreeNode *root);

	// 硬币
	int waysToChange(int n);
};

#endif // _DAILY_H
