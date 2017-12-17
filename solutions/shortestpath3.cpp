#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
typedef tuple<int, int, int> iii;

int main() {
    bool first = true;

    int n, m, q, s;
    while (cin >> n >> m >> q >> s, n || m || q || s) {
        multiset<iii> EL;

        while (m--) {
            int u, v, w;
            cin >> u >> v >> w;

            // AL[u].push_back({v, w});
            EL.insert(make_tuple(u, v, w));
        }

        vector<int> distance(n, INF);
        distance[s] = 0;

        // Bellman Ford
        for (int i = 0; i < n - 1; i++) { // O(V)   overall O(VE)
            for (auto &tup : EL) {        // O(E)
                int u = get<0>(tup);
                int v = get<1>(tup);
                int w = get<2>(tup);

                // do `distance[u] != INF` to only start from source 
                if (distance[u] != INF && distance[u] + w < distance[v]) {
                    distance[v] = distance[u] + w;
                }
            }
        }

        // Check for negative weight cycle
        vector<bool> affectedVertice(n, false); // part of -ve cycle
        bool check = true;
        while (check) { // Keep checking as not all vertices confirmed to be part of -ve cycle
            check = false;
            for (auto &tup : EL) {
                int u = get<0>(tup);
                int v = get<1>(tup);
                int w = get<2>(tup);

                if (distance[u] != INF && !affectedVertice[v] && distance[u] + w < distance[v]) {
                    distance[v] = -INF;
                    check = true;
                    affectedVertice[v] = true;
                }
            }
        }

        if (first) {
            first = false;
        } else {
            cout << endl;
        }

        // Queries
        while (q--) {
            int v;
            cin >> v;

            if (distance[v] == INF) {
                cout << "Impossible" << endl;
            } else if (distance[v] == -INF) {
                cout << "-Infinity" << endl;
            } else {
                cout << distance[v] << endl;
            }
        }
    }

    return 0;
}
