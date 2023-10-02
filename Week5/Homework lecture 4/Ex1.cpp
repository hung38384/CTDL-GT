#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

int calculateHeight(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);
    return max(leftHeight, rightHeight) + 1;
}

void preorderTraversal(Node* root, vector<int>& result) {
    if (root == nullptr) {
        return;
    }
    result.push_back(root->data);
    preorderTraversal(root->left, result);
    preorderTraversal(root->right, result);
}

void postorderTraversal(Node* root, vector<int>& result) {
    if (root == nullptr) {
        return;
    }
    postorderTraversal(root->left, result);
    postorderTraversal(root->right, result);
    result.push_back(root->data);
}

bool isBinaryTree(Node* root, vector<int>& result) {
    if (root == nullptr) {
        return true;
    }
    stack<Node*> s;
    Node* current = root;

    while (!s.empty() || current != nullptr) {
        if (current != nullptr) {
            s.push(current);
            current = current->left;
        } else {
            current = s.top();
            s.pop();
            result.push_back(current->data);
            current = current->right;
        }
    }

    for (int i = 1; i < result.size(); i++) {
        if (result[i] <= result[i - 1]) {
            return false;
        }
    }

    return true;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<Node*> nodes(N);

    for (int i = 0; i < N; i++) {
        nodes[i] = new Node(i + 1);
    }

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        if (nodes[u - 1]->left == nullptr) {
            nodes[u - 1]->left = nodes[v - 1];
        } else {
            nodes[u - 1]->right = nodes[v - 1];
        }
    }

    int height = calculateHeight(nodes[0]);

    vector<int> preorderResult;
    preorderTraversal(nodes[0], preorderResult);

    vector<int> postorderResult;
    postorderTraversal(nodes[0], postorderResult);

    vector<int> inorderResult;
    bool isBinary = isBinaryTree(nodes[0], inorderResult);

    cout << "Height: " << height << endl;
    cout << "Preorder Traversal: ";
    for (int node : preorderResult) {
        cout << node << " ";
    }
    cout << endl;
    cout << "Postorder Traversal: ";
    for (int node : postorderResult) {
        cout << node << " ";
    }
    cout << endl;
    if (isBinary) {
        cout << "Inorder Traversal: ";
        for (int node : inorderResult) {
            cout << node << " ";
        }
    } else {
        cout << "NOT BINARY TREE";
    }
    cout << endl;

    for (Node* node : nodes) {
        delete node;
    }

    return 0;
}
