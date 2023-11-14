#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> counts;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        counts[a[i]]++;
    }

    int b1 = -1, b2 = -1, b3 = -1;

    for (int i = 0; i < n; i++) {
        if (counts[a[i]] >= 2) {
            if (b1 == -1) {
                b1 = a[i];
            } else if (b2 == -1) {
                b2 = a[i];
            } else {
                b3 = a[i];
            }
        }
    }

    if (b1 == -1) {
        for (int i = 0; i < n; i++) {
            if (b2 == -1) {
                if (counts[a[i]] > 1) {
                    b2 = a[i];
                }
            } else {
                break;
            }
        }
    }
    set <int> s;
    for(int i = 0; i < n; i++){
        s.insert(a[i]);
    }
    if(s.size() == 1){
        cout << -1 << endl;
        continue;
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == b1) {
            cout << "1 ";
        } else if (a[i] == b2) {
            cout << "2 ";
        } else {
            cout << "3 ";
        }
    }

    cout << endl;
    }

    return 0;
}
