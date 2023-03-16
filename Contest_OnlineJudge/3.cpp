#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

const int MAXN = 1005;
int H, W;
int A[MAXN][MAXN];
vector<vector<int>> dp(MAXN, vector<int>(MAXN, 0));

int main() {
    cin >> H >> W;

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> A[i][j];
        }
    }

    return 0;
}
