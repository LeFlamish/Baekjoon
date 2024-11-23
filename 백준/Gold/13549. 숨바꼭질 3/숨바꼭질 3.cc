#include <iostream>
#include <queue>
using namespace std;

int N, K;
int visited[100001];
int dx[] = { 2, -1, 1 };

void init() {
	cin >> N >> K;
}

int BFS(int start) {
	visited[start] = 1;
	queue<int> Q;
	Q.push(start);
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		if (cur == K) return visited[cur] - 1;
		for (int dir = 0; dir < 3; dir++) {
			int next = cur;
			if (dir == 0) next *= 2;
			else next += dx[dir];
			if (next < 0 || next > 100000) continue;
			if (visited[next]) continue;
			
			if (dir == 0) visited[next] = visited[cur];
			else visited[next] = visited[cur] + 1;
			Q.push(next);
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	cout << BFS(N);
	return 0;
}