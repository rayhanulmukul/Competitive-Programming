#include <iostream>
#include <cmath>

using namespace std;

const long long MOD = 998244353;

// Function to compute (base^exp) % mod using binary exponentiation
long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Function to compute modular inverse of a number 'a' under modulo 'mod'
long long mod_inverse(long long a, long long mod) {
    return mod_pow(a, mod - 2, mod);  // Using Fermat's Little Theorem
}

// Function to compute the expected days to reach weight G from weight W
long long expected_days(long long W, long long G, long long L) {
    if (L == 0) {
        // If L is 0, we can only decrease weight directly
        return (W - G) % MOD;
    }
    
    // When L > 0, we calculate using random walk properties with reflective barrier.
    long long numerator = W - G; // This is like the distance to cover.
    long long denominator = L + 1; // The total number of possible states (since you can move up to W + L).

    long long inv_denominator = mod_inverse(denominator, MOD); // Modular inverse of denominator.

    // Expected number of steps is p/q (mod 998244353)
    long long result = (numerator * inv_denominator) % MOD;

    return result;
}

int main() {
    int T;  // Number of test cases
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        long long W, G, L;
        cin >> W >> G >> L;

        // Calculate the expected days and output the result
        long long result = expected_days(W, G, L);
        cout << "Case #" << t << ": " << result << endl;
    }

    return 0;
}
