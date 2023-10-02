#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int i, j, k, n, m, p, cases = 0;
    
    while (getline(cin, s)) {
        sscanf(s.c_str(), "%d", &n);
        m = 0;
        for (i = 0; s[i]; i++) {
            if (s[i] == '!') {
                m++;
            }
        }

        int C[1005] = {};
        for (i = n; i >= 0; i -= m) {
            p = i;
            for (j = 2; j <= p; j++) {
                while (p % j == 0) {
                    p /= j;
                    C[j]++;
                }
            }
        }
        for(int i = 0; i < 1005; i++){
            cout << C[i] << " ";
        }
        

        long long res = 1;
        double sum = 0;
        for (i = 0; i <= n; i++) {
            res *= C[i] + 1;
            sum += log10(C[i] + 1);
        }

        cout << "Case " << ++cases << ": ";
        if (ceil(sum) > 18) {
            cout << "Infinity" << endl;
        } else {
            cout << res << endl;
        }
    }
    
    return 0;
}
