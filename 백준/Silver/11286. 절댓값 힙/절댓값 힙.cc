#include <bits/stdc++.h>
using namespace std;
int N, tmp;
struct cmp {
    bool operator()(int a, int b) {
        if (abs(a) == abs(b)) return a > b;
        return abs(a) > abs(b);
    }
};
int main() {
    cin.tie(0)->sync_with_stdio(0);
    priority_queue<int, vector<int>, cmp> PQ;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        if (tmp == 0) {
            if (PQ.empty()) cout << 0 << '\n';
            else {
                cout << PQ.top() << '\n';
                PQ.pop();
            }
        }
        else {
            PQ.push(tmp);
        }
    }
    return 0;
}