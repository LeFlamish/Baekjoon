#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
int answer[4];

int Tri(int n) {
    return n * (n + 1) / 2;
}

bool Select(int cnt, int k, int x) {
    if (cnt == 3) {
        int sum = 0;
        for (int i = 0; i < 3; i++) {
            sum += Tri(answer[i]);
        }
        return sum == x;
    }

    for (int i = k; Tri(i) <= x; i++) {
        answer[cnt] = i;
        if (Select(cnt + 1, i, x))
            return true;
    }
    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int x;
        cin >> x;

        int n = (int)sqrt(2 * x);
        if (Select(0, 1, x))
            cout << "1\n";
        else
            cout << "0\n";
    }

    return 0;
}
