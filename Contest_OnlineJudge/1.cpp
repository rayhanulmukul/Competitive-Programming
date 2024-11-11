#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;

    // Generate sequence by starting from 2 and adding a constant step, e.g., 5
    vector<int> sequence;
    int start = 2;
    for (int i = 0; i < n; ++i) {
        sequence.push_back(start);
        start += 5; // Choosing step size 5 to avoid overlap and maintain uniqueness
    }

    // Print the generated sequence
    for (int num : sequence) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
