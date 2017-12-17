#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int main() {
    int TC;
    cin >> TC;

    int x_moves[] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int y_moves[] = {2, 1, -1, -2, -2, -1, 1, 2};

    while (TC--) {
        string curpos;
        cin >> curpos;

        int x_pos = curpos[0] - 'a';
        int y_pos = (curpos[1] - '0') - 1;

        int chessboard[8][8];
        for (int i = 0; i < 8; i++) {
            fill_n(chessboard[i], 8, -1);
        }

        int maxDist = 0;

        chessboard[x_pos][y_pos] = 0;
        queue<ii> q;
        q.push({x_pos, y_pos});

        while (!q.empty()) {
            ii f = q.front();
            q.pop();

            x_pos = f.first;
            y_pos = f.second;

            for (int i = 0; i < 8; i++) {
                int newX = x_pos + x_moves[i];
                int newY = y_pos + y_moves[i];

                if (newX < 0 || newX >= 8 || newY < 0 || newY >= 8)
                    continue;

                if (chessboard[newX][newY] == -1) {
                    chessboard[newX][newY] = chessboard[x_pos][y_pos] + 1;
                    maxDist = max(maxDist, chessboard[newX][newY]);
                    q.push({newX, newY});
                }
            }
        }

        cout << maxDist;
        for (int j = 7; j >= 0; j--) {
            for (int i = 0; i < 8; i++) {
                if (chessboard[i][j] == maxDist) {
                    cout << " " << (char)(i + 'a') << (char)((j + '0') + 1);
                }
            }
        }
        cout << endl;
    }

    return 0;
}
