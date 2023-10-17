#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

int main() {
    int n, m, X, Y;
    cin >> n >> m >> X >> Y;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x - 1].push_back(y - 1);
    }

    vector<int> distance(n, INF);
    distance[X - 1] = 0;

    queue<int> q;
    q.push(X - 1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (distance[v] == INF) {
                distance[v] = distance[u] + 1;
                q.push(v);
            }
        }
    }

    if (distance[Y - 1] == INF) {
        cout << "No path from X to Y" << endl;
    } else {
        cout << distance[Y - 1] << endl;
    }

    return 0;
}
