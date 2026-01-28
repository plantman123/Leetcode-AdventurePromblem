#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class MyQueue {
private:
    vector<int> inStack;
    vector<int> outStack;

public:
    MyQueue() {}
    
    void push(int x) {
        inStack.push_back(x);
    }
    
    int pop() {
        int front = 0;
        while (inStack.size() > 1) {
            outStack.push_back(inStack.back());
            inStack.pop_back();
        }
        front = inStack.back();
        inStack.pop_back();
        while (!outStack.empty()) {
            inStack.push_back(outStack.back());
            outStack.pop_back();
        }
        return front;
    }
    
    int peek() {
        int front = 0;
        if (!inStack.empty()) front = inStack[0];
        return front;
    }
    
    bool empty() {
        return inStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */