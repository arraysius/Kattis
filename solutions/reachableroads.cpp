#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adjList;
vector<bool> visited;
int cc = 0;

void dfs(int u) {
    visited[u] = true;
    for (auto &v : adjList[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        int m, r;
        cin >> m >> r;

        // Clear adjList and visited list
        cc = 0;
        adjList.assign(m, vector<int>());
        visited.assign(m, false);

        // Read edges
        while (r--) {
            int u, v;
            cin >> u >> v;

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        // Count connected components
        for (int i = 0; i < m; i++) {
            if (!visited[i]) {
                cc++;
                dfs(i);
            }
        }

        cout << cc - 1 << endl;
    }

    return 0;
}
