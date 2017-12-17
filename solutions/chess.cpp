#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

int main() {
    int TC;
    cin >> TC;

    while (TC--) {
        int AM[8][8];
        vector<pair<int, int>> path[8][8];
        for (int i = 0; i < 8; i++)
            fill_n(AM[i], 8, INF);

        pair<int, int> X, Y;

        char a, b;
        cin >> a >> b;
        X = {(int)(a - 'A'), (int)(b - '0') - 1};

        cin >> a >> b;
        Y = {(int)(a - 'A'), (int)(b - '0') - 1};

        // BFS
        AM[X.first][X.second] = 0;
        queue<pair<int, int>> q;
        q.push(X);
        while (!q.empty()) {
            pair<int, int> u = q.front();
            q.pop();

            pair<int, int> moves[] = {{-1, 1}, {1, 1}, {1, -1}, {-1, -1}};

            // Set diagonals distance
            for (int i = 0; i < 4; i++) {
                int newX = u.first + moves[i].first;
                int newY = u.second + moves[i].second;

                while (newX >= 0 && newX < 8 && newY >= 0 && newY < 8 &&
                       (AM[u.first][u.second] + 1 < AM[newX][newY])) {
                    AM[newX][newY] = AM[u.first][u.second] + 1;
                    path[newX][newY] = path[u.first][u.second];
                    path[newX][newY].push_back({u.first, u.second});
                    q.push({newX, newY});

                    newX += moves[i].first;
                    newY += moves[i].second;
                }
            }
        }

        if (AM[Y.first][Y.second] != INF) {
            cout << AM[Y.first][Y.second] << " ";
            for (auto v : path[Y.first][Y.second]) {
                cout << (char)(v.first + 'A') << " "
                     << (char)(v.second + 1 + '0') << " ";
            }
            cout << (char)(Y.first + 'A') << " " << (char)(Y.second + 1 + '0')
                 << endl;
        } else {
            cout << "Impossible" << endl;
        }
    }

    return 0;
}
