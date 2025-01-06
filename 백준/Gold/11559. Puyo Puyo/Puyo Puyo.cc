#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> CD;
#define X first
#define Y second

int ret;
string board[12];
bool visited[12][6];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void init() {
	for (int i = 0; i < 12; i++) cin >> board[i];
}

bool area(int x, int y) {
	return (x < 0 || x >= 6 || y < 0 || y >= 12);
}

void clearPuyo() {
	for (int y = 0; y < 12; y++) {
		for (int x = 0; x < 6; x++) {
			if (visited[y][x]) board[y][x] = '.';
		}
	}
}

bool BFS(int x, int y) {
	memset(visited, false, sizeof(visited));
	int cnt = 0;
	queue<CD> Q;
	visited[y][x] = true;
	Q.push({ x, y });
	while (!Q.empty()) {
		CD cur = Q.front(); Q.pop();
		cnt++;
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (area(nx, ny)) continue;
			if (visited[ny][nx] || board[ny][nx] != board[cur.Y][cur.X]) continue;
			visited[ny][nx] = true;
			Q.push({ nx, ny });
		}
	}

	if (cnt >= 4) {
		clearPuyo();
		return true;
	}
	else return false;
}

void moveDown(int x, int y) {
	int nx = x, ny = y;
	while (1) {
		ny++;
		if (area(nx, ny) || board[ny][nx] != '.') {
			ny--;
			break;
		}
	}
	char tmp = board[y][x];
	board[y][x] = '.';
	board[ny][nx] = tmp;
}

void setBoard() {
	for (int y = 11; y >= 0; y--) {
		for (int x = 0; x < 6; x++) {
			if (board[y][x] != '.') moveDown(x, y);
		}
	}
}

void check() {
	cout << "====================\n";
	for (int y = 0; y < 12; y++) {
		for (int x = 0; x < 6; x++) {
			cout << board[y][x];
		}
		cout << '\n';
	}
	cout << "====================\n";
}

void solve() {
	bool flag = true;
	while (1) {
		flag = false;
		for (int y = 0; y < 12; y++) {
			for (int x = 0; x < 6; x++) {
				if (board[y][x] != '.') {
					if (BFS(x, y)) flag = true;
				}
			}
		}
		if (flag) {
			ret++;
			//check();
			setBoard();
			//check();
		}
		else break;
	}
	cout << ret;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	solve();
	return 0;
}