#include <bits/stdc++.h>

using namespace std;

int main() {
    int minv = 1, maxv = 1000;
    string result;
    do {
        // Make guess
        int guess = (maxv + minv) / 2;
        cout << guess << endl << flush;

        // Get result
        cin >> result;
        if (result == "lower")
            maxv = guess - 1;
        else
            minv = guess + 1;
    } while (result != "correct");

    return 0;
}