#include <bits/stdc++.h>

using namespace std;

int main() {
    int jack, jill;

    while ((jack + jill) != 0) {
        cin >> jack >> jill;

        if ((jack + jill) == 0) {
            break;
        }

        int ans = 0;
        unordered_set<int> jackHash;

        for (int i = 0; i < jack; i++) {
            int jackCD;
            cin >> jackCD;
            jackHash.insert(jackCD);
        }

        for (int i = 0; i < jack; i++) {
            int jillCD;
            cin >> jillCD;
            if (jackHash.find(jillCD) != jackHash.end()) {
                ans++;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
