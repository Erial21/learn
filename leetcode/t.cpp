#include<iostream>
#include<stack>

using namespace std;

int main() {
    stack<int> stack[3];
    int a = 1, b = 2;
    for (int i = 0;i < 3;++i) {
        if (a < b) continue;
        cout << "1" << endl;
    }
    stack->push(3);
    cout << stack->size() << endl;
    return 0;
}