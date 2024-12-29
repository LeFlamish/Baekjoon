#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    for (int t = 0; t < n; ++t) {
        string s;
        int i, j;
        cin >> s >> i >> j;
        s.erase(i, j - i);
        cout << s << endl;
    }
    return 0;
}