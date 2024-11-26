#include <iostream>
#include <queue>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;
typedef pair<int, int> CD;
#define X first
#define Y second

int N, ret = INT_MAX;
int board[100][100];
bool visited[100][100];
int times[100][100];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void init() {
	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> board[y][x];
		}
	}
}

void check() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (visited[y][x]) cout << "1 ";
			else cout << "0 ";
		}
		cout << '\n';
	}
}

int BFS(int x, int y) {
	visited[y][x] = true;
	queue<CD> Q;
	queue<CD> QQ;
	Q.push(make_pair(x, y));
	while (!Q.empty()) {
		CD cur = Q.front(); Q.pop();
		bool flag = false;
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (board[ny][nx] == 1 && !visited[ny][nx]) {
				visited[ny][nx] = true;
				Q.push(make_pair(nx, ny));
			}
			else {
				if (!flag) {
					QQ.push(cur);
					flag = true;
				}
			}
		}
	}
	memset(times, 0, sizeof(times));
	while (!QQ.empty()) {
		CD cur = QQ.front(); QQ.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (visited[ny][nx] || times[ny][nx]) continue;
			if (board[ny][nx] == 1) return times[cur.Y][cur.X];
			times[ny][nx] = times[cur.Y][cur.X] + 1;
			QQ.push(make_pair(nx, ny));
		}
	}
	return INT_MAX;
}

void solve() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (board[y][x] == 1 && !visited[y][x]) ret = min(BFS(x, y), ret);
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