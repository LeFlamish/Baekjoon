#include <bits/stdc++.h>
using namespace std;
int A, B, C, M;
int tired, work;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> A >> B >> C >> M;
    for (int t = 0; t < 24; t++) {
        tired += A;
        if (tired <= M) {
            work += B;
        }
        else {
            tired -= A + C;
        }
        if (tired < 0) tired = 0;
    }
    cout << work;
    return 0;
}