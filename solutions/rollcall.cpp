#include <bits/stdc++.h>

using namespace std;

int main() {
    string first, last;

    map<string, set<string>> fnames; // first : last
    map<string, set<string>> lnames; // last : first

    while (cin >> first >> last) {
        fnames[first].insert(last);
        lnames[last].insert(first);
    }

    // For every last name
    for (auto &lp : lnames) {
        // For every first name in last name
        for (auto &f : lp.second) {
            if (fnames[f].size() > 1) {
                // If first name is not unique
                // If there is another first name with different last name
                cout << f << " " << lp.first << endl;
            } else {
                // First name is unique
                cout << f << endl;
            }
        }
    }

    return 0;
}
