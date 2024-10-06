#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const long long MOD = 998244353;

// Function to count the number of ways to decode a string with `?`
long long countDecodings(const string &s) {
    int n = s.length();
    vector<long long> dp(n + 1, 0);
    dp[0] = 1; // Base case: one way to decode an empty string

    for (int i = 1; i <= n; ++i) {
        // Single digit decode (1-9)
        if (s[i - 1] == '?') {
            dp[i] = (dp[i] + 9 * dp[i - 1]) % MOD; // 1-9
        } else if (s[i - 1] != '0') {
            dp[i] = (dp[i] + dp[i - 1]) % MOD; // Only valid digits
        }

        // Two digit decode (10-26)
        if (i > 1) {
            if (s[i - 2] == '?' && s[i - 1] == '?') {
                dp[i] = (dp[i] + 15 * dp[i - 2]) % MOD; // 10-26
            } else if (s[i - 2] == '?') {
                if (s[i - 1] >= '0' && s[i - 1] <= '6') {
                    dp[i] = (dp[i] + 2 * dp[i - 2]) % MOD; // 10 or 20
                } else {
                    dp[i] = (dp[i] + dp[i - 2]) % MOD; // 1-2 prefix with 0-9
                }
            } else if (s[i - 1] == '?') {
                if (s[i - 2] == '1') {
                    dp[i] = (dp[i] + 9 * dp[i - 2]) % MOD; // 10-19
                } else if (s[i - 2] == '2') {
                    dp[i] = (dp[i] + 7 * dp[i - 2]) % MOD; // 20-26
                }
            } else {
                int two_digit = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
                if (two_digit >= 10 && two_digit <= 26) {
                    dp[i] = (dp[i] + dp[i - 2]) % MOD; // Valid two-digit decode
                }
            }
        }
    }
    return dp[n];
}

// Generate the uncorrupted string with the maximum number of decodings
void generateMaxStrings(const string &E, int K, string &result, long long &max_count) {
    // We can store the possible combinations and their counts
    unordered_map<string, long long> count_map;

    // We'll generate possible uncorrupted strings by replacing '?' and counting the decodings
    string current;

    // A lambda function to explore replacements
    function<void(int)> explore = [&](int idx) {
        if (idx == E.size()) {
            long long count = countDecodings(current);
            count_map[current] = (count_map[current] + count) % MOD;
            return;
        }

        if (E[idx] == '?') {
            for (char digit = '0'; digit <= '9'; ++digit) {
                // Prevent leading zero
                if (current.empty() && digit == '0') continue;  
                current += digit;
                explore(idx + 1);
                current.pop_back();
            }
        } else {
            // Prevent leading zero
            if (current.empty() && E[idx] == '0') return; 
            current += E[idx];
            explore(idx + 1);
            current.pop_back();
        }
    };

    explore(0);

    // Now find the max_count and strings
    max_count = 0;
    vector<string> max_strings;

    for (const auto &pair : count_map) {
        if (pair.second > max_count) {
            max_count = pair.second;
            max_strings.clear();
            max_strings.push_back(pair.first);
        } else if (pair.second == max_count) {
            max_strings.push_back(pair.first);
        }
    }

    // Sort strings to find the K-th largest
    sort(max_strings.begin(), max_strings.end());

    if (K <= max_strings.size()) {
        result = max_strings[K - 1];
    } else {
        result = ""; // Should not happen based on constraints
    }
}

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        string E;
        int K;
        cin >> E >> K;

        string result;
        long long max_count;

        generateMaxStrings(E, K, result, max_count);

        // Output the result
        cout << "Case #" << t << ": " << result << " " << max_count << endl;
    }

    return 0;
}
