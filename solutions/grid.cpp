#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
typedef pair<int, int> ii;

int main() {
    int n, m;
    cin >> n >> m;

    int grid[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            grid[i][j] = c - '0';
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << grid[i][j] << endl;
    //     }
    // }

    vector<vector<int>> dist(n, vector<int>(m, INF));

    // BFS
    dist[0][0] = 0;
    queue<ii> q;
    q.push(ii(0, 0));

    while (!q.empty()) {
        ii front = q.front();
        q.pop();
        int y = front.first;
        int x = front.second;

        int dn[] = {1, -1, 0, 0};
        int dm[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int newN = y + (dn[i] * grid[y][x]);
            int newM = x + (dm[i] * grid[y][x]);

            if (newN < 0 || newN >= n || newM < 0 || newM >= m)
                continue;

            if (dist[y][x] + 1 < dist[newN][newM]) {
                dist[newN][newM] = dist[y][x] + 1;
                q.push(ii(newN, newM));
            }
        }
    }

    if (dist[n - 1][m - 1] < INF) {
        cout << dist[n - 1][m - 1] << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
