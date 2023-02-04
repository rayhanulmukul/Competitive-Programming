#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string input;
    getline(cin, input);

    transform(input.begin(), input.end(), input.begin(), ::tolower);
    if (input.find("magic") != string::npos)
        cout << "Magic Exists!" << endl;
    else
        cout << "Magic Where :(" << endl;

    return 0;
}
