//ex2
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, d;
    Edge(int u, int v, int d) : u(u), v(v), d(d) {}
    bool operator<(const Edge& other) const {
        return d < other.d;
    }
};

vector<int> parent;

int find(int u) {
    if (parent[u] == u)
        return u;
    return parent[u] = find(parent[u]);
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        parent[u] = v;
    }
}

int main() {
    ifstream inputFile("connection.txt");
    ofstream outputFile("connection.out");

    int n, m;
    inputFile >> n >> m;
    vector<Edge> edges;

    for (int i = 0; i < m; i++) {
        int u, v, d;
        inputFile >> u >> v >> d;
        edges.push_back(Edge(u, v, d));
    }

    sort(edges.begin(), edges.end());

    parent.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    long long totalCost = 0;
    vector<Edge> selectedEdges;

    for (Edge edge : edges) {
        if (find(edge.u) != find(edge.v)) {
            unite(edge.u, edge.v);
            totalCost += edge.d;
            selectedEdges.push_back(edge);
        }
    }

    outputFile << totalCost << endl;
    for (Edge edge : selectedEdges) {
        outputFile << edge.u << " " << edge.v << " " << edge.d << endl;
    }

    inputFile.close();
    outputFile.close();

}
