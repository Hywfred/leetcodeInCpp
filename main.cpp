#include <iostream>
#include <vector>
using namespace std;
void bubbleSort(vector<int>& inputArray) {
    for (int i = 0; i < inputArray.size() - 1; ++i) {
        for (int j = i+1; j < inputArray.size(); ++j) {
            if (inputArray[i] > inputArray[j]) {
                int tmp = inputArray[i];
                inputArray[i] = inputArray[j];
                inputArray[j] = tmp;
            }
        }
    }
}
int main () {
    int n; // 数字个数
    vector<int> inputArray;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        inputArray.push_back(tmp);
    }
    bubbleSort(inputArray);
    auto it = inputArray.begin();
    while (it != inputArray.end()-1) {
        if ((*it) == *(it+1)) {
            it = inputArray.erase(it);
        } else {
            ++it;
        }
    }
    for (int i = 0; i < inputArray.size(); i++) {
        cout << inputArray[i] << endl;
    }
    return 0;
}

