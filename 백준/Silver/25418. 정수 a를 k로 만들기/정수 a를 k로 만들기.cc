#include <iostream>
#include <queue>
using namespace std;

int A, K;
int num[1000001];
int visited[1000001];

void init() {
	cin >> A >> K;
}

int BFS(int S) {
	visited[S] = 1;
	queue<int> Q;
	Q.push(S);
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		if (cur == K) break;
		for (int dir = 0; dir < 2; dir++) {
			int nx = cur;
			if (dir == 1) nx *= 2;
			else nx += 1;
			if (nx < 1 || nx > K) continue;
			if (visited[nx]) continue;
			visited[nx] = visited[cur] + 1;
			Q.push(nx);
		}
	}
	return visited[K] - 1;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	cout << BFS(A);
	return 0;
}