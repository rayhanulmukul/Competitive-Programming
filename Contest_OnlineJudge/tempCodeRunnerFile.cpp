#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the digit sum of a number
int digitSum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// Function to count the number of good integers less than or equal to N
int countGoodIntegers(int N) {
    int count = 0;

    for (int i = 1; i <= N; ++i) {
        if (i % digitSum(i) == 0) {
            ++count;
        }
    }

    return count;
}

int main() {
    // Input N
    int N;
    cout << "Enter the value of N: ";
    cin >> N;

    // Count the number of good integers
    int result = countGoodIntegers(N);

    cout << "Number of good integers less than or equal to " << N << ": " << result << endl;

    return 0;
}
