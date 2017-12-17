#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N >> ws;

    unordered_map<string, set<string>> AL;
    unordered_map<string, vector<string>> visited;

    // Read map
    while (N--) {
        string line;
        getline(cin, line);
        istringstream iss(line);

        string station;
        getline(iss, station, ' ');

        string neighbour;
        // vector<string> neighbours;
        while (getline(iss, neighbour, ' ')) {
            AL[station].insert(neighbour);
            AL[neighbour].insert(station);
        }
    }

    // Source and Destination
    string source, dest;
    cin >> source >> dest;

    // BFS
    queue<string> q;
    q.push(source);
    visited.insert({source, vector<string>()});

    while (!q.empty()) {
        string u = q.front();
        q.pop();

        for (auto v : AL[u]) {
            if (visited.find(v) == visited.end() ||
                visited[u].size() + 1 < visited[v].size()) {
                q.push(v);

                visited.insert({v, visited[u]});
                visited[v].push_back(u);
            }
        }
    }

    if (visited.find(dest) != visited.end()) {
        for (auto s : visited[dest])
            cout << s << " ";
        cout << dest << endl;
    } else {
        cout << "no route found" << endl;
    }

    return 0;
}
