#include "daily/ReverseWordsInAStr.h"
#include <iostream>
using namespace std;

int main() {
    cout << Solution::reverseWords("the sky is blue") << endl;
    cout << Solution::reverseWords("  hello world!  ") << endl;
    cout << Solution::reverseWords("a good   example") << endl;
    cout << Solution::reverseWords(" sky ") << endl;
    cout << Solution::reverseWords("   ") << endl;
    cout << Solution::reverseWords("") << endl;
    return 0;
}