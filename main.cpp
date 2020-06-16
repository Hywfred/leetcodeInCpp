#include <iostream>
#include <sstream>
#include <string>

#include "daily.h"

using namespace std;

int main(int argv, char *args[]) {
    string str;
    string a = "1,2,3,null,null,4,5";
    istringstream ss(a);
    while (getline(ss, str, ',')) { cout << str << endl; }
    // getline(istringstream("1,2,3,null,null,4,5"), str, ',');
    cout << str << endl;
    return 0;
}