#include <bits/stdc++.h>

using namespace std;

unordered_map<string, vector<string>> adjList;
unordered_map<string, int> visited;
bool cycle;

void dfs(string u) {
    visited[u] = 1; // Set explored

    for (auto &v : adjList[u]) {
        if (cycle) {
            return;
        }

        if (visited[v] == 0) {
            // not visited
            dfs(v);
        } else if (visited[v] == 1) {
            // cycle
            cycle = true;
            return;
        }
    }

    visited[u] = 2;
}

int main() {
    int n;
    cin >> n;

    unordered_set<string> cities;

    while (n--) {
        string o, d;
        cin >> o >> d;

        adjList[o].push_back(d);

        cities.insert(o);
        cities.insert(d);
    }

    string city;
    while (cin >> city) {
        // Reset city visit status
        for (auto &c : cities) {
            visited[c] = 0;
        }

        cycle = false;

        dfs(city);
        cout << city << (cycle ? " safe" : " trapped") << endl;
    }

    return 0;
}
