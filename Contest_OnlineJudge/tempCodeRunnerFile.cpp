#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 998244353

using namespace std;

// Function to calculate modular inverse using Fermat's Little Theorem
long long modInverse(long long a, long long m) {
    long long result = 1, power = m - 2;
    while (power) {
        if (power & 1) result = (result * a) % m;
        a = (a * a) % m;
        power >>= 1;
    }
    return result;
}

int main() {
    int N;
    cin >> N;
    vector<long long> red(N), green(N), expected_weights(N);

    for (int i = 0; i < N; i++) cin >> red[i];
    for (int i = 0; i < N; i++) cin >> green[i];

    // Calculate the expected weight sum for each box (r + g) instead of (r + g) / 2
    for (int i = 0; i < N; i++) {
        expected_weights[i] = red[i] + green[i];
    }

    // Sort expected weight sums in descending order to maximize sum as we increment K
    sort(expected_weights.rbegin(), expected_weights.rend());

    // Precompute the modular inverse of 2 (for division by 2)
    long long inv2 = modInverse(2, MOD);

    // Running sum of expected weights for each K
    long long P = 0;
    for (int k = 1; k <= N; k++) {
        P = (P + expected_weights[k - 1]) % MOD;  // cumulative sum up to k elements
        long long Q = k;
        
        // Calculate (P * inv2 * Q^-1) % MOD
        long long result = (P * inv2 % MOD) * modInverse(Q, MOD) % MOD;
        cout << result << " ";
    }
    cout << endl;

    return 0;
}
