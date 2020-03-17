#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void Encrypt (char aucPassword[], char aucResult[]) {
    int len = sizeof(aucPassword)/sizeof(char);
    cout << 1 << len << endl;
    for (int i = 0; i  < len; ++i) {
        char cur = aucPassword[i];
        if (cur >= 'a' && cur <= 'z') {
            aucResult[i] = (cur - 'a' + 1) % 26 + 'A';
        } else if (cur >= 'A' && cur <= 'Z') {
            aucResult[i] = (cur - 'A' + 1) % 26 + 'a';
        } else if (cur >= '0' && cur <= '9') {
            aucResult[i] = (cur - '0' + 1) % 10 + '0';
        }
        cout << aucResult[i];
    }
    aucResult[len] = '\0';
}
int unEncrypt (char result[], char password[]) {
    int len = sizeof(result)/sizeof(char);
    cout << 2 << len << endl;
    for (int i = 0; i  < len; ++i) {
        char cur = result[i];
        if (cur >= 'a' && cur <= 'z') {
            password[i] = (cur - 'a' + 25) % 26 + 'A';
        } else if (cur >= 'A' && cur <= 'Z') {
            password[i] = (cur - 'A' + 25) % 26 + 'a';
        } else if (cur >= '0' && cur <= '9') {
            password[i] = (cur - '0' + 9) % 10 + '0';
        }
        cout << password[i];
    }
    password[len] = '\0';
    cout << endl;
    return 1;
}

int main() {
    char aucPassword[101] = "abcdefg";
    char aucResult[101];
    char result[101] = "BCDEFGH";
    char password[101];
    Encrypt(aucPassword, aucResult);
    unEncrypt(result, password);
    return 0;
}