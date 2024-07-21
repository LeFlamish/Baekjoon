#include <bits/stdc++.h>
using namespace std;
string s;
int step = 2;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    while (1) {
        getline(cin, s);
        if (s == "Was it a cat I saw?") break;
        for (int i = 0; i < s.size(); i += step) {
            cout << s[i];
        }
        cout << '\n';
        step++;
    }
    return 0;
}