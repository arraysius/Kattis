#include <bits/stdc++.h>

using namespace std;

// Pre C++11
// bool cmp(string a, string b) {
//     if (a[0] != b[0])
//         return a[0] < b[0];
//     else
//         return a[1] < b[1];
// }

int main() {
    bool first = true;
    int cases;
    do {
        cin >> cases;

        string names[cases];
        for (int i = 0; i < cases; i++) {
            cin >> names[i] >> ws;
        }

        // stable_sort(names, names + cases, cmp);
        stable_sort(names, names + cases, [](string a, string b) {
            if (a[0] != b[0])
                return a[0] < b[0];
            else
                return a[1] < b[1];
        });

        for (string n : names) {
            cout << n << endl;
        }

        if (!first)
            cout << endl;
        first = false;
    } while (cases != 0);

    return 0;
}