#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

int main() {
    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;

    vector<int> dist(f + 1, INF);
    dist[s] = 0;

    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        int up = curr + u;
        int down = curr - d;

        if (up <= f && dist[up] == INF) {
            dist[up] = dist[curr] + 1;
            q.push(up);
        }

        if (down > 0 && dist[down] == INF) {
            dist[down] = dist[curr] + 1;
            q.push(down);
        }
    }

    if (dist[g] != INF) {
        cout << dist[g] << endl;
    } else {
        cout << "use the stairs" << endl;
    }

    return 0;
}
