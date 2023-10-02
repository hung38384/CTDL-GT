#include <iostream>
using namespace std;

// Một Node trong cây
class Node {
public:
    // Chứa thông tin của Node đó
    int data;
    // Con trỏ đến Node cha
    Node* fatherNode;
    // Con trỏ đến các Node con
    // Đây là một danh sách liên kết (con trỏ đến con đầu tiên)
    // Thứ tự ưu tiên từ nhỏ đến lớn (con nhỏ được duyệt trước)
    Node* firstChild;

    // Hàm khởi tạo Node với giá trị data và con trỏ cha là nullptr
    Node(int value) : data(value), fatherNode(nullptr), firstChild(nullptr) {}
};

// Lớp Cây
class Tree {
private:
    // Chứa một Node gốc
    Node* root;

public:
    // Khởi tạo cây với gốc là nullptr
    Tree() : root(nullptr) {}

    // Hàm thêm một Node vào cây
    // Hàm trả về false nếu Node cha không tồn tại trên cây
    // hoặc Node father đã có con là data
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
            if (!parentNode->firstChild) {
                parentNode->firstChild = new Node(data);
            } else {
                Node* sibling = parentNode->firstChild;
                while (sibling->firstChild) {
                    sibling = sibling->firstChild;
                }
                sibling->firstChild = new Node(data);
            }
            return true;
        }

        return false;
    }

    // Hàm xoá một Node trên cây
    // Nếu không phải Node lá xoá Node đó và toàn bộ các Node con của nó
    // Hàm trả về số lượng Node đã xoá
    // Nếu Node data không tồn tại trả về 0 (zero)
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
        Node* prevSibling = nullptr;
        Node* sibling = parentNode->firstChild;

        while (sibling) {
            if (sibling == nodeToRemove) {
                if (prevSibling) {
                    prevSibling->firstChild = sibling->firstChild;
                } else {
                    parentNode->firstChild = sibling->firstChild;
                }
                deleteTree(nodeToRemove);
                count++;
                break;
            }
            prevSibling = sibling;
            sibling = sibling->firstChild;
        }

        return count;
    }

    // Hàm in ra các Node theo thứ tự preorder
    void preorder() {
        preorderTraversal(root);
        cout << endl;
    }

    // Hàm in ra các Node theo thứ tự postorder
    void postorder() {
        postorderTraversal(root);
        cout << endl;
    }

    // Hàm kiểm tra cây nhị phân
    bool isBinaryTree() {
        return isBinaryTreeHelper(root);
    }

    // Hàm kiểm tra cây tìm kiếm nhị phân
    bool isBinarySearchTree() {
        // Viết mã cho hàm kiểm tra cây tìm kiếm nhị phân ở đây
        // ...
        return false;
    }

    // Hàm kiểm tra cây max-heap
    bool isMaxHeapTree() {
        // Viết mã cho hàm kiểm tra cây max-heap ở đây
        // ...
        return false;
    }


    // Hàm trả về độ cao của cây
    int height() {
        return calculateHeight(root);
    }

    // Hàm trả về độ sâu của một Node
    int depth(int data) {
        Node* node = findNode(root, data);
        if (node) {
            return calculateDepth(root, node);
        }
        return -1;
    }

    // Hàm đếm số lượng lá
    int numOfLeaves() {
        return countLeaves(root);
    }

    // Hàm trả về Node có giá trị lớn nhất
    int findMax() {
        return findMaxValue(root);
    }

    // Hàm trả về Node có nhiều con nhất
    int findMaxChild() {
        return findMaxChildValue(root);
    }

// ... (các phần khác)

private:
    // Hàm tìm Node trong cây
    Node* findNode(Node* currentNode, int data) {
        if (!currentNode) {
            return nullptr;
        }

        if (currentNode->data == data) {
            return currentNode;
        }

        Node* foundNode = nullptr;
        Node* child = currentNode->firstChild;
        while (child && !foundNode) {
            foundNode = findNode(child, data);
            child = child->firstChild;
        }

        return foundNode;
    }

    // Hàm xoá toàn bộ cây
    void deleteTree(Node* node) {
        if (!node) {
            return;
        }

        Node* child = node->firstChild;
        while (child) {
            Node* nextChild = child->firstChild;
            deleteTree(child);
            child = nextChild;
        }

        delete node;
    }

    // Hàm duyệt cây theo thứ tự preorder
    void preorderTraversal(Node* node) {
        if (node) {
            cout << node->data << " ";
            Node* child = node->firstChild;
            while (child) {
                preorderTraversal(child);
                child = child->firstChild;
            }
        }
    }

    // Hàm duyệt cây theo thứ tự postorder
    void postorderTraversal(Node* node) {
        if (node) {
            Node* child = node->firstChild;
            while (child) {
                postorderTraversal(child);
                child = child->firstChild;
            }
            cout << node->data << " ";
        }
    }

    // Hàm kiểm tra cây nhị phân
    bool isBinaryTreeHelper(Node* node) {
        if (!node) {
            return true;
        }

        if (!node->fatherNode && node->firstChild) {
            return false;
        }

        Node* child = node->firstChild;
        while (child) {
            if (child->fatherNode != node) {
                return false;
            }
            if (!isBinaryTreeHelper(child)) {
                return false;
            }
            child = child->firstChild;
        }

        return true;
    }

    // Hàm tính chiều cao của cây
    int calculateHeight(Node* node) {
        if (!node) {
            return 0;
        }

        int maxChildHeight = 0;
        Node* child = node->firstChild;
        while (child) {
            int childHeight = calculateHeight(child);
            if (childHeight > maxChildHeight) {
                maxChildHeight = childHeight;
            }
            child = child->firstChild;
        }

        return 1 + maxChildHeight;
    }

    // Hàm tính độ sâu của một Node
    int calculateDepth(Node* currentNode, Node* targetNode) {
        if (!currentNode) {
            return -1;
        }

        if (currentNode == targetNode) {
            return 0;
        }

        int childDepth = calculateDepth(currentNode->firstChild, targetNode);
        if (childDepth >= 0) {
            return 1 + childDepth;
        }

        return calculateDepth(currentNode->firstChild, targetNode);
    }

    // Hàm đếm số lượng lá
    int countLeaves(Node* node) {
        if (!node) {
            return 0;
        }

        if (!node->firstChild) {
            return 1;
        }

        int leafCount = 0;
        Node* child = node->firstChild;
        while (child) {
            leafCount += countLeaves(child);
            child = child->firstChild;
        }

        return leafCount;
    }

    // Hàm tìm giá trị lớn nhất trong cây
    int findMaxValue(Node* node) {
        if (!node) {
            return INT_MIN;
        }

        int maxVal = node->data;
        Node* child = node->firstChild;
        while (child) {
            int childMax = findMaxValue(child);
            if (childMax > maxVal) {
                maxVal = childMax;
            }
            child = child->firstChild;
        }

        return maxVal;
    }

    // Hàm tìm Node có nhiều con nhất
    int findMaxChildValue(Node* node) {
        if (!node) {
            return INT_MIN;
        }

        int maxChildCount = -1;
        Node* maxChildNode = nullptr;
        Node* child = node->firstChild;

        while (child) {
            int childCount = countChildren(child);
            if (childCount > maxChildCount) {
                maxChildCount = childCount;
                maxChildNode = child;
            }
            child = child->firstChild;
        }

        if (maxChildNode) {
            return maxChildNode->data;
        }

        return INT_MIN;
    }

    // Hàm đếm số lượng con của một Node
    int countChildren(Node* node) {
        int count = 0;
        Node* child = node->firstChild;
        while (child) {
            count++;
            child = child->firstChild;
        }
        return count;
    }
};

#include <iostream>
using namespace std;

// Định nghĩa các lớp và phương thức Tree và Node ở đây (giống như đã được định nghĩa trước đó)

int main(int argc, char const *argv[]) {
    // Tạo cây ngẫu nhiên có ít nhất 30 Node
    Tree randomTree;
    randomTree.insert(-1, 10);
    randomTree.insert(10, 5);
    randomTree.insert(10, 15);
    randomTree.insert(5, 3);
    randomTree.insert(5, 8);
    randomTree.insert(15, 12);
    randomTree.insert(15, 20);
    randomTree.insert(3, 1);
    randomTree.insert(3, 4);
    randomTree.insert(8, 7);
    randomTree.insert(12, 11);
    randomTree.insert(12, 14);
    randomTree.insert(20, 18);
    randomTree.insert(20, 25);
    randomTree.insert(1, 0);
    randomTree.insert(1, 2);
    randomTree.insert(4, 6);
    randomTree.insert(7, 9);
    randomTree.insert(11, 13);
    randomTree.insert(14, 16);
    randomTree.insert(18, 17);
    randomTree.insert(18, 19);
    randomTree.insert(25, 22);
    randomTree.insert(25, 30);
    randomTree.insert(2, 21);
    randomTree.insert(2, 24);
    randomTree.insert(6, 23);
    randomTree.insert(9, 26);
    randomTree.insert(13, 27);
    randomTree.insert(16, 28);
    randomTree.insert(17, 29);

    // Test các hàm của cây ngẫu nhiên ở đây
    cout << "Random Tree Preorder: ";
    randomTree.preorder();

    cout << "Random Tree Postorder: ";
    randomTree.postorder();

    cout << "Random Tree is Binary Tree: " << (randomTree.isBinaryTree() ? "Yes" : "No") << endl;

    // Tạo cây thoả mãn tính chất của Binary Search Tree (BST)
    Tree bstTree;
    bstTree.insert(-1, 5);
    bstTree.insert(5, 3);
    bstTree.insert(5, 8);
    bstTree.insert(3, 1);
    bstTree.insert(3, 4);
    bstTree.insert(8, 7);
    bstTree.insert(8, 9);

    // Test các hàm của cây BST ở đây
    cout << "BST Tree Preorder: ";
    bstTree.preorder();

    cout << "BST Tree Postorder: ";
    bstTree.postorder();

    cout << "BST Tree is Binary Search Tree: " << (bstTree.isBinarySearchTree() ? "Yes" : "No") << endl;

    // Tạo cây thoả mãn tính chất của Max Heap Tree
    Tree maxHeapTree;
    maxHeapTree.insert(-1, 9);
    maxHeapTree.insert(9, 8);
    maxHeapTree.insert(9, 7);
    maxHeapTree.insert(8, 6);
    maxHeapTree.insert(8, 5);
    maxHeapTree.insert(7, 4);
    maxHeapTree.insert(7, 3);
    maxHeapTree.insert(6, 2);
    maxHeapTree.insert(6, 1);

    // Test các hàm của cây Max Heap ở đây
    cout << "Max Heap Tree Preorder: ";
    maxHeapTree.preorder();

    cout << "Max Heap Tree Postorder: ";
    maxHeapTree.postorder();

    cout << "Max Heap Tree is Max Heap Tree: " << (maxHeapTree.isMaxHeapTree() ? "Yes" : "No") << endl;

    return 0;
}
