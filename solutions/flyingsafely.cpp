#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int n, m;
        cin >> n >> m;

        unordered_set<int> islands;
        for (int j = 0; j < m; j++) {
            int a, b;
            cin >> a >> b;
            islands.insert(a);
            islands.insert(b);
        }

        cout << islands.size() - 1 << endl;
    }

    return 0;
}
