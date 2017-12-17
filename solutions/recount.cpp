#include <bits/stdc++.h>

using namespace std;

int main() {
    unordered_map<string, int> candidates;

    string name;
    while (getline(cin, name)) {
        if (name == "***")
            break;

        if (candidates.find(name) == candidates.end()) {
            // Not found
            candidates[name] = 1;
        } else {
            // Already exists
            candidates[name]++;
        }
    }

    int maxVotes = 0;
    for (auto &candidate : candidates) {
        if (candidate.second > maxVotes) {
            maxVotes = candidate.second;
            name = candidate.first;
        } else if (candidate.second == maxVotes) {
            name = "!";
        }
    }

    cout << (name != "!" ? name : "Runoff!") << endl;

    return 0;
}
