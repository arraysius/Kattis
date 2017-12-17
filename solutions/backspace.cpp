#include <bits/stdc++.h>

using namespace std;

int main() {
    List<char> l;

    char temp;
    while (cin >> temp) {
        if (temp == '<') {
            l.pop_back();
        } else {
            l.push_back(temp);
        }
    }

    for (char c : l) {
        cout << c;
    }

    return 0;
}