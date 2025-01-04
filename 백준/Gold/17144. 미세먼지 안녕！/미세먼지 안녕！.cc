#include <iostream>
#include <cstring>
using namespace std;
struct Purifier {
	int x, y;
};

int R, C, T;
int board[50][50];
int tmp[50][50];
int spread[50][50];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
Purifier P;

void init() {
	cin >> R >> C >> T;
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			cin >> board[y][x];
		}
	}
	for (int y = 0; y < R; y++) {
		if (board[y][0] == -1) {
			P.x = 0; P.y = y;
			break;
		}
	}
}

void check() {
	cout << "====================\n";
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			cout << board[y][x] << ' ';
		}
		cout << '\n';
	}
	cout << "====================\n";
}

bool area(int x, int y) {
	return (x < 0 || x >= C || y < 0 || y >= R);
}

void diffusion() {
	memset(spread, 0, sizeof(spread));
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if (board[y][x] > 4) {
				int cnt = 0;
				for (int dir = 0; dir < 4; dir++) {
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if (area(nx, ny)) continue;
					if (board[ny][nx] == -1) continue;
					cnt++;
					spread[ny][nx] += board[y][x] / 5;
				}
				board[y][x] -= (board[y][x] / 5) * cnt;
			}
		}
	}
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			board[y][x] += spread[y][x];
		}
	}
}

void copyBoard() {
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			tmp[y][x] = board[y][x];
		}
	}
}

void setBoard() {
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			board[y][x] = tmp[y][x];
		}
	}
}

void circulation() {
	copyBoard();
	// 공기청정기의 위쪽
	for (int x = 1; x < C; x++) { // →
		tmp[P.y][x] = board[P.y][x - 1];
	}
	tmp[P.y][1] = 0;
	for (int y = P.y - 1; y >= 0; y--) { // ↑
		tmp[y][C - 1] = board[y + 1][C - 1];
	}
	for (int x = C - 2; x >= 0; x--) { // ←
		tmp[0][x] = board[0][x + 1];
	}
	for (int y = 1; y < P.y; y++) { // ↓
		tmp[y][0] = board[y - 1][0];
	}
	// 공기청정기의 아래쪽
	for (int x = 1; x < C; x++) { // →
		tmp[P.y + 1][x] = board[P.y + 1][x - 1];
	}
	tmp[P.y + 1][1] = 0;
	for (int y = P.y + 2; y < R; y++) { // ↓
		tmp[y][C - 1] = board[y - 1][C - 1];
	}
	for (int x = C - 2; x >= 0; x--) { // ←
		tmp[R - 1][x] = board[R - 1][x + 1];
	}
	for (int y = R - 2; y > P.y + 1; y--) { // ↑
		tmp[y][0] = board[y + 1][0];
	}
	setBoard();
}

int result() {
	int ret = 0;
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if (board[y][x] == -1) continue;
			ret += board[y][x];
		}
	}
	return ret;
}

void solve() {
	for (int t = 0; t < T; t++) {
		diffusion();
		circulation();
	}
	// check();
	cout << result();
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	solve();
	return 0;
}