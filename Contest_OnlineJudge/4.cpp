#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int f(vector<int>& a, int x) {
    int n = a.size();
    int s = 0;
    for (int i = 0; i < n; i++) {
        s = (s * 10 + a[i]) % x;
    }
    return s;
}

bool is_palindrome(int n) {
    string s = to_string(n);
    return equal(s.begin(), s.end(), s.rbegin());
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int x = 1;
    for (int i = n-1; i >= 0; i--) {
        x = max(x, a[i]+1);
    }
    while (x > 1) {
        int fx = f(a, x);
        if (is_palindrome(fx)) {
            cout << x << endl;
            return 0;
        }
        x--;
    }
    cout << 1 << endl;
    return 0;
}
