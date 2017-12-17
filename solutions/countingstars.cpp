#include <bits/stdc++.h>

using namespace std;

int m, n;
int stars = 0;
vector<vector<char>> image;
vector<vector<bool>> visited;
queue<pair<int, int>> bqueue;

// void bfs() {
//     pair<int, int> p = bqueue.front();
//     bqueue.pop();

//     visited[p.first][p.second] = true;

//     if (p.first - 1 >= 0 && image[p.first - 1][p.second] == '-' &&
//         !visited[p.first - 1][p.second]) {
//         bqueue.push(make_pair(p.first - 1, p.second));
//     }
//     if (p.first + 1 < m && image[p.first + 1][p.second] == '-' &&
//         !visited[p.first + 1][p.second]) {
//         bqueue.push(make_pair(p.first + 1, p.second));
//     }
//     if (p.second >= 0 && image[p.first][p.second - 1] == '-' &&
//         !visited[p.first][p.second - 1]) {
//         bqueue.push(make_pair(p.first, p.second - 1));
//     }
//     if (p.second < n && image[p.first][p.second + 1] == '-' &&
//         !visited[p.first][p.second + 1]) {
//         bqueue.push(make_pair(p.first, p.second + 1));
//     }
// }

void dfs(int a, int b) {
    visited[a][b] = true;

    // Up
    if (a - 1 >= 0 && image[a - 1][b] == '-' && !visited[a - 1][b]) {
        dfs(a - 1, b);
    }
    // Down
    if (a + 1 < m && image[a + 1][b] == '-' && !visited[a + 1][b]) {
        dfs(a + 1, b);
    }

    // Left
    if (b - 1 >= 0 && image[a][b - 1] == '-' && !visited[a][b - 1]) {
        dfs(a, b - 1);
    }

    // Right
    if (b + 1 < n && image[a][b + 1] == '-' && !visited[a][b + 1]) {
        dfs(a, b + 1);
    }
}

int main() {
    int cases = 0;

    while (cin >> m >> n) {
        cases++;

        stars = 0;
        image.assign(m, vector<char>());
        visited.assign(m, vector<bool>());

        // Build image
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char c;
                cin >> c;
                image[i].push_back(c);
                visited[i].push_back(false);
            }
        }

        // Count stars
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (image[i][j] == '-' && !visited[i][j]) {
                    stars++;
                    // bqueue.push(make_pair(i, j));
                    // while (!bqueue.empty()) {
                    //     bfs();
                    // }
                    dfs(i, j);
                }
            }
        }

        cout << "Case " << cases << ": " << stars << endl;
    }

    return 0;
}
