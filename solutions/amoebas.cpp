#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int main() {
    int m, n;
    cin >> m >> n;

    char AM[m][n];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> AM[i][j];

    int cc = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (AM[i][j] == '#') {
                cc++;

                // DFS
                stack<ii> st;
                st.push({i, j});
                while (!st.empty()) {
                    ii front = st.top();
                    st.pop();

                    AM[front.first][front.second] = '.';

                    int dr[] = {1, 1, 1, 0, 0, -1, -1, -1};
                    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

                    for (int k = 0; k < 8; k++) {
                        ii newCell = {front.first + dr[k],
                                      front.second + dc[k]};
                        if (newCell.first < 0 || newCell.first >= m ||
                            newCell.second < 0 || newCell.second >= n ||
                            AM[newCell.first][newCell.second] != '#') {
                            continue;
                        }

                        st.push(newCell);
                    }
                }
            }
        }
    }

    cout << cc << endl;

    return 0;
}
