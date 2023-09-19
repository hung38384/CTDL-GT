#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* pre;
    Node(int value) : data(value), pre(NULL), next(NULL){}
};

class DoublyLinkedList{
    public:
    Node* head;
    Node* tail;
    DoublyLinkedList () : head(NULL), tail(NULL){}
    void append(int data){
        Node* tmp = new Node(data);
        if(!head){
            head = tmp;
            tail = tmp;
        } else {
            tail->next = tmp;
            tmp->pre = tail;
            tail = tmp;
        }
    }
    int count_triplets(){
        int count = 0;
        Node* cur = head;
        while(cur != NULL && cur->next != NULL && cur->next->next != NULL){
            if (cur->data + cur->next->data + cur->next->next->data == 0){
                count++;
            }
            cur = cur->next;
        }
        return count;
    }
};


int main () {
    int n;
    cin >> n;
    DoublyLinkedList dll;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        dll.append(num);
    }
    cout << dll.count_triplets() << endl;
    return 0;
}