#include <bits/stdc++.h>

using namespace std;

int main() {
    while (true) {
        int N;
        cin >> N >> ws;

        if (N == 0) {
            break;
        }

        map<string, set<string>> report;

        for (int i = 0; i < N; i++) {
            string name;
            string food;

            string line;
            getline(cin, line);
            istringstream iss(line);

            getline(iss, name, ' ');
            while (getline(iss, food, ' ')) {
                report[food].insert(name);
            }
        }
        
        for (auto it = report.begin(); it != report.end(); it++) {
            cout << it->first << " ";
            for (auto &name : it->second) {
                cout << name << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
