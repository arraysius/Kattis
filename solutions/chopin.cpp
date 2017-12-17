#include <bits/stdc++.h>

using namespace std;

int main() {
    int TC = 0;
    string note, tonality;
    while (cin >> note >> tonality) {
        TC++;

        // Unique
        if (note.length() == 1) {
            cout << "Case " << TC << ": UNIQUE" << endl;
            continue;
        }

        char newnote, newacci;
        if (note[1] == '#') { // Forward
            newnote = note[0] + 1;
            newacci = 'b';

            if (newnote > 71)
                newnote -= 7;
        } else { // Backward
            newnote = note[0] - 1;
            newacci = '#';

            if (newnote < 65)
                newnote += 7;
        }

        printf("Case %d: %c%c %s\n", TC, newnote, newacci, tonality.c_str());
    }

    return 0;
}
