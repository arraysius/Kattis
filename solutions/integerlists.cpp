#include <bits/stdc++.h>

using namespace std;

int main() {
    int TC;
    cin >> TC;

    while (TC--) {
        string commands;
        cin >> commands;

        int n;
        string elements;
        cin >> n >> elements;

        elements = elements.substr(1, elements.length() - 2);
        istringstream iss(elements);

        deque<int> d;

        string value;
        while (getline(iss, value, ',')) {
            d.push_back(stoi(value));
        }

        bool valid = true;
        bool reversed = false;
        for (char &c : commands) {
            if (c == 'R') {
                reversed = !reversed;
            } else if (!d.empty()) {
                if (!reversed) {
                    d.pop_front();
                } else {
                    d.pop_back();
                }
            } else {
                valid = false;
                break;
            }
        }

        if (!valid) {
            cout << "error" << endl;
        } else {
            cout << "[";

            if (!d.empty()) {
                if (!reversed) {
                    cout << d.front();

                    if (d.size() > 1) {
                        for (int i = 1; i < d.size(); i++) {
                            cout << "," << d[i];
                        }
                    }
                } else {
                    cout << d.back();

                    if (d.size() > 1) {
                        for (int i = d.size() - 2; i >= 0; i--) {
                            cout << "," << d[i];
                        }
                    }
                }
            }

            cout << "]" << endl;
        }

        // for (auto &v : d) {
        //     cout << v << " ";
        // }
        // cout << endl;
    }

    return 0;
}
