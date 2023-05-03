#include <iostream>
#include <cmath>

using namespace std;

bool find_pair(long long N, int& A, int& B) {
    int max_a = log(N) / log(3);
    int max_b = log(N) / log(5);
    for (A = 0; A <= max_a; A++) {
        for (B = 0; B <= max_b; B++) {
            if (pow(3, A) + pow(5, B) == N) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    long long N;
    int A, B;
    cin >> N;
    if (find_pair(N, A, B)) {
        cout << A << " " << B << endl;
    } else {
        cout << "-1" << endl;
    }
    return 
