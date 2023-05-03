#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const int MAX_SIZE = 100;

void gauss_jordan(double a[][MAX_SIZE], double b[], int n) {
    // forward elimination
    for(int i=1; i<=n; i++) {
        // pivoting
        int max_row = i;
        for(int j=i+1; j<=n; j++) {
            if(fabs(a[j][i]) > fabs(a[max_row][i])) {
                max_row = j;
            }
        }
        if(max_row != i) {
            swap(a[i], a[max_row]);
            swap(b[i], b[max_row]);
        }
        // elimination
        for(int j=1; j<=n; j++) {
            if(j != i) {
                double factor = a[j][i] / a[i][i];
                for(int k=i+1; k<=n; k++) {
                    a[j][k] -= factor * a[i][k];
                }
                b[j] -= factor * b[i];
                a[j][i] = 0;
            }
        }
    }
    // backward substitution
    for(int i=1; i<=n; i++) {
        b[i] /= a[i][i];
    }
}

int main() {
    int n;
    double a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE];
    cout << "Enter the number of equations: ";
    cin >> n;
    cout << "Enter the coefficients of the equations:" << endl;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> a[i][j];
        }
        cin >> b[i];
    }
    gauss_jordan(a, b, n);
    cout << "Solution:" << endl;
    for(int i=1; i<=n; i++) {
        cout << "x[" << i << "] = " << fixed << setprecision(2) << b[i] << endl;
    }
    return 0;
}
