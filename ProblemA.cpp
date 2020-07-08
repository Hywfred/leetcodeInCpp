#include <iostream>
#include <stack>

using namespace std;

int main(int argv, char *args[]) {
    int num;
    int last_time = 0;
    int speed, time;
    int total = 0;
    while (cin >> num, num > 0) {
        for (int i = 0; i != num; ++i) {
            cin >> speed >> time;
            total += speed * (time - last_time);
            last_time = time;
        }
        cout << total << " miles" << endl;
        total = 0;
        last_time = 0;
    }
    return 0;
}
