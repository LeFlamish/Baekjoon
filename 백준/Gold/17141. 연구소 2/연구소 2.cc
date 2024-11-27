#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;
typedef pair<int, int> CD;
#define X first
#define Y second

bool flag;
int N, M, ans = INT_MAX;
int board[50][50];
int visited[50][50];
vector<CD> V;
CD virus[10];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void init() {
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> board[y][x];
			if (board[y][x] == 2) {
				V.push_back(make_pair(x, y));
				board[y][x] = 0;
			}
		}
	}
}

void setVirus() {
	for (int i = 0; i < M; i++) {
		board[virus[i].Y][virus[i].X] = 2;
	}
}

void resetBoard() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (board[y][x] == 2) board[y][x] = 0;
		}
	}
}

bool checkAll() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (board[y][x] == 0) return false;
		}
	}
	return true;
}

int BFS() {
	int ret = 0;
	memset(visited, 0, sizeof(visited));
	queue<CD> Q;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (board[y][x] == 2) {
				visited[y][x] = 1;
				Q.push(make_pair(x, y));
			}
		}
	}

	while (!Q.empty()) {
		CD cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (visited[ny][nx] || board[ny][nx] == 1) continue;
			board[ny][nx] = 2;
			visited[ny][nx] = visited[cur.Y][cur.X] + 1;
			ret = max(ret, visited[ny][nx] - 1);
			Q.push(make_pair(nx, ny));
		}
	}
	return ret;
}

void select(int cnt, int k) {
	if (cnt == M) {
		setVirus();
		int tmp = BFS();
		if (checkAll()) {
			flag = true;
			ans = min(ans, tmp);
		}
		resetBoard();
	}

	int size = V.size();
	for (int i = k; i < size; i++) {
		virus[cnt] = V[i];
		select(cnt + 1, i + 1);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	select(0, 0);
	if (flag) cout << ans;
	else cout << -1;
	return 0;
}