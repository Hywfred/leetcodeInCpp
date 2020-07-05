#include <stack>

using namespace std;

int main(int argv, char *args[]) {
    stack<int> s;
    return 0;
}

class StackQueue {
  public:
    stack<int> in_;
    stack<int> out_;

    void push(int a) { in_.push(a); }

    void pop() {
        if (out_.empty())
            trans();
        else
            out_.pop();
    }

    int front() { return out_.top(); }

    void trans() {
        while (!in_.empty()) {
            int top = in_.top();
            in_.pop();
            out_.push(top);
        }
    }
};