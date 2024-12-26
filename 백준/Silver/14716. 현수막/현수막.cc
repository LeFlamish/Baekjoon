#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> CD;
#define X first
#define Y second

int M, N, ret;
int board[250][250];
bool visited[250][250];
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void init() {
	cin >> M >> N;
	for (int y = 0; y < M; y++) {
		for (int x = 0; x < N; x++) {
			cin >> board[y][x];
		}
	}
}

void BFS(int x, int y) {
	queue<CD> Q;
	visited[y][x] = true;
	Q.push(make_pair(x, y));
	while (!Q.empty()) {
		CD cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 8; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (visited[ny][nx] || board[ny][nx] == 0) continue;
			visited[ny][nx] = true;
			Q.push(make_pair(nx, ny));
		}
	}
	ret++;
}

void solve() {
	for (int y = 0; y < M; y++) {
		for (int x = 0; x < N; x++) {
			if (board[y][x] == 1 && !visited[y][x]) BFS(x, y);
		}
	}
	cout << ret;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	solve();
	return 0;
}