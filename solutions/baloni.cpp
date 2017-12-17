#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    int arrows = 0;
    int balloons[N];

    for (int i = 0; i < N; i++) {
        cin >> balloons[i];
    }

    for (int i = 0; i < N; i++) {
        int front = balloons[i];

        if (front == -1)
            continue;

        balloons[i] = -1;
        arrows++;

        for (int j = i + 1; j < N; j++) {
            if (balloons[j] == front - 1) {
                balloons[j] = -1;
                front--;

                if (front == 1)
                    break;
            }
        }
    }

    cout << arrows << endl;

    return 0;
}
