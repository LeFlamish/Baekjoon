#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;
typedef pair<int, int> PI;
#define X first
#define Y second

int R, C, N, ret = INT_MAX;
int board[1000][1000];
int visited[1000][1000];
int dx[10], dy[10];

void check() {
	cout << "====================\n";
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			cout << visited[y][x] << ' ';
		}
		cout << '\n';
	}
	cout << "====================\n";
}

void init() {
	cin >> R >> C;
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			cin >> board[y][x];
		}
	}
	cin >> N;
	for (int n = 0; n < N; n++) {
		cin >> dy[n] >> dx[n];
	}
}

inline bool OOB(int x, int y) {
	return x < 0 || x >= C || y < 0 || y >= R;
}

void BFS() {
	queue<PI> Q;
	for (int x = 0; x < C; x++) {
		if (board[0][x]) {
			visited[0][x] = 1;
			Q.push({ x, 0 });
		}
	}
	while (!Q.empty()) {
		PI cur = Q.front(); Q.pop();
		if (cur.Y == R - 1) continue;
		for (int dir = 0; dir < N; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (OOB(nx, ny)) continue;
			if (visited[ny][nx] || board[ny][nx] == 0) continue;
			visited[ny][nx] = visited[cur.Y][cur.X] + 1;
			Q.push({ nx, ny });
		}
	}
}

void solve() {
	BFS();
	// check();
	bool flag = false;
	for (int x = 0; x < C; x++) {
		if (visited[R - 1][x]) {
			ret = min(ret, visited[R - 1][x] - 1);
			flag = true;
		}
	}
	if (flag) cout << ret;
	else cout << -1;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	solve();
	return 0;
}