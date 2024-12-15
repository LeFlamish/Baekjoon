#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> CD;
#define X first
#define Y second

int N, M, ret;
int board[100][70];
bool visited[100][70];
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

void BFS(int x, int y) {
	bool isPeak = true;
	queue<CD> Q;
	visited[y][x] = true;
	Q.push(make_pair(x, y));
	while (!Q.empty()) {
		CD cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 8; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
			if (board[ny][nx] > board[cur.Y][cur.X]) {
				isPeak = false;
				continue;
			}
			if (visited[ny][nx]) continue;
			if (board[ny][nx] == board[cur.Y][cur.X]) {
				visited[ny][nx] = true;
				Q.push(make_pair(nx, ny));
			}
		}
	}
	if (isPeak) ret++;
}

void solve() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (!visited[y][x]) BFS(x, y);
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