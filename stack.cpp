// stack implementation using vectors

#include <iostream>
#include <vector>
using namespace std;

class Stack {
    vector<int> v;

public:
    void push(int data) {
        v.push_back(data);
    }

    void pop() {
        v.pop_back();
    }

    int top() {
        return v[v.size()-1];
    }

    bool empty() {
        return v.size() == 0;
    }
};

int main() {
    return 0;
}