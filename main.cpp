#include "./tree/easy/MinimumDepthOfBT.h"
#include "util/treenode.h"
#include <climits>
#include <iostream>
using namespace std;

int main() {
	Solution s;
	vector<int> arr{3,9,20,INT_MAX,INT_MAX,15,7};
    auto root = GenerateBT(arr, 0);
    cout << s.minDepth(root) << endl;
    PreorderTraversal(root);
    arr = {1, 2};
    root = GenerateBT(arr, 0);
    PreorderTraversal(root);
    cout << s.minDepth(root);
	return 0;
}
