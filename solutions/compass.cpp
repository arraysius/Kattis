#include <bits/stdc++.h>

using namespace std;

int main() {
    int n1, n2;
    cin >> n1 >> n2;

    int change;

    if (abs(n2 - n1) == 360 - abs(n1 - n2)) {
        change = abs(n2 - n1);
    } else if (abs(n2 - n1) < 360 - abs(n2 - n1)) {
        change = (n1 < n2) ? abs(n2 - n1) : -(abs(n2 - n1));
    } else {
        change = (n1 < n2) ? -(360 - abs(n2 - n1)) : 360 - abs(n2 - n1);
    }

    cout << change << endl;

    return 0;
}
