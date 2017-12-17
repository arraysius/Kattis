#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
typedef pair<int, int> ii;
typedef tuple<int, int, int, int> iiii;

int main() {
    int n, m, q, s;
    bool first = true;

    while (cin >> n >> m >> q >> s, n || m || q || s) {
        // dest, start time, interval, distance
        vector<iiii> AL[n];

        // Read graph
        while (m--) {
            int u, v, t, P, d;
            cin >> u >> v >> t >> P >> d;

            AL[u].push_back(make_tuple(v, t, P, d));
        }

        // Dijkstra
        int duration[n];
        fill_n(duration, n, INF);
        duration[s] = 0;

        priority_queue<ii, vector<ii>, greater<ii>> pq;
        pq.push({0, s}); // total duration to next node, next node

        while (!pq.empty()) {
            ii front = pq.top();
            pq.pop();

            int u = front.second;
            int dur = front.first;

            for (auto &tup : AL[u]) {
                int v = get<0>(tup);
                int t = get<1>(tup);
                int P = get<2>(tup);
                int d = get<3>(tup);

                // Time for next available travel window
                int window = t;
                if (P != 0) {
                    while (window < duration[u]) {
                        window += P;
                    }
                } else if (duration[u] > window) {
                    // window has passed, no future window
                    continue;
                }

                // If has shorter duration
                int nextNodeTime = window + d;
                if (nextNodeTime < duration[v]) {
                    duration[v] = nextNodeTime;
                    pq.push({duration[v], v});
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

            if (duration[v] != INF) {
                cout << duration[v] << endl;
            } else {
                cout << "Impossible" << endl;
            }
        }
    }

    return 0;
}
