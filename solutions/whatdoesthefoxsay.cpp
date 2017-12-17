#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T >> ws;

    for (int i = 0; i < T; i++) {
        list<string> sounds;
        unordered_set<string> soundsHash;

        string line;
        getline(cin, line);
        istringstream iss(line);
        string sound;
        while (getline(iss, sound, ' ')) {
            sounds.push_back(sound);
            soundsHash.insert(sound);
        }

        while (getline(cin, line)) {
            if (line == "what does the fox say?") {
                for (auto s : sounds) {
                    if (soundsHash.find(s) != soundsHash.end()) {
                        cout << s << " ";
                    }
                }
                cout << endl;
                break;
            } else {
                istringstream iss(line);
                for (int j = 0; j < 3; j++) {
                    getline(iss, sound, ' ');
                }
                soundsHash.erase(sound);
            }
        }
    }

    return 0;
}
