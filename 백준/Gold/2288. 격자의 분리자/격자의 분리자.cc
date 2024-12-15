#include <iostream>
#include <string>
#include <queue>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;
typedef pair<int, int> CD;
#define X first
#define Y second

int N, M, ret;
string board[200];
int visited[200][200];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
queue<CD> Q;

bool init() {
	memset(visited, 0, sizeof(visited));
	cin >> N >> M;
	if (N + M == 0) return true;
	for (int y = 0; y < N; y++) {
		cin >> board[y];
	}
	for (int y = 0; y < N; y++) {
		for (int x = M - 1; x >= 0; x--) {
			if (board[y][x] == 'S') {
				if (x + 1 < M) {
					board[y][x + 1] = 'S';
				}
			}
		}
	}
	for (int x = 0; x < M; x++) {
		if (board[0][x] == 'S') {
			visited[0][x] = 1;
			Q.push(make_pair(x, 0));
		}
	}
	return false;
}

void BFS() {
	while (!Q.empty()) {
		CD cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
			if (visited[ny][nx] || board[ny][nx] != 'S') continue;
			visited[ny][nx] = visited[cur.Y][cur.X] + 1;
			Q.push(make_pair(nx, ny));
		}
	}
}

void solve() {
	while (1) {
		ret = INT_MAX;
		if (init()) break;
		BFS();
		for (int x = 0; x < M; x++) {
			if (visited[N - 1][x] != 0) ret = min(ret, visited[N - 1][x]);
		}
		cout << ret << '\n';
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	solve();
	return 0;
}