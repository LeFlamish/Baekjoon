#include <bits/stdc++.h>
using namespace std;
string pattern, preffix, suffix;
int N;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    cin >> pattern;
    int pos = pattern.find("*");
    preffix = pattern.substr(0, pos);
    suffix = pattern.substr(pos + 1);
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        if (preffix.size() + suffix.size() > s.size()) {
            cout << "NE\n";
        }
        else {
            if (preffix == s.substr(0, preffix.size()) && suffix == s.substr(s.size() - suffix.size())) cout << "DA\n";
            else cout << "NE\n";
        }
    }
    return 0;
}