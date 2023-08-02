#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string findShortestContainingString(const string& a, const string& b, const string& c) {
    string combined = a + b + c;
    int n = combined.length();

    int startPosA = combined.find(a);
    int startPosB = combined.find(b);
    int startPosC = combined.find(c);

    int endPosA = startPosA + a.length() - 1;
    int endPosB = startPosB + b.length() - 1;
    int endPosC = startPosC + c.length() - 1;

    int shortestLen = min({endPosA, endPosB, endPosC}) - max({startPosA, startPosB, startPosC}) + 1;

    return combined.substr(max({startPosA, startPosB, startPosC}), shortestLen);
}

int main() {
    string a, b, c;
    cout << "Enter string a: ";
    cin >> a;
    cout << "Enter string b: ";
    cin >> b;
    cout << "Enter string c: ";
    cin >> c;

    string result = findShortestContainingString(a, b, c);
    cout << "The lexicographically smallest string containing all three substrings is: " << result << endl;

    return 0;
}
