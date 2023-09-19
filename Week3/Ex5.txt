#include<iostream>
#include<string>
using namespace std;

int size = 100;
int top = -1;
int stack[100];

bool empty(){
    return top == 0 ? true : false;
}

void push(int item){
    top++;
    stack[top] = item;
}

void pop(){
    stack[top] = 0;
    --top;
}

void printStack() {
    for (int i = 0; i <= top; i++) {
        cout << stack[i] << " ";
    }
    cout << endl;
}

int main () {
    int n; 
    cin >> n;
    for(int i = 0; i < n; i++){
        string opr;
        cin >> opr;
        if(opr == "push"){
            int x;
            cin >> x;
            push(x);
        }
        if(opr == "pop"){
            pop();
        }
    }
    printStack();
    return 0;
}

