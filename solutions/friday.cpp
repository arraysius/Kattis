#include <bits/stdc++.h>

using namespace std;

int main() {
    int TC;
    cin >> TC;

    while (TC--) {
        int D, M;
        cin >> D >> M;

        int ans = 0;
        int day = 0; // Sunday = 0

        for (int i = 0; i < M; i++) {
            int d; // days in month
            cin >> d;

            for (int j = 1; j <= d; j++) {
                if (j == 13 && day == 5) {
                    ans++;
                }
                day = (day + 1) % 7; // Next day
            }
        }

        cout << ans << endl;
    }

    return 0;
}
