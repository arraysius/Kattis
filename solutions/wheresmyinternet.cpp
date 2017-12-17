#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> AL[N + 1];
    int visited[N + 1];
    fill_n(visited, N + 1, 0);

    while (M--) {
        int a, b;
        cin >> a >> b;

        AL[a].push_back(b);
        AL[b].push_back(a);
    }

    // BFS
    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        visited[u] = 1;

        for (auto &v : AL[u]) {
            if (visited[v] == 0) {
                q.push(v);
            }
        }
    }

    bool printed = false;
    for (int i = 1; i <=N;i++) {
        if (visited[i] == 0) {
            printed = true;
            cout << i << endl;
        }
    }

    if (!printed) {
        cout << "Connected" << endl;
    }

    return 0;
}
