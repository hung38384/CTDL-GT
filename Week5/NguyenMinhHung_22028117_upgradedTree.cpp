#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* fatherNode;
    vector<Node*> children; // Sử dụng vector để lưu trữ các con của nút

    Node(int value) : data(value), fatherNode(nullptr) {}

    // Thêm một nút con vào nút hiện tại
    void addChild(Node* child) {
        child->fatherNode = this;
        children.push_back(child);
    }

    // Kiểm tra xem nút hiện tại có phải là nút lá hay không
    bool isLeaf() {
        return children.empty();
    }
};

class Tree {
private:
    Node* root;

public:
    Tree() : root(nullptr) {}

    bool insert(int father, int data) {
        if (!root) {
            if (father == -1) {
                root = new Node(data);
                return true;
            }
            return false;
        }

        Node* parentNode = findNode(root, father);
        if (parentNode) {
            parentNode->addChild(new Node(data));
            return true;
        }

        return false;
    }

    int remove(int data) {
        int count = 0;
        Node* nodeToRemove = findNode(root, data);
        if (!nodeToRemove) {
            return count;
        }

        if (!nodeToRemove->fatherNode) {
            deleteTree(root);
            root = nullptr;
            return 1;
        }

        Node* parentNode = nodeToRemove->fatherNode;
        for (auto it = parentNode->children.begin(); it != parentNode->children.end(); ++it) {
            if (*it == nodeToRemove) {
                parentNode->children.erase(it);
                deleteTree(nodeToRemove);
                count++;
                break;
            }
        }

        return count;
    }

    // Các phương thức khác không cần thay đổi vì vẫn sử dụng các đệ quy và duyệt cây.

    // ...
};
