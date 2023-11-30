#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// Function to check if the array 'a' satisfies the conditions
bool isValid(const vector<int>& a, const vector<vector<int>>& M) {
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && (a[i] | a[j]) != M[i][j]) {
                return false;
            }
        }
    }
    return true;
}

// Function to print the array 'a'
void printArray(const vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    srand(time(0));

    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<vector<int>> M(n, vector<int>(n));

    cout << "Enter the elements of matrix M:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> M[i][j];
        }
    }

    vector<int> a(n);

    // Try to find a valid array by generating random values
    do {
        for (int i = 0; i < n; ++i) {
            a[i] = rand() % (1 << 30); // Random value between 0 and 2^30 - 1
        }
    } while (!isValid(a, M));

    cout << "Found a valid array to open the lock:" << endl;
    printArray(a);

    return 0;
}
