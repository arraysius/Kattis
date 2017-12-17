#include <bits/stdc++.h>

using namespace std;

int sumOfDigits(int num) {
    int total = 0;
    while (num > 0) {
        total += num % 10;
        num /= 10;
    }
    return total;
}

int main() {
    int L, D, X;
    cin >> L >> D >> X;

    for (int N = L; N <= D; N++) {
        if (sumOfDigits(N) == X) {
            cout << N << endl;
            break;
        }
    }

    for (int M = D; M >= L; M--) {
        if (sumOfDigits(M) == X) {
            cout << M << endl;
            break;
        }
    }
}