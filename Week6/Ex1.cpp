#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int find(int node) {
    if (parent[node] == -1) {
        return node;
    }
    return find(parent[node]);
}

void unionNodes(int a, int b) {
    parent[a] = b;
}

int main() {
    int n, m;
    cin >> n >> m;

    parent.assign(n, -1);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        int parentX = find(x - 1);
        int parentY = find(y - 1);

        if (parentX != parentY) {
            unionNodes(parentX, parentY);
        }
    }

    int connectedComponents = 0;
    for (int i = 0; i < n; i++) {
        if (parent[i] == -1) {
            connectedComponents++;
        }
    }

    cout << connectedComponents << endl;

    return 0;
}
