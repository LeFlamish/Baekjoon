#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
typedef pair<int, int> CD;
#define X first
#define Y second

int R, C;
string board[50];
int MaxD;
int visited[50][50];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void init() {
	cin >> R >> C;
	for (int y = 0; y < R; y++) {
		cin >> board[y];
	}
}

void BFS(int x, int y) {
	memset(visited, 0, sizeof(visited));
	visited[y][x] = 1;
	queue<CD> Q;
	Q.push(make_pair(x, y));
	while (!Q.empty()) {
		CD cur = Q.front(); Q.pop();
		MaxD = max(MaxD, visited[cur.Y][cur.X] - 1);
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= C || ny < 0 || ny >= R) continue;
			if (visited[ny][nx] || board[ny][nx] == 'W') continue;
			visited[ny][nx] = visited[cur.Y][cur.X] + 1;
			Q.push(make_pair(nx, ny));
		}
	}
}

void solve() {
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if (board[y][x] == 'L') {
				BFS(x, y);
			}
		}
	}
	cout << MaxD;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	solve();
	return 0;
}