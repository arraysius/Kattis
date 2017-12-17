#include <bits/stdc++.h>

using namespace std;

typedef tuple<double, double, string> dds;

int main() {
    int n;
    cin >> n;

    vector<dds> runners; // first leg other leg, name

    while (n--) {
        string name;
        double first, other;
        cin >> name >> first >> other;

        runners.push_back(make_tuple(first, other, name));
    }

    sort(runners.begin(), runners.end());

    double totalTime = 1e9;
    string names = "";

    for (auto &r : runners) {
        vector<dds> otherlegs(runners);        

        otherlegs.erase(find(otherlegs.begin(), otherlegs.end(), r));

        // for (auto &a : otherlegs) {
        //     cout << get<2>(a) << " " << get<1>(a) << " " << get<0>(a) << endl;
        // }
        // cout << endl;

        sort(otherlegs.begin(), otherlegs.end(),
             [](dds a, dds b) { return get<1>(a) < get<1>(b); });

        double newTime = get<0>(r);
        string tempNames = get<2>(r);
        for (int i = 0; i < 3; i++) {
            newTime += get<1>(otherlegs[i]);
            tempNames += "\n" + get<2>(otherlegs[i]);
        }

        if (newTime < totalTime) {
            totalTime = newTime;
            names = tempNames;
        }
    }

    cout << totalTime << "\n" << names << endl;

    return 0;
}
