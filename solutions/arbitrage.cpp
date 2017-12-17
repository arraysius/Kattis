#include <bits/stdc++.h>

using namespace std;

int main() {
    int C;
    while (cin >> C, C) {
        unordered_map<string, int> currencies;
        for (int i = 0; i < C; i++) {
            string curr;
            cin >> curr;
            currencies[curr] = i;
        }

        int R;
        cin >> R;

        double AM[C][C];
        for (int i = 0; i < C; i++) {
            fill_n(AM[i], C, 0);
            AM[i][i] = 1;
        }

        while (R--) {
            string u, v;
            double a, b;
            cin >> u >> v;
            scanf("%lf:%lf", &a, &b);

            AM[currencies[u]][currencies[v]] = b / a;
        }

        // Floyd Warshall's
        for (int k = 0; k < C; k++) {
            for (int i = 0; i < C; i++) {
                for (int j = 0; j < C; j++) {
                    // cout << AM[i][j] << " " << AM[i][k] << " " << AM[k][j] <<
                    // " " << AM[i][k] * AM[k][j] << endl;
                    AM[i][j] = max(AM[i][j], AM[i][k] * AM[k][j]);
                }
            }
        }

        // // Print AM
        // for (int i = 0; i < C; i++) {
        //     for (int j = 0; j < C; j++) {
        //         cout << AM[i][j] << "\t";
        //     }
        //     cout << endl;
        // }

        // For every pair, check for profit
        bool arbitrage = false;
        for (int i = 0; i < C; i++) {
            if (AM[i][i] > 1) {
                arbitrage = true;
                break;
            }
        }

        if (arbitrage) {
            cout << "Arbitrage" << endl;
        } else {
            cout << "Ok" << endl;
        }
    }

    return 0;
}
