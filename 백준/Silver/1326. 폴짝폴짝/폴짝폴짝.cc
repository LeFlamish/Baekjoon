#include <iostream>
#include <queue>
using namespace std;

int N, A, B;
int bridge[10001];
int visited[10001];

void init() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> bridge[i];
    }
    cin >> A >> B;
}

bool solve(int S) {
    queue<int> Q;
    visited[S] = 1;
    Q.push(S);
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        if (cur == B) return true;
        for (int next = cur + bridge[cur]; next <= N; next += bridge[cur]) {
            if (visited[next]) continue;
            visited[next] = visited[cur] + 1;
            Q.push(next);
        }
        for (int next = cur - bridge[cur]; next >= 1; next -= bridge[cur]) {
            if (visited[next]) continue;
            visited[next] = visited[cur] + 1;
            Q.push(next);
        }
    }
    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    init();
    if (solve(A)) cout << visited[B] - 1;
    else cout << -1;
    return 0;
}