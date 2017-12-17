#include <bits/stdc++.h>

using namespace std;

int main() {
    string line;
    cin >> line;

    multiset<int> deck[4];

    // Input
    for (int i = 0; i < line.length(); i += 3) {
        char suit = line[i];
        int number = stoi(line.substr(i + 1, 2));

        switch (suit) {
        case 'P':
            deck[0].insert(number);
            break;
        case 'K':
            deck[1].insert(number);
            break;
        case 'H':
            deck[2].insert(number);
            break;
        case 'T':
            deck[3].insert(number);
            break;
        }
    }

    // Check valid
    bool valid = true;
    for (int i = 0; i < 4; i++) {
        for (auto n : deck[i]) {
            if (deck[i].count(n) > 1) {
                valid = false;
                break;
            }
        }

        if (!valid)
            break;
    }

    // Print
    if (valid) {
        for (int i = 0; i < 4; i++) {
            cout << 13 - deck[i].size() << " ";
        }
        cout << endl;
    } else {
        cout << "GRESKA" << endl;
    }

    return 0;
}
