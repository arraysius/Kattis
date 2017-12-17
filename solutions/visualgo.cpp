#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() {
    int V, E;
    cin >> V >> E;

    vector<vii> AL;
    AL.assign(V, vii());

    while (E--) {
        int u, v, w;
        cin >> u >> v >> w;

        AL[u].push_back(ii(v, w));
    }

    int s, t;
    cin >> s >> t;

    // Dijkstra
    vi dist(V, INF);
    vi ways(V, 0);

    dist[s] = 0;
    ways[s] = 1;

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push(ii(0, s));

    while (!pq.empty()) {
        ii front = pq.top();
        pq.pop();

        int d = front.first;
        int u = front.second;

        if (d > dist[u])
            continue;

        for (auto &v : AL[u]) {
            int newDist = dist[u] + v.second;
            if (newDist < dist[v.first]) {
                // If shorter distance
                dist[v.first] = newDist;
                ways[v.first] = ways[u];
                pq.push(ii(newDist, v.first));
            } else if (newDist == dist[v.first]) {
                // If equal distance
                ways[v.first] += ways[u];
            }
        }
    }

    cout << ways[t] << endl;

    return 0;
}
