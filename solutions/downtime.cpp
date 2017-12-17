#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    double k;
    cin >> n >> k;

    multimap<int, int> sequence;
    while (n--) {
        int t;
        cin >> t;
        sequence.insert({t, 1});
        sequence.insert({t + 1000, -1});
    }

    int topRPS = 0, currRPS = 0;
    for (auto p : sequence) {
        currRPS += p.second;
        topRPS = max(topRPS, currRPS);
    }

    cout << ceil(topRPS / k) << endl;

    return 0;
}
