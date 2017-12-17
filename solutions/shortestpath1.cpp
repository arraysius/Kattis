#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000

typedef pair<int, int> ii;

int main() {
    int n, m, q, s;
    bool first = true;

    while (cin >> n >> m >> q >> s, n || m || q || s) {
        vector<vector<ii>> AL(n, vector<ii>());
        // AL.assign(n, vector<ii>());

        // Edges
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;

            AL[u].emplace_back(v, w);
        }

        // Dijkstra
        vector<int> distance(n, INF);
        distance[s] = 0;

        priority_queue<ii, vector<ii>, greater<ii>> pq;
        pq.push({0, s});

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > distance[u])
                continue;

            for (auto &v : AL[u]) {
                if (distance[u] + v.second < distance[v.first]) {
                    distance[v.first] = distance[u] + v.second;
                    pq.push({distance[v.first], v.first});
                }
            }
        }

        // Queries
        if (!first)
            cout << endl;
        first = false;

        for (int i = 0; i < q; i++) {
            int dest;
            cin >> dest;

            if (distance[dest] != INF) {
                cout << distance[dest] << endl;
            } else {
                cout << "Impossible" << endl;
            }
        }
    }

    return 0;
}
