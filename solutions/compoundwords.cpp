#include <bits/stdc++.h>

using namespace std;

int main() {
    unordered_set<string> words;
    set<string> compoundWords;

    string word;
    while (cin >> word) {
        words.insert(word);
    }

    for (auto &w1 : words) {
        for (auto &w2 : words) {
            if (w1 != w2) {
                compoundWords.insert(w1 + w2);
            }
        }
    }

    for (auto &w : compoundWords) {
        cout << w << endl;
    }

    return 0;
}
