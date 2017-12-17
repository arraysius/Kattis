#include <bits/stdc++.h>

using namespace std;

int main() {
    unordered_set<string> combos;

    string moves = "BLR";
    sort(moves.begin(), moves.end());
    do {
        combos.insert(moves);
    } while (next_permutation(moves.begin(), moves.end()));

    string monster;
    cin >> monster;

    for (int i = 0; i < monster.length(); i++) {
        if (i + 2 < monster.length() &&
            combos.find(monster.substr(i, 3)) != combos.end()) {
            cout << 'C';
            i += 2;
        } else {
            char counter;
            switch (monster[i]) {
            case 'R':
                counter = 'S';
                break;
            case 'B':
                counter = 'K';
                break;
            case 'L':
                counter = 'H';
                break;
            }

            cout << counter;
        }
    }
    cout << endl;

    return 0;
}
