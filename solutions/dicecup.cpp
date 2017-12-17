#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    map<int, int> freq;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            freq[i + j]++;
        }
    }

    map<int, vector<int>> sorted;
    for (auto &p : freq) {
        sorted[p.second].push_back(p.first);
    }

    for (auto &v : sorted.rbegin()->second) {
        cout << v << endl;
    }

    return 0;
}
