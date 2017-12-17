#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> s;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;

        if (s.empty()) {
            s.push(val);
            continue;
        }

        if ((val + s.top()) % 2 == 0) {
            s.pop();
        } else {
            s.push(val);
        }
    }

    cout << s.size() << endl;

    return 0;
}