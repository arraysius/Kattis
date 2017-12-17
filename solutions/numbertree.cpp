#include <bits/stdc++.h>

using namespace std;

int main() {
    int H;
    cin >> H;

    // int treeSize = pow(2, H + 1) - 1;
    int treeSize = (1 << (H + 1)) - 1; // bitshift is faster

    int index = 1;
    char direction;
    while (cin >> direction) {
        if (direction == 'L') {
            index = index << 1;
        } else {
            index = (index << 1) + 1;
        }
    }

    cout << treeSize - index + 1 << endl;

    return 0;
}