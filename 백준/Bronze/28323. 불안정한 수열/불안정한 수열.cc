#include <bits/stdc++.h>
using namespace std;
int N;
stack<int> S;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        if (S.empty()) S.push(tmp);
        else {
            if ((S.top() & 1) && !(tmp & 1)) S.push(tmp);
            else if (!(S.top() & 1) && (tmp & 1)) S.push(tmp);
        }
    }
    cout << S.size();
    return 0;
}