#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;

    while (cin >> n) {
        if (n == -1)
            break;

        vector<int> AL[n];
        int structural[n];
        fill_n(structural, n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int v;
                cin >> v;

                if (v == 1) {
                    AL[i].push_back(j);
                    AL[j].push_back(i);
                }
            }
        }

        for (int i = 0; i < n - 1; i++) {
            if (AL[i].size() == 0) {
                continue;
            }

            for (int j = 0; j < AL[i].size() - 1; j++) {
                int n1 = AL[i][j];
                for (int k = j + 1; k < AL[i].size(); k++) {
                    int n2 = AL[i][k];

                    if (structural[i] == 1 && structural[n1] == 1 &&
                        structural[n2] == 1) {
                        continue;
                    }

                    if (find(AL[n1].begin(), AL[n1].end(), n2) !=
                            AL[n1].end() &&
                        find(AL[n2].begin(), AL[n2].end(), n1) !=
                            AL[n2].end()) {
                        structural[i] = 1;
                        structural[n1] = 1;
                        structural[n2] = 1;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (structural[i] == 0) {
                cout << i << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
