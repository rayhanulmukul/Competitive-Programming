#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int L = max({__builtin_popcount(a), __builtin_popcount(b), __builtin_popcount(c)});

    int maxVal = (c | 0) - (b | 0);
    for (int i = L-1; i >= 0; i--) {
        if ((c >> i) & 1) {
            if ((b >> i) & 1) {
                maxVal += (1 << i);
            } else if (maxVal < (1 << i)) {
                break;
            }
        } else {
            if ((b >> i) & 1 && maxVal >= (1 << i)) {
                maxVal -= (1 << i);
            }
        }
    }

    int ans = (maxVal >= 0) ? (1 << (L+1)) - (1 << L) : 0;
    cout << ans << endl;

    return 0;
}
