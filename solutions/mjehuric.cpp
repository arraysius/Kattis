#include <bits/stdc++.h>

using namespace std;

#define MAX_N 5

int main() {
    int A[MAX_N];
    for (int i = 0; i < MAX_N; i++) {
        cin >> A[i];
    }

    // Time complexity = O(n^3)
    for (int i = 0; i < MAX_N - 1; i++) {         // O(n)
        for (int j = 0; j < MAX_N - i - 1; j++) { // O(n)
            if (A[j] > A[j + 1]) {
                swap(A[j], A[j + 1]);

                for (int n : A) { // O(n)
                    cout << n << " ";
                }
                cout << endl;
            }
        }
    }

    return 0;
}