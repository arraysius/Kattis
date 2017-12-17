#include <bits/stdc++.h>

using namespace std;

class Hotel {
  private:
    vector<bool> roomsTaken;

  public:
    Hotel(int noOfRooms) {
        // noOfRooms + 1 : Ignore room 0
        roomsTaken.assign(noOfRooms + 1, false);
    }

    void bookRoom(int roomNo) { roomsTaken[roomNo] = true; }

    bool isBooked(int roomNo) { return roomsTaken[roomNo]; }
};

int main() {
    int r, n;
    cin >> r >> n;

    Hotel hotel(r);

    for (int i = 0; i < n; i++) {
        int roomNo;
        cin >> roomNo;
        hotel.bookRoom(roomNo);
    }

    // No more available rooms
    if (r == n) {
        cout << "too late" << endl;
        return 0;
    }

    for (int i = 1; i <= r; i++) {
        if (!hotel.isBooked(i)) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}