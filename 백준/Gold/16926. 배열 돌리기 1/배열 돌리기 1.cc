#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M, R, T;
int board[300][300];
int tmp[300][300];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void check() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cout << board[y][x] << ' ';
		}
		cout << '\n';
	}
	/*
	cout << "====================\n";
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cout << tmp[y][x] << ' ';
		}
		cout << '\n';
	}
	cout << "====================\n";
	*/
}

void init() {
	cin >> N >> M >> R;
	T = min(N, M) / 2;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> board[y][x];
		}
	}
}

void setBoard() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			board[y][x] = tmp[y][x];
		}
	}
}

bool area(int x, int y) {
	return (x < 0 || x >= M || y < 0 || y >= N);
}

void rotate() {
	memset(tmp, 0, sizeof(tmp));
	for (int i = 0; i < T; i++) {
		int cx = i, cy = i, dir = 1;
		while (1) {
			int nx = cx + dx[dir];
			int ny = cy + dy[dir];
			if (area(nx, ny) || tmp[ny][nx]) {
				dir = (dir + 3) % 4;
				nx = cx + dx[dir];
				ny = cy + dy[dir];
			}
			tmp[ny][nx] = board[cy][cx];
			//check();
			cx = nx; cy = ny;
			if (nx == i && ny == i) break;
		}
	}
	setBoard();
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	for (int r = 0; r < R; r++) {
		rotate();
	}
	check();
	return 0;
}