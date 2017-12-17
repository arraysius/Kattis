#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        priority_queue<int, vector<int>, greater<int>> Ag, Am;

        int Ng, Nm;
        cin >> Ng >> Nm;

        int strength;
        for (int i = 0; i < Ng; i++) {
            cin >> strength;
            Ag.push(strength);
        }

        for (int i = 0; i < Nm; i++) {
            cin >> strength;
            Am.push(strength);
        }

        while (!Ag.empty() && !Am.empty()) {
            if (Ag.top() == Am.top()) { // Both has weakest
                Am.pop();
            } else if (Ag.top() < Am.top()) { // Godzilla weakest
                Ag.pop();
            } else { // MechaGodzilla weakest
                Am.pop();
            }
        }

        string winner;
        if (Ag.empty() && Am.empty()) {
            winner = "uncertain";
        } else if (Am.empty()) {
            winner = "Godzilla";
        } else {
            winner = "MechaGodzilla";
        }

        cout << winner << endl;
    }

    return 0;
}
