#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> position;
    multiset<int> roll;

    while (n--) {
        int v;
        cin >> v;
        position.push_back(v);
        roll.insert(v);
    }

    int value = -1;
    set<int> nonunique;
    for (auto it = roll.rbegin(); it != roll.rend(); it++) {
        if (nonunique.find(*it) != nonunique.end()) {
            continue;
        } else if (roll.count(*it) > 1) {
            nonunique.insert(*it);
        } else {
            value = *it;
            break;
        }
    }

    if (value != -1) {
        cout << distance(position.begin(),
                         find(position.begin(), position.end(), value)) +
                    1
             << endl;
        ;
    } else {
        cout << "none" << endl;
    }

    return 0;
}
