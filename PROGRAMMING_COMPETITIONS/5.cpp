#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void solve(int tt) {
    int n;
    cin >> n;
    unordered_map<int, int> preCal; // Track elements already processed
    unordered_map<int, int> mp;     // Track remaining elements
    vector<int> a(n);
    
    // Read input and populate the map with the count of elements
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    
    int ans = 0;

    // Iterate through the array
    for (int i = 0; i < n; i++) {
        // Decrease the count of the current element in the remaining elements map
        mp[a[i]]--;
        
        // Remove element from map if its count becomes zero (to optimize the lookup)
        if (mp[a[i]] == 0) {
            mp.erase(a[i]);
        }

        // If not the first element, increment the count in the prefix map
        if (i > 0) {
            preCal[a[i - 1]]++;
        }

        // If there's a match for -a[i] in the prefix map, calculate its contribution
        if (preCal.count(-a[i])) {
            int x = preCal[-a[i]];
            
            // Instead of looping through all elements, directly calculate valid pairs
            for (const auto& it : mp) {
                // Only count elements that are not equal to a[i] or -a[i]
                if (it.first != a[i] && it.first != -a[i]) {
                    ans += x * it.second;
                }
            }
        }
    }
    
    cout << ans << endl; // Output the result
}
