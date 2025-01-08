#include <iostream>
#include <cmath>
using namespace std;

int T, N, D;
int board[500][500];
int tmp[500][500];

void printBoard() {
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cout << board[y][x] << ' ';
		}
		cout << '\n';
	}
}

void init() {
	cin >> N >> D;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> board[y][x];
		}
	}
}

void copyBoard() {
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			tmp[y][x] = board[y][x];
		}
	}
}

void setBoard() {
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			board[y][x] = tmp[y][x];
		}
	}
}

void rightRotate() {
	copyBoard();
	for (int i = 1; i <= N; i++) {
		tmp[i][(N + 1) / 2] = board[i][i];
	}
	for (int i = 1; i <= N; i++) {
		tmp[i][N + 1 - i] = board[i][(N + 1) / 2];
	}
	for (int i = 1; i <= N; i++) {
		tmp[(N + 1) / 2][i] = board[N + 1 - i][i];
	}
	for (int i = 1; i <= N; i++) {
		tmp[i][i] = board[(N + 1) / 2][i];
	}
	setBoard();
}

void leftRotate() {
	copyBoard();
	for (int i = 1; i <= N; i++) {
		tmp[i][(N + 1) / 2] = board[i][N + 1 - i];
	}
	for (int i = 1; i <= N; i++) {
		tmp[i][N + 1 - i] = board[(N + 1) / 2][N + 1 - i];
	}
	for (int i = 1; i <= N; i++) {
		tmp[(N + 1) / 2][i] = board[i][i];
	}
	for (int i = 1; i <= N; i++) {
		tmp[i][i] = board[i][(N + 1) / 2];
	}
	setBoard();
}

void solve() {
	if (D < 0) {
		for (int i = 0; i < abs(D) / 45; i++) leftRotate();
	}
	else for (int i = 0; i < D / 45; i++) rightRotate();
	printBoard();
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	for (int t = 0; t < T; t++) {
		init();
		solve();
	}
	return 0;
}