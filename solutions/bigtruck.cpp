#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
typedef pair<int, int> ii;

int main() {
    int n;
    cin >> n;

    int items[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> items[i];
    }

    vector<ii> AL[n + 1];

    int m;
    cin >> m;

    while (m--) {
        int a, b, d;
        cin >> a >> b >> d;
        AL[a].push_back({b, d});
        AL[b].push_back({a, d});
    }

    // Dijkstra
    vector<int> dist(n + 1, INF);
    dist[1] = 0;
    vector<int> collected(n + 1, 0);
    collected[1] = items[1];
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        ii front = pq.top();
        pq.pop();

        int u = front.second;
        int d = front.first;

        for (auto &v : AL[u]) {
            int newdist = dist[u] + v.second;
            if (newdist < dist[v.first] ||
                (newdist == dist[v.first] &&
                 collected[u] + items[v.first] > collected[v.first])) {
                dist[v.first] = newdist;
                collected[v.first] = collected[u] + items[v.first];
                pq.push({newdist, v.first});
            }
        }
    }

    if (dist[n] == INF) {
        cout << "impossible" << endl;
    } else {
        cout << dist[n] << " " << collected[n] << endl;
    }

    return 0;
}
