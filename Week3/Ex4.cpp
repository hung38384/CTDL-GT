#include <iostream>
#include <string>
using namespace std;

const int MAX = 1e5;

template <typename T>
class Queue {
    T base[MAX];
    T *a = base;
    int size = 0;

public:
    Queue() {
    }

    void enqueue(T x) {
        a[size] = x;
        size++;
    }

    void dequeue() {
        a++;
        size--;
    }

    bool empty() {
        return size > 0;
    }

    T front() {
        return a[0];
    }
};

int main() {
    int n;
    cin >> n;

    Queue<int> a;

    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;

        if (operation == "enqueue") {
            int x;
            cin >> x;
            a.enqueue(x);
        } else if (operation == "dequeue") {
                a.dequeue();
        } else {
            cout << "Invalid operation: " << operation << endl;
        }
    }

    while (a.empty()) {
        cout << a.front() << " ";
        a.dequeue();
    }
    cout << endl;

    return 0;
}
