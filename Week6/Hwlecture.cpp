//eX1
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void topologicalSort(vector<vector<int>>& graph, vector<int>& indegree, vector<int>& result) {
    queue<int> q;
    int n = graph.size();

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u + 1);

        for (int v : graph[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }
}

int main() {
    ifstream inputFile("jobs.txt");
    int n, m;
    inputFile >> n >> m;

    vector<vector<int>> graph(n);
    vector<int> indegree(n, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        inputFile >> u >> v;
        graph[u - 1].push_back(v - 1);
        indegree[v - 1]++;
    }

    inputFile.close();

    vector<int> result;
    topologicalSort(graph, indegree, result);

    ofstream outputFile("jobs.out");
    for (int job : result) {
        outputFile << job << endl;
    }
    outputFile.close();
}
