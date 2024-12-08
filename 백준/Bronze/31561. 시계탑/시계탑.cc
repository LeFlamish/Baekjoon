#include <iostream>
using namespace std;
float M, answer;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> M;
    cout << fixed;
    cout.precision(1);
    if (M > 30) {
        answer = 15 + (M - 30) * 3 / 2;
    }
    else {
        answer = M / 2;
    }
    cout << answer;
    return 0;
}