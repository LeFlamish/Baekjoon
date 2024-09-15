#include <bits/stdc++.h>
using namespace std;
string s;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    getline(cin, s);
    for (auto x : s) {
        if (x >= 'A' && x <= 'Z') cout << char((x + 13 - 'A') % 26 + 'A');
        else if (x >= 'a' && x <= 'z') cout << char((x + 13 - 'a') % 26 + 'a');
        else cout << x;
    }
    return 0;
}