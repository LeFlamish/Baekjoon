#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
typedef pair<int, int> PI;
#define X first
#define Y second

int M, ret, cnt = 100;
string board[2];
int visited[2][50];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void init() {
	cin >> M;
	for (int y = 0; y < 2; y++) {
		cin >> board[y];
		for (int x = 0; x < M; x++) {
			if (board[y][x] == '.') ret++;
		}
	}
}

inline bool OOB(int x, int y) {
	return x < 0 || x >= M || y < 0 || y >= 2;
}

int BFS(int x, int y) {
	queue<PI> Q;
	visited[y][x] = 1;
	Q.push({ x, y });
	while (!Q.empty()) {
		PI cur = Q.front(); Q.pop();
		if (cur.X == M - 1) return visited[cur.Y][cur.X];
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (OOB(nx, ny)) continue;
			if (visited[ny][nx] || board[ny][nx] == '#') continue;
			visited[ny][nx] = visited[cur.Y][cur.X] + 1;
			Q.push({ nx, ny });
		}
	}
}

void solve() {
	for (int y = 0; y < 2; y++) {
		if (board[y][0] == '.') {
			memset(visited, 0, sizeof(visited));
			cnt = min(cnt, BFS(0, y));
		}
	}
	cout << ret - cnt;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	solve();
	return 0;
}