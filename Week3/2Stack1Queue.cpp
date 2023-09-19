#include<iostream>
#include<stack>
using namespace std;

class Queue {
    private:
    stack<int> stackPop;
    stack<int> stackPush;
    public:
    Queue() {}

    void push(int x) {
        stackPush.push(x);
    }

    int pop(){
        if(stackPop.empty()){
            while(!stackPush.empty()){
                stackPop.push(stackPush.top());
                stackPush.pop();
            }
        }
        if(!stackPop.empty()){
            int front = stackPop.top();
            stackPop.pop();
            return front;
        }
        return -1;
    }

    int peek() {
        if(stackPop.empty()){
            while(!stackPush.empty()){
                stackPop.push(stackPush.top());
                stackPush.pop();
            }
        }
        if(!stackPop.empty()){
            return stackPop.top();
        }
        return -1;
    }

    bool empty() {
        return stackPush.empty() && stackPop.empty();
    }

};

int main () {
    Queue Myqueue;
    Myqueue.push(1);
    Myqueue.pop();
    cout << Myqueue.empty();
}