#include <iostream>
#include <cmath>
#include <algorithm>
#define MOD 998244353
using namespace std;

// Function to calculate gcd for fraction reduction
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate the square of the minimal jump distance L^2
void calculateDistanceSquared(int X, int Y, int Z) {
    // Calculate the semi-perimeter
    double s = (X + Y + Z) / 2.0;
    
    // Calculate the area of the triangle using Heron's formula
    double area = sqrt(s * (s - X) * (s - Y) * (s - Z));

    // Calculate L^2 in terms of the area and side lengths (simplified approximation)
    // We use the formula L^2 ≈ (4 * area^2) / (s * (s - X) * (s - Y) * (s - Z))
    double L_squared = (4 * area * area) / (s * (s - X) * (s - Y) * (s - Z));
    
    // Convert L_squared to numerator/denominator form
    long long numerator = static_cast<long long>(round(L_squared * 1e6)); // Use rounding to avoid precision issues
    long long denominator = 1000000; // Since we scaled L_squared up by 1e6

    // Reduce the fraction by finding the gcd
    long long common_divisor = gcd(numerator, denominator);
    numerator /= common_divisor;
    denominator /= common_divisor;

    // Output the result as an irreducible fraction
    cout << numerator << "/" << denominator << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int X, Y, Z;
        cin >> X >> Y >> Z;
        calculateDistanceSquared(X, Y, Z);
    }
    return 0;
}
