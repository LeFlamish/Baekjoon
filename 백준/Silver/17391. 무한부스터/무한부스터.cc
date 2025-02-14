#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> PI;
#define X first
#define Y second

int N, M;
int board[300][300];
int visited[300][300];
int dx[] = { 1, 0 };
int dy[] = { 0, 1 };

void init() {
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> board[y][x];
		}
	}
}

bool OOB(int x, int y) {
	return (x < 0 || x >= M || y < 0 || y >= N);
}

int BFS() {
	queue<PI> Q;
	visited[0][0] = 1;
	Q.push({ 0, 0 });
	while (!Q.empty()) {
		PI cur = Q.front(); Q.pop();
		int cnt = board[cur.Y][cur.X];
		if (cur.X == M - 1 && cur.Y == N - 1) return visited[cur.Y][cur.X];
		for (int dir = 0; dir < 2; dir++) {
			int nx = cur.X;
			int ny = cur.Y;
			for (int i = 0; i < cnt; i++) {
				nx += dx[dir];
				ny += dy[dir];
				if (OOB(nx, ny)) continue;
				if (visited[ny][nx]) continue;
				visited[ny][nx] = visited[cur.Y][cur.X] + 1;
				Q.push({ nx, ny });
			}
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	cout << BFS() - 1;
	return 0;
}