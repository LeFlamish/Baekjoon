#include <bits/stdc++.h>
using namespace std;
string word, temp;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> word;
    temp = word;
    reverse(temp.begin(), temp.end());
    if (temp == word) cout << 1;
    else cout << 0;
    return 0;
}