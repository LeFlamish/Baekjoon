#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> PI;
#define X first
#define Y second

int N, M, K, ret;
int board[101][101];
bool visited[101][101];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void check() {
	cout << "====================\n";
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			cout << board[y][x] << ' ';
		}
		cout << '\n';
	}
	cout << "====================\n";
}

void init() {
	cin >> N >> M >> K;
	for (int k = 0; k < K; k++) {
		int x, y;
		cin >> y >> x;
		board[y][x] = 1;
	}
}

inline bool OOB(int x, int y) {
	return x < 1 || x > M || y < 1 || y > N;
}

void BFS(int x, int y) {
	int cnt = 0;
	queue<PI> Q;
	visited[y][x] = true;
	Q.push({ x, y });
	while (!Q.empty()) {
		PI cur = Q.front(); Q.pop();
		cnt++;
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (OOB(nx, ny)) continue;
			if (visited[ny][nx] || board[ny][nx] == 0) continue;
			visited[ny][nx] = true;
			Q.push({ nx, ny });
		}
	}
	ret = max(cnt, ret);
}

void solve() {
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			if (!visited[y][x] && board[y][x]) BFS(x, y);
		}
	}
	cout << ret;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	solve();
	// check();
	return 0;
}