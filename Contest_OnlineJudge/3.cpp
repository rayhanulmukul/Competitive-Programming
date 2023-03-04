#include <iostream>
#include <vector>

<<<<<<< Updated upstream
#define ll long long int
#define int ll
#define ld long double
#define pb push_back
#define mp make_pair
#define ft front()
#define bk back()
#define pi 2*acos(0.0)     /// acos(-1) , 3.14159265359
#define gap ' '
#define en '\n'
#define endl en
#define sz(x) (int(x.size()))
#define mem(a, b) memset(a, b, sizeof(a))
#define sor(x)  sort(x.begin(), x.end())
=======
using namespace std;
>>>>>>> Stashed changes

const int MOD = 1e9 + 7;

<<<<<<< Updated upstream
void solve(int tt){
    dbg(tt);
    // int n, mi = 1e9, ma = -1e9, ans = 0;
=======
// Computes the matrix power A^n modulo MOD using binary exponentiation
vector<vector<int>> matrix_power(const vector<vector<int>>& A, int n) {
    if (n == 0) {
        int sz = A.size();
        vector<vector<int>> X(sz, vector<int>(sz, 0));
        for (int i = 0; i < sz; i++) {
            X[i][i] = 1;
        }
        return X;
    }
    if (n == 1) {
        return A;
    }
    vector<vector<int>> X = matrix_power(A, n/2);
    X = matrix_multiply(X, X);
    if (n % 2 == 1) {
        X = matrix_multiply(X, A);
    }
    return X;
}

// Computes the product A*B modulo MOD
vector<vector<int>> matrix_multiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int m = A.size();
    int n = B.size();
    int p = B[0].size();
    vector<vector<int>> C(m, vector<int>(p, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] = (C[i][j] + (long long) A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

// Computes the n-th Fibonacci number modulo MOD using matrix exponentiation
int fib(int n) {
    if (n == 0) {
        return 0;
    }
    vector<vector<int>> A = {{1, 1}, {1, 0}};
    vector<vector<int>> X = matrix_power(A, n - 1);
    return X[0][0];
>>>>>>> Stashed changes
}

int main() {
    int f1, f2, n;
    cin >> f1 >> f2 >> n;
    if (n == 1) {
        cout << (f1 % MOD + MOD) % MOD << endl;
    } else if (n == 2) {
        cout << (f2 % MOD + MOD) % MOD << endl;
    } else {
        int ans = (fib(n) % MOD + MOD) % MOD;
        cout << ans << endl;
    }
    return 0;
}
