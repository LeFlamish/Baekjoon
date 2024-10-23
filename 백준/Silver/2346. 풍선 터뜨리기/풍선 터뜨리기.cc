#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
deque<P> DQ;
vector<int> V;
int N;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int tmp;
        cin >> tmp;
        DQ.push_back({ tmp, i });
    }
    while (!DQ.empty()) {
        int diff = DQ.front().first;
        V.push_back(DQ.front().second);
        DQ.pop_front();
        if (DQ.empty()) break;
        if (diff > 0) {
            for (int i = 0; i < diff - 1; i++) {
                DQ.push_back(DQ.front()); DQ.pop_front();
            }
        }
        else {
            for (int i = 0; i > diff; i--) {
                DQ.push_front(DQ.back()); DQ.pop_back();
            }
        }
    }
    for (int i : V) cout << i << ' ';
    return 0;
}