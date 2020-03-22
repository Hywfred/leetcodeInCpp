#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
#include <stdexcept>
using namespace std;

int test1() {
    int arr[6] = {1, 2, 3, 54, 33, 40};
    vector<int, allocator<int>> v(arr, arr+6);
    cout << count_if(v.begin(), v.end(), not1(bind2nd(less<int>(), 40)));
    return  0;
}

void testException(){
    try {
        int a = 1/0;
        cout << a << endl;
    } catch(exception &e) {
        cout << "不得了了" << e.what();
        abort();
    }

}

void testVector() {
    vector<int> v{1, 2, 34, 5, 6};
    cout << "front: " << v.front() << endl;
    cout << "back: " << v.back() << endl;
    cout << "cap: " << v.capacity() << endl;
    cout << "addr: " << v.data() << endl;
    v.push_back(8);
    cout << "front: " << v.front() << endl;
    cout << "back: " << v.back() << endl;
    cout << "cap: " << v.capacity() << endl;
    cout << "addr: " << v.data() << endl;
}