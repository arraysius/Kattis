#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int main() {
    bool escaped = false;
    int escapableX, escapableY;

    int R, C;
    cin >> R >> C;

    char AM[R][C];

    queue<pair<int, int>> fires;
    queue<pair<int, int>> positions;

    int seconds[R][C];
    for (int i = 0; i < R; i++) {
        fill_n(seconds[i], C, INF);
    }

    // Read map
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            char c;
            cin >> c;

            if (c == 'F') {
                fires.push({j, i});
            } else if (c == 'J') {
                positions.push({j, i});
                seconds[i][j] = 0;
            }

            AM[i][j] = c;
        }
    }

    while (!positions.empty()) {
        // BFS position
        int possize = positions.size();
        for (int i = 0; i < possize; i++) {
            pair<int, int> f = positions.front();
            positions.pop();

            // cout << seconds[f.second][f.first] << endl;

            // Set visited
            AM[f.second][f.first] = 'J';

            for (int j = 0; j < 4; j++) {
                int newX = f.first + dx[j];
                int newY = f.second + dy[j];

                // Escaped
                if (newX < 0 || newX >= C || newY < 0 || newY >= R) {
                    escaped = true;
                    escapableX = f.first;
                    escapableY = f.second;
                    break;
                }

                // If explored
                if (AM[newY][newX] == 'J')
                    continue;

                // Potential new position
                if (AM[newY][newX] != '#' && AM[newY][newX] != 'F') {
                    // Look for fire
                    bool danger = false;
                    for (int k = 0; k < 4; k++) {
                        int lookX = newX + dx[k];
                        int lookY = newY + dy[k];

                        if (lookX >= 0 && lookX < C && lookY >= 0 &&
                            lookY < R) {
                            // Will be consumed in next turn
                            if (AM[lookY][lookX] == 'F') {
                                danger = true;
                                break;
                            }
                        }

                        if (danger)
                            break;
                    }

                    if (!danger) {
                        AM[newY][newX] = 'J';
                        positions.push({newX, newY});
                        // cout << seconds[f.second][f.first] << endl;
                        seconds[newY][newX] = seconds[f.second][f.first] + 1;
                    }
                }
            }

            if (escaped)
                break;
        }

        if (escaped)
            break;

        // BFS Fire
        int firesize = fires.size();
        for (int i = 0; i < firesize; i++) {
            pair<int, int> f = fires.front();
            fires.pop();

            for (int j = 0; j < 4; j++) {
                int newX = f.first + dx[j];
                int newY = f.second + dy[j];

                if (newX < 0 || newX >= C || newY < 0 || newY >= R)
                    continue;

                if (AM[newY][newX] != '#' && AM[newY][newX] != 'F') {
                    AM[newY][newX] = 'F';
                    fires.push({newX, newY});
                }
            }
        }

        // // Print map
        // for (int i = 0; i < R; i++) {
        //     for (int j = 0; j < C; j++) {
        //         cout << AM[i][j];
        //     }
        //     cout << endl;
        // }
    }

    if (escaped) {
        cout << seconds[escapableY][escapableX] + 1 << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
