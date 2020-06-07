#include "my_iostream.h"

using namespace std;

ostream &my_print(ostream &os, const vector<string> &str_vec) {
    for (const auto &str : str_vec) { os << str << " "; }
    return os;
}

ostream &my_print(ostream &os, const vector<vector<string>> &str_vec) {
    for (const auto &elem : str_vec) {
        for (const auto &str : elem) { os << str << " "; }
        os << endl;
    }
    return os;
}