#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

#define INF 1e9

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int main() {
    int TC;
    cin >> TC;

    while (TC--) {
        bool escaped = false;
        int x, y;

        int w, h;
        cin >> w >> h;

        char AM[h][w];

        queue<pair<int, int>> fires;
        queue<pair<int, int>> positions;

        int seconds[h][w];
        for (int i = 0; i < h; i++) {
            fill_n(seconds[i], w, INF);
        }

        // Read map
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                char c;
                cin >> c;

                if (c == '*') {
                    fires.push({j, i});
                } else if (c == '@') {
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

                // Set explored
                AM[f.second][f.first] = '@';

                for (int j = 0; j < 4; j++) {
                    int newX = f.first + dx[j];
                    int newY = f.second + dy[j];

                    // Escaped
                    if (newX < 0 || newX >= w || newY < 0 || newY >= h) {
                        escaped = true;
                        x = f.first;
                        y = f.second;
                        break;
                    }

                    // If explored
                    if (AM[newY][newX] == '@')
                        continue;

                    // Potential new position
                    if (AM[newY][newX] != '#' && AM[newY][newX] != '*') {
                        // Look for fire
                        bool danger = false;
                        for (int k = 0; k < 4; k++) {
                            int lookX = newX + dx[k];
                            int lookY = newY + dy[k];

                            if (lookX >= 0 && lookX < w && lookY >= 0 &&
                                lookY < h) {
                                // Will be consumed in next turn
                                if (AM[lookY][lookX] == '*') {
                                    danger = true;
                                    break;
                                }
                            }

                            if (danger)
                                break;
                        }

                        if (!danger) {
                            AM[newY][newX] = '@';
                            positions.push({newX, newY});
                            // cout << seconds[f.second][f.first] << endl;
                            seconds[newY][newX] =
                                seconds[f.second][f.first] + 1;
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

                    if (newX < 0 || newX >= w || newY < 0 || newY >= h)
                        continue;

                    if (AM[newY][newX] != '#' && AM[newY][newX] != '*') {
                        AM[newY][newX] = '*';
                        fires.push({newX, newY});
                    }
                }
            }

            // // Print map
            // for (int i = 0; i < h; i++) {
            //     for (int j = 0; j < w; j++) {
            //         cout << AM[i][j];
            //     }
            //     cout << endl;
            // }
            // cout << endl;
            // usleep(200000);
        }

        if (escaped) {
            cout << seconds[y][x] + 1 << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    }

    return 0;
}
