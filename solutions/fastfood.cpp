#include <bits/stdc++.h>

using namespace std;

int main() {
    int TC;
    cin >> TC;

    while (TC--) {
        int n, m;
        cin >> n >> m;

        int total = 0;
        int collection[m + 1];
        unordered_multimap<int, vector<int>> prizes;

        while (n--) {
            int k;
            cin >> k;

            int value;
            vector<int> types;

            while (k--) {
                int t;
                cin >> t;
                types.push_back(t);
            }

            cin >> value;

            prizes.insert({value, types});
        }

        // Read collection
        for (int i = 1; i <= m; i++) {
            cin >> collection[i];
        }

        // Try prize
        for (auto p : prizes) {
            bool hasAllStickers = true;

            // Try to claim as many times as possible
            while (hasAllStickers) {
                // Check for all sticker types
                for (auto type : p.second) {
                    if (collection[type] <= 0) {
                        hasAllStickers = false;
                        break;
                    }
                }

                // If has all sticker types
                if (hasAllStickers) {
                    total += p.first;
                    for (auto type : p.second) {
                        collection[type]--;
                    }
                }
            }
        }

        cout << total << endl;
    }

    return 0;
}
