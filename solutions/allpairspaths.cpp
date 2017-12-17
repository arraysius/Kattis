#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

int main() {
    bool first = true;
    int n, m, q;

    while (cin >> n >> m >> q, n || m || q) {
        int AM[n][n];
        for (int i = 0; i < n; i++) {
            fill_n(AM[i], n, INF);
            AM[i][i] = 0;
        }

        while (m--) {
            int u, v, w;
            cin >> u >> v >> w;
            AM[u][v] = min(AM[u][v], w);
        }

        // Floyd Warshall's
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (AM[i][k] != INF && AM[k][j] != INF)
                        AM[i][j] = min(AM[i][j], AM[i][k] + AM[k][j]);
                }
            }
        }

        if (first) {
            first = false;
        } else {
            cout << endl;
        }

        while (q--) {
            int u, v;
            cin >> u >> v;

            int d = AM[u][v];

            for (int k = 0; k < n; k++) {
                if (AM[u][k] != INF && AM[k][v] != INF && AM[k][k] < 0) {
                    d = -INF;
                    break;
                }
            }

            if (d == INF) {
                cout << "Impossible" << endl;
            } else if (d == -INF) {
                cout << "-Infinity" << endl;
            } else {
                cout << d << endl;
            }
        }
    }

    return 0;
}
