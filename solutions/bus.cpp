#include <bits/stdc++.h>

using namespace std;

int main() {
    int TC;
    cin >> TC;

    while (TC--) {
        int stops;
        cin >> stops;
        stops--;

        double p = 1;

        while (stops--) {
            p = (2 * p) + 1;
        }

        cout << (int)p << endl;
    }

    return 0;
}
