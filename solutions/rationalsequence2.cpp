#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);

    int TC;
    cin >> TC;

    while (TC--) {
        int K;
        cin >> K >> ws;

        stack<char> path;

        int p;
        int q;

        string pq, ps, qs;
        getline(cin, pq);
        istringstream iss(pq);
        getline(iss, ps, '/');
        getline(iss, qs, '/');

        p = stoi(ps);
        q = stoi(qs);

        // cout << p << "," << q << endl;
        
        while (!(p == 1 && q == 1)) {
            if (p < q) {
                path.push('L');
                q -= p;
            } else {
                path.push('R');
                p -= q;
            }
        }

        int index = 1;

        while (!path.empty()) {
            if (path.top() == 'L') {
                index = index << 1;
            } else {
                index = (index << 1) + 1;
            }

            path.pop();
        }

        cout << K << " " << index << endl;
    }

    return 0;
}
