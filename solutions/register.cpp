#include <bits/stdc++.h>

using namespace std;

#define SIZE 8

int main() {
    int p[SIZE] = {2, 3, 5, 7, 11, 13, 17, 19};

    int v[SIZE];
    for (int i = 0; i < SIZE; i++) {
        cin >> v[i];
    }

    int ans = 0;
    while (true) {
        v[0]++;

        // Overflow handler
        for (int i = 0; i < SIZE - 1 && v[i] >= p[i]; i++) {
            v[i] = 0;
            v[i + 1]++;
        }

        if (v[SIZE - 1] >= p[SIZE - 1]) {
            // All overflow
            break;
        } else {
            // Not max overflow
            ans++;
        }
    }

    cout << ans;

    return 0;
}