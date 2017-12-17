#include <bits/stdc++.h>

using namespace std;

vector<string> split(string s, string delim) {

}

int main() {
    // freopen("input.txt", "r", stdin);

    int cases;
    cin >> cases;

    for (int i = 0; i < cases; i++) {
        char name[31];
        int studiesYear, birthYear, courses;

        scanf("%s %d/%*d/%*d %d/%*d/%*d %d", name, &studiesYear, &birthYear, &courses);
        
        string eligibility;
        if (studiesYear >= 2010 || birthYear >= 1991) {
            eligibility = "eligible";
        } else if (courses > 40) {
            eligibility = "ineligible";
        } else {
            eligibility = "coach petitions";
        }

        cout << name << " " + eligibility << endl;
    }

    return 0;
}