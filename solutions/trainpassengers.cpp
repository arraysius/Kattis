#include <bits/stdc++.h>

using namespace std;

int main() {
    int C, n;
    cin >> C >> n;

    bool possible = true;

    int train = 0;
    while (n--) {
        int left, entered, wait;
        cin >> left >> entered >> wait;

        if (left > train || train - left + entered > C ||
            (wait > 0 && (C - (train - left + entered)) > 0)) {
            possible = false;
            break;
        }

        train -= left;
        train += entered;
    }

    if (train > 0)
        possible = false;

    cout << (possible ? "possible" : "impossible") << endl;

    return 0;
}
