#include <bits/stdc++.h>
using namespace std;
#define SIZE 51
typedef pair<int, int> CD;
#define X first
#define Y second

int N, L, R;
int board[SIZE][SIZE];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
bool visited[SIZE][SIZE];
bool finishMove[SIZE][SIZE];
bool checking[SIZE][SIZE];
int isMove[SIZE][SIZE];

void init() {
	cin >> N >> L >> R;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> board[y][x];
		}
	}
}

void check() {
	cout << "====================\n";
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cout << board[y][x] << ' ';
		}
		cout << '\n';
	}
	cout << "====================\n";
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cout << isMove[y][x] << ' ';
		}
		cout << '\n';
	}
	cout << "====================\n";
}

bool moveCheck() {
	int group = 1;
	bool flag = false;
	memset(isMove, false, sizeof(isMove));
	memset(visited, false, sizeof(visited));
	memset(finishMove, false, sizeof(finishMove));
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			bool tmp = false;
			memset(checking, false, sizeof(checking));
			queue<CD> Q;
			checking[y][x] = true;
			Q.push({ x, y });
			while (!Q.empty()) {
				CD cur = Q.front(); Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
					int gap = abs(board[cur.Y][cur.X] - board[ny][nx]);
					if (checking[ny][nx] || isMove[ny][nx]) continue;
					if (gap >= L && gap <= R) {
						tmp = true;
						flag = true;
						isMove[y][x] = group;
						isMove[ny][nx] = group;
						checking[ny][nx] = true;
						Q.push({ nx, ny });
					}
				}
			}
			if (tmp) group++;
		}
	}
	return flag;
}

int BFS(int x, int y) {
	int ret = 0, cnt = 1, group;
	queue<CD> Q;
	visited[y][x] = true;
	ret += board[y][x];
	group = isMove[y][x];
	Q.push({ x, y });
	while (!Q.empty()) {
		CD cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (visited[ny][nx] || isMove[ny][nx] != group) continue;
			visited[ny][nx] = true;
			ret += board[ny][nx];
			cnt++;
			Q.push({ nx, ny });
		}
	}
	return ret / cnt;
}

void afterMove(int x, int y, int value) {
	queue<CD> Q;
	int group = isMove[y][x];
	finishMove[y][x] = true;
	board[y][x] = value;
	Q.push({ x, y });
	while (!Q.empty()) {
		CD cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (finishMove[ny][nx] || isMove[ny][nx] != group) continue;
			board[ny][nx] = value;
			finishMove[ny][nx] = true;
			Q.push({ nx, ny });
		}
	}
}

int solve() {
	int ret = 0;
	while (moveCheck()) {
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				if (isMove[y][x] && !visited[y][x]) {
					afterMove(x, y, BFS(x, y));
					//check();
				}
			}
		}
		ret++;
	}
	return ret;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	cout << solve();
	return 0;
}