#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    multiset<int> numbers;

    while (n--) {
        int num;
        cin >> num;
        numbers.insert(num);
    }

    int value[2] = {0, 0};

    while (!numbers.empty()) {
        value[0] += *numbers.rbegin();
        numbers.erase(--numbers.end());

        if (numbers.empty())
            break;

        value[1] += *numbers.rbegin();
        numbers.erase(--numbers.end());
    }

    cout << value[0] << " " << value[1] << endl;

    return 0;
}
