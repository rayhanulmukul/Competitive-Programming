#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int M, N;
    cin >> M >> N;

    vector<int> A(M), B(M);
    set<int> uniqueIndices;

    for (int i = 0; i < M; i++) {
        cin >> A[i];
        uniqueIndices.insert(A[i]);
    }

    for (int i = 0; i < M; i++) {
        cin >> B[i];
        uniqueIndices.insert(B[i]);
    }

    int X_size = uniqueIndices.size();
    if (X_size == N) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
