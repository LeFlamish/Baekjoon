#include <iostream>
#include <queue>
using namespace std;

int F, S, G, U, D;
int visited[1000001];
int dx[2];

void init() {
	cin >> F >> S >> G >> U >> D;
	dx[0] = U;
	dx[1] = -D;
}

bool BFS(int s) {
	visited[s] = 1;
	queue<int> Q;
	Q.push(s);
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		if (cur == G) return true;
		for (int dir = 0; dir < 2; dir++) {
			int nx = cur + dx[dir];
			if (nx < 1 || nx > F) continue;
			if (visited[nx]) continue;
			visited[nx] = visited[cur] + 1;
			Q.push(nx);
		}
	}
	return false;
}

void solve() {
	if (BFS(S)) cout << visited[G] - 1;
	else cout << "use the stairs";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	solve();
	return 0;
}