#include <bits/stdc++.h>

using namespace std;

int main () {
    char name[101];
    scanf("%s", name);

    vector<char> uppercases;
    for (int i = 0; i < strlen(name); i++) {
        if (name[i] >= 65 && name[i] <= 90) {
            uppercases.push_back(name[i]);
        }
    }

    for (char uppercase : uppercases) {
        cout << uppercase;
    }
    cout <<endl;
}