#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void insertNode(Node*& head, int pos, int x){
    Node* tmp = new Node();
    tmp->data = x;
    tmp->next = NULL;
    if(pos == 0 || head == NULL){
        if(head == NULL){
        head = tmp;
    }else{
        tmp->next = head; 
        head = tmp;
    }
    } else {
        int k = 1;
        Node* p = head;
        while(p != nullptr && k != pos){
            p = p->next;
            k++;
        }
        Node* q = new Node();
        q->next = p->next;
        p->next = q;
        q->data = x;
    }
}

void deleteNode(Node*& head, int pos){
    if(head == NULL){
        return ;
    }
    if (pos == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    int k = 1;
    Node* p = head;
    while(p != nullptr && k != pos ){
        p = p->next;
        k++;
    }
    Node* temp = p->next;
    p->next = p->next->next;
    delete temp;
}

void printNode(Node* head){
    Node* p = head;
    while(p != nullptr){
        cout << p->data << " " << endl;
        p = p->next;
    }
}

int main (){
    Node* head = nullptr;
    insertNode(head, 0, 1);
    insertNode(head, 1, 3);
    insertNode(head, 1, 4);
    insertNode(head, 2, 2);
    deleteNode(head, 1);
    printNode(head);
}