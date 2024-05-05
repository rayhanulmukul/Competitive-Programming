#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minAnagramLength(string s) {
        unordered_map<char, int> freq;
        int mini = INT_MAX, count = 0;
        for (int i = 0; i < s.length(); i++) {
            unordered_set<char> seen;
            count = 0;
            while (i < s.length()) {
                if (freq.find(s[i]) != freq.end() && freq[s[i]] >= 1)
                    break;
                freq[s[i]]++;
                seen.insert(s[i]);
                count++;
                i++;
            }
            i--;
            if (seen.size() > 0)
                mini = min(mini, count);
            freq.clear();
        }
        return mini == INT_MAX ? 0 : mini;
    }
};

int main() {
    Solution sol;
    string s = "xxe";
    int result = sol.minAnagramLength(s);
	cout << result << endl;
    // Output result
    return 0;
}
