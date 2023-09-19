#include<iostream>
#include<queue>
using namespace std;

class stack{
    private:
    int Top;
    queue<int> q1;
    queue<int> q2;
    public:
    stack() {}
    void push(int x){
        q2.push(x);
        Top = x;
        while(!q1.empty()){
            Top = q1.front();
            q1.pop();
            q2.push(Top);
        }
        swap(q1,q2);
    }
    int pop(){
        int popped = Top;
        q1.pop();
        if(!q1.empty()){
            Top = q1.front();
        }
        return popped;
    }
    int top(){
        return Top;
    }
    bool empty(){
        return q1.empty();
    }

};

int main () {
    stack Mystack;
    Mystack.push(1);
    Mystack.pop();
    cout << Mystack.empty();

}