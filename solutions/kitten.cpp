#include <bits/stdc++.h>

using namespace std;

int main() {
    int parentArray[101];
    fill_n(parentArray, 101, -1);

    int K;
    cin >> K >> ws;

    string line;
    while (getline(cin, line)) {
        if (stoi(line) == -1)
            break;

        istringstream iss(line);

        int parent;
        string parentstr;
        int child;
        string childstr;

        getline(iss, parentstr, ' ');
        parent = stoi(parentstr);
        while (getline(iss, childstr, ' ')) {
            child = stoi(childstr);
            parentArray[child] = parent;
        }
    }

    while (K != -1) {
        cout << K << " ";
        K = parentArray[K];
    }
    cout << endl;

    return 0;
}
