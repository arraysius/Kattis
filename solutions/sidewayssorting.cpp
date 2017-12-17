#include <bits/stdc++.h>

using namespace std;

string lowercase(string s) {
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c >= 97) {
            s[i] = c - 32;
        }
    }
    return s;
}

int main() {
    int row, col;
    bool isFirst = true;
    while (true) {
        cin >> row >> col;

        if (row == 0 && col == 0) {
            break;
        }

        if (isFirst) {
            isFirst = false;
        } else {
            cout << endl;
        }

        string vertical[col];
        // fill(vertical, vertical + col, "");

        for (int r = 0; r < row; r++) {
            string temp;
            cin >> temp;
            for (int c = 0; c < col; c++) {
                vertical[c] += temp[c];
            }
        }

        sort(vertical, vertical + col, [](string s1, string s2) {
            return lowercase(s1) < lowercase(s2);
        });

        string toPrint[row];
        // fill(toPrint, toPrint + row, "");

        for (int c = 0; c < col; c++) {
            for (int r = 0; r < row; r++) {
                toPrint[r] += vertical[c][r];
            }
        }

        for (string s : toPrint) {
            cout << s << endl;
        }
    }

    return 0;
}