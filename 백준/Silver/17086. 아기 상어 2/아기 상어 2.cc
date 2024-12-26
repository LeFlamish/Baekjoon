#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int, int> CD;
#define X first
#define Y second

int N, M;
int board[50][50];
int visited[50][50];
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void init() {
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> board[y][x];
		}
	}
}

int BFS(int x, int y) {
	queue<CD> Q;
	visited[y][x] = 1;
	Q.push(make_pair(x, y));
	while (!Q.empty()) {
		CD cur = Q.front(); Q.pop();
		if (board[cur.Y][cur.X] == 1) {
			return visited[cur.Y][cur.X] - 1;
		}
		for (int dir = 0; dir < 8; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = visited[cur.Y][cur.X] + 1;
			Q.push(make_pair(nx, ny));
		}
	}
}

void solve() {
	int Max = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (board[y][x] == 0) {
				Max = max(Max, BFS(x, y));
				memset(visited, 0, sizeof(visited));
			}
		}
	}
	cout << Max;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	solve();
	return 0;
}