#include <iostream>
using namespace std;

void solve(int test_case) {
    long long N;
    int P;
    cin >> N >> P;

    string winner;
    if (N == 1) {
        // Only one stone, so Oddius wins if he starts
        winner = (P == 2) ? "Oddius" : "Evenius";
    } else if (N % 2 == 0) {
        // For an even number of stones
        winner = (P == 1) ? "Evenius" : "Oddius";
    } else {
        // For an odd number of stones
        winner = "Oddius";
    }

    cout << "Case " << test_case << ": " << winner << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(i);
    }
    return 0;
}
