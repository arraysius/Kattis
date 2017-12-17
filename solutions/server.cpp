#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, T;
    cin >> N >> T;

    int complete = 0;
    for (int i = 0; i < N; i++) {
        int t;
        cin >> t;
        
        T -= t;
        if (T >= 0) {
            complete++;
        } else {
            break;
        }
    }

    cout << complete << endl;

    return 0;
}