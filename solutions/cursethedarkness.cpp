#include <bits/stdc++.h>

using namespace std;

int main() {
    int TC;
    cin >> TC;

    while (TC--) {
        bool light = false;

        double bookX, bookY;
        cin >> bookX >> bookY;

        int n;
        cin >> n;
        while (n--) {
            double candleX, candleY;
            cin >> candleX >> candleY;

            if (light)
                continue;

            // Pythagoras Theorem
            double distance =
                sqrt(pow(candleX - bookX, 2) + pow(candleY - bookY, 2));

            if (distance <= 8.0) {
                light = true;
            }
        }

        cout << (light ? "light a candle" : "curse the darkness") << endl;
    }

    return 0;
}
