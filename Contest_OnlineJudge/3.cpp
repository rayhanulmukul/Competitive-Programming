#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i = 3;
    string s = "Bangladesh";
    int size = s.size();
    string s1 = s.substr(0, i);        // 0 = index_start , i = length
    string s2 = s.substr(i, size - i); // i = index_start , x-i = length
    cout << "S1 : " << s1 << " "
         << "s2 : " << s2 << endl;
    return 0;
}