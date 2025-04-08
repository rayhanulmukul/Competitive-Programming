#include <iostream>
using namespace std;

void solve(int tt) {
    int x;
    cin >> x;

    // Try y as the largest power of 2 less than x
    int y = 1;
    while (y * 2 < x) {
        y *= 2;
    }

    // Check y and y-1 as candidates
    for (int candidate : {y, y - 1}) {
        if (candidate >= 1 && candidate < x) {
            int z = x ^ candidate;
            if (x + candidate > z && candidate + z > x && x + z > candidate) {
                cout << candidate << endl;
                return;
            }
        }
    }

    // If no valid y is found, output -1
    cout << -1 << endl;
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        solve(tt);
    }
    return 0;
}