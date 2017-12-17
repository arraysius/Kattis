#include <bits/stdc++.h>

using namespace std;

int main() {
    bool isFirst = true;
    while (true) {
        int n;
        cin >> n;

        if (n == 0) {
            break;
        }

        tuple<int, int, int> A[n];
        int B[n];

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0) {
                    int temp;
                    cin >> temp;
                    A[j] = make_tuple(j, temp, -1);
                } else {
                    cin >> B[j];
                }
            }
        }

        sort(A, A + n, [](tuple<int, int, int> a, tuple<int, int, int> b) {
            return get<1>(a) < get<1>(b);
        });
        sort(B, B + n);
        for (int i = 0; i < n; i++) {
            get<2>(A[i]) = B[i];
        }

        sort(A, A + n, [](tuple<int, int, int> a, tuple<int, int, int> b) {
            return get<0>(a) < get<0>(b);
        });

        if (isFirst) {
            isFirst = false;
        }

        if (!isFirst) {
            cout << endl;
        }

        for (tuple<int, int, int> t : A) {
            cout << get<2>(t) << endl;
        }
    }

    return 0;
}