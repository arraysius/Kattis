#include <bits/stdc++.h>

using namespace std;

int main() {
    int TC;
    cin >> TC;

    while (TC--) {
        double r, b, m;
        cin >> r >> b >> m;

        int R = (int)((r * 100) + 0.5);
        long long B = (long long)((b * 100) + 0.5);
        int M = (int)((m * 100) + 0.5);

        int payments = 0;
        while (B > 0 && payments <= 1200) {
            // Add interest
            int i = (B * (R / 10000.0)) + 0.5;
            if (i > M) {
                payments = 1201;
                break;
            }
            B += i;

            // Deduct
            B -= M;
            payments++;
        }

        if (payments <= 1200)
            cout << payments << endl;
        else
            cout << "impossible" << endl;
    }

    return 0;
}
