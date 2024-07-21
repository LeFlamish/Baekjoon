#include <bits/stdc++.h>
using namespace std;
typedef pair<string, int> P;
#define name first
#define value second
vector<P> computer;
int N;

bool compare(const P& x, const P& y) {
    if (x.value == y.value) {
        return x.name < y.name;
    }
    return x.value > y.value;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        int R, S, D;
        cin >> s >> R >> S >> D;
        computer.push_back({ s, 2 * R + 3 * S + D });
    }
    if (N == 0) return 0;
    else if (N == 1) {
        cout << computer[0].name;
        return 0;
    }
    sort(computer.begin(), computer.end(), compare);
    for (int i = 0; i < 2; i++) cout << computer[i].name << '\n';
    return 0;
}