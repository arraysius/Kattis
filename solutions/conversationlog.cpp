#include <bits/stdc++.h>

using namespace std;

int main() {
    int M;
    cin >> M >> ws;

    unordered_set<string> users;
    unordered_map<string, unordered_map<string, int>>
        userWords; // <words, <users, freq>>

    // Read messages
    while (M--) {
        string line;
        getline(cin, line);
        istringstream iss(line);

        // User
        string user;
        getline(iss, user, ' ');
        users.insert(user);

        // Count words
        string word;
        while (getline(iss, word, ' ')) {
            // If word does not exist
            if (userWords.find(word) == userWords.end()) {
                userWords[word] = unordered_map<string, int>();
            }

            // If user does not exist
            if (userWords[word].find(user) == userWords[word].end()) {
                userWords[word][user] = 1;
            } else {
                userWords[word][user]++;
            }
        }
    }

    // Get popular words
    vector<pair<int, string>> words;
    for (auto &w : userWords) {
        // If said by more than 1 user
        if (w.second.size() == users.size()) {
            int freq = 0;
            for (auto &u : w.second) {
                freq += u.second;
            }
            words.push_back({freq, w.first});
        }
    }

    if (words.size() == 0) {
        cout << "ALL CLEAR" << endl;
        return 0;
    }

    // Sort
    sort(words.begin(), words.end(),
         [](pair<int, string> a, pair<int, string> b) {
             if (a.first == b.first) {
                 return a.second < b.second;
             }

             return a.first > b.first;
         });

    for (auto &w : words) {
        // cout << w.second << " " << w.first << endl;
        cout << w.second << endl;
    }

    return 0;
}
