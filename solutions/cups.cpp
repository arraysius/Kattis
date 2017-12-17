#include <bits/stdc++.h>

using namespace std;

int main () {
    int cases;
    cin >> cases >> ws;

    vector<pair<int, string>> cups;
    for (int i = 0; i < cases; i++) {
        string line;
        getline(cin, line);

        string a, b;
        istringstream ss(line);
        getline(ss, a, ' ');
        getline(ss, b, ' ');

        if (isdigit(a[0])) {
            // Diameter
            cups.push_back(make_pair(stoi(a), b));
        } else {
            // Radius
            cups.push_back(make_pair(stoi(b) * 2, a));
        }
    }
    
    sort(cups.begin(), cups.end());

    for (auto c: cups) {
        cout << c.second << endl;
    }

    return 0;
}