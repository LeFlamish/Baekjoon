#include <bits/stdc++.h>
using namespace std;
#define SIZE 1000

int N, target;
int board[SIZE][SIZE];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
int curX, curY, curDir;
int retX, retY;

void check() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cout << board[y][x] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> target;
	board[N / 2][N / 2] = 1;
	board[N / 2 - 1][N / 2] = 2;
	if (target == 1) {
		retX = N / 2; retY = N / 2;
	}
	else if (target == 2) {
		retX = N / 2; retY = N / 2 - 1;
	}
	curX = N / 2; curY = N / 2 - 1; curDir = 1;
	for (int i = 3; i <= N * N; i++) {
		int nx, ny;
		int right = (curDir + 1) % 4;
		if (board[curY + dy[right]][curX + dx[right]]) {
			nx = curX + dx[curDir];
			ny = curY + dy[curDir];
			board[ny][nx] = i;
		}
		else {
			nx = curX + dx[right];
			ny = curY + dy[right];
			board[ny][nx] = i;
			curDir = right;
		}
		curX = nx; curY = ny;
		if (board[curY][curX] == target) {
			retX = curX; retY = curY;
		}
	}
	check();
	cout << retY + 1 << ' ' << retX + 1;
	return 0;
}