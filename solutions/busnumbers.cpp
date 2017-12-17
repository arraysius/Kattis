#include <bits/stdc++.h>

using namespace std;

int main() {
    int buses;
    cin >> buses;

    vector<bool> bus(1001, false);

    for (int i = 0; i < buses; i++) {
        int n;
        cin >> n;
        bus[n] = true;
    }

    for (int i = 1; i <= 1000; i++) {
        if (bus[i]) {
            int j = i;
            cout << i;
            while (bus[i + 1]) {
                i++;
            }

            if (i - j == 0) {
                cout << " ";
            } else if (i - j == 1) {
                cout << " " << i << " ";
            } else {
                cout << "-" << i << " ";
            }
        }
    }

    return 0;
}
