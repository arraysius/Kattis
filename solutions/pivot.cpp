#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int leftMax[N], rightMin[N];
    leftMax[0] = A[0];
    for (int i = 1; i < N; i++) {
        leftMax[i] = max(leftMax[i - 1], A[i]);
    }
    rightMin[N - 1] = A[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        rightMin[i] = min(rightMin[i + 1], A[i]);
    }

    int possiblePos = 0;
    for (int i = 0; i < N; i++) {
        if ((A[i] >= leftMax[i]) && (A[i] <= rightMin[i])) {
            possiblePos++;
        }
    }

    cout << possiblePos << endl;

    return 0;
}