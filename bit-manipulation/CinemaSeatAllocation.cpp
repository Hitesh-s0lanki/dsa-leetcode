// 1386. Cinema Seat Allocation
//
// n = number of rows (1 <= n <= 1e9), m = reservedSeats.length (m <= min(10 * n, 1e4))
// r = number of distinct reserved rows, r <= min(m, n)  (each row holds <= 10 seats, so r >= m / 10)
//
// Time Complexity: O(m)
//      -> O(m) to group the reserved seats by row (O(1) average per hash insert)
//      -> O(r) to scan the reserved rows, O(1) work per row (only seats 2..9 matter)
//      -> untouched rows are counted in O(1) with (n - r) * 2, never iterated
// Space Complexity: O(m)
//      -> the hash map of reserved rows; independent of n, so n = 1e9 is fine
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// Set: O(m) time, O(m) space -- one hash-set node per reserved seat.
int solveSet(int n, vector<vector<int>> &reservedSeats) {
    unordered_map<int, unordered_set<int>> mp;

    for (vector<int> reservedSeat : reservedSeats) {
        int row = reservedSeat[0];
        int seat = reservedSeat[1];

        mp[row].insert(seat);
    }

    int result = (n - mp.size()) * 2;  // for the empty seats;

    for (auto &[row, bookedSeats] : mp) {
        auto isAvailable = [&](int seat) {
            return bookedSeats.find(seat) == bookedSeats.end();
        };

        bool graupA = isAvailable(2) && isAvailable(3) && isAvailable(4) & isAvailable(5);
        bool graupB = isAvailable(4) && isAvailable(5) && isAvailable(6) & isAvailable(7);
        bool graupC = isAvailable(6) && isAvailable(7) && isAvailable(8) & isAvailable(9);

        if (graupA && graupC)
            result += 2;
        else if (graupA || graupB || graupC)
            result += 1;
    }

    return result;
}

// Bitmask: O(m) time, O(r) space -- one int per reserved row instead of a set of seats,
// and the three group checks become single AND operations.
int solveBit(int n, vector<vector<int>> &reservedSeats) {
    unordered_map<int, int> mp;

    for (vector<int> reservedSeat : reservedSeats) {
        int row = reservedSeat[0];
        int seat = reservedSeat[1];

        mp[row] |= (1 << seat);
    }

    int result = (n - mp.size()) * 2;  // for the empty seats;

    int maskA = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
    int maskB = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
    int maskC = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);

    for (auto &[row, bookedSeats] : mp) {
        bool graupA = (bookedSeats & maskA) == 0;
        bool graupB = (bookedSeats & maskB) == 0;
        bool graupC = (bookedSeats & maskC) == 0;

        if (graupA && graupC)
            result += 2;
        else if (graupA || graupB || graupC)
            result += 1;
    }

    return result;
}

int maxNumberOfFamilies(int n, vector<vector<int>> &reservedSeats) {
    // using the set operation
    // return solveSet(n, reservedSeats);

    // using the bit manipulation
    return solveBit(n, reservedSeats);
}

int main() {
    int n = 3;
    vector<vector<int>> reservedSeats = {
        {1, 2}, {1, 3}, {1, 8}, {2, 6}, {3, 1}, {3, 10}};

    cout << maxNumberOfFamilies(n, reservedSeats) << endl;  // 4

    return 0;
}
