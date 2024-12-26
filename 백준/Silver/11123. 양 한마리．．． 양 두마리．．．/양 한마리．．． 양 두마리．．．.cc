#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
typedef pair<int, int> CD;
#define X first
#define Y second

int T, H, W, ret;
string board[100];
bool visited[100][100];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void init() {
	ret = 0;
	for (int y = 0; y < H; y++) board[y].clear();
	memset(visited, false, sizeof(visited));
	cin >> H >> W;
	for (int y = 0; y < H; y++) cin >> board[y];
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
			if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
			if (visited[ny][nx] || board[ny][nx] != '#') continue;
			visited[ny][nx] = true;
			Q.push(make_pair(nx, ny));
		}
	}
	ret++;
}

void solve() {
	init();
	for (int y = 0; y < H; y++) {
			for (int x = 0; x < W; x++) {
			if (board[y][x] == '#' && !visited[y][x]) BFS(x, y);
		}
	}
	cout << ret << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	for (int t = 0; t < T; t++) {
		solve();
	}
	return 0;
}