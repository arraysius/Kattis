#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);

    int case_no = 1, n;
    while (cin >> n) {
        int numbers[30];
        for (int i = 0; i < n; i++) {
            cin >> numbers[i];
        }
        auto values = minmax_element(numbers, numbers + n);
        int minv = *values.first; // *min_element(numbers, numbers + n);
        int maxv = *values.second; // *max_element(numbers, numbers + n);
        printf("Case %d: %d %d %d\n", case_no, minv, maxv, maxv - minv);
        case_no++;
    }
}