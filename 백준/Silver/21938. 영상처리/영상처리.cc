#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> CD;
#define X first
#define Y second

int N, M, T, ret;
int board[1000][1000];
bool visited[1000][1000];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void init() {
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			int a, b, c;
			cin >> a >> b >> c;
			board[y][x] = (a + b + c) / 3;
		}
	}
	cin >> T;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (board[y][x] < T) board[y][x] = 0;
			else board[y][x] = 255;
		}
	}
}

void BFS(int x, int y) {
	queue<CD> Q;
	visited[y][x] = true;
	Q.push(make_pair(x, y));
	while (!Q.empty()) {
		CD cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
			if (visited[ny][nx] || board[ny][nx] == 0) continue;
			visited[ny][nx] = true;
			Q.push(make_pair(nx, ny));
		}
	}
	ret++;
}

void solve() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (board[y][x] == 255 && !visited[y][x]) BFS(x, y);
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