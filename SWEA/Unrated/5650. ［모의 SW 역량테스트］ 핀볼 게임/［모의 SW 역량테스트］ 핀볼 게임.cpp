#include <bits/stdc++.h>
using namespace std;
#define SIZE 101

struct ball {
	int X;
	int Y;
	int Dir;
	int score;
};

int T, N;
int board[SIZE][SIZE];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
ball B = { -1, -1, -1 };
int startX, startY;
pair<int, int> wormhole[11][2];

void init() {
	for (int i = 6; i <= 10; i++) {
		for (int j = 0; j < 2; j++) {
			wormhole[i][j] = { -1, -1 };
		}
	}
	memset(board, 0, sizeof(board));
	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> board[y][x];
			int tmp = board[y][x];
			if (tmp >= 6 && tmp <= 10) {
				if (wormhole[tmp][0] == make_pair(-1, -1)) {
					wormhole[tmp][0] = { x, y };
				}
				else {
					wormhole[tmp][1] = { x, y };
				}
			}
		}
	}
}

bool isWall(int nx, int ny) {
	int tmp = board[ny][nx];
	if (nx < 0 || nx >= N || ny < 0 || ny >= N) return true;
	else if (tmp == 1) {
		if (B.Dir == 0 || B.Dir == 1) return true;
	}
	else if (tmp == 2) {
		if (B.Dir == 1 || B.Dir == 2) return true;
	}
	else if (tmp == 3) {
		if (B.Dir == 2 || B.Dir == 3) return true;
	}
	else if (tmp == 4) {
		if (B.Dir == 3 || B.Dir == 0) return true;
	}
	else if (tmp == 5) return true;
	return false;
}

bool isEnd(int nx, int ny) {
	return board[ny][nx] == -1;
}

bool isBlock(int nx, int ny) {
	int tmp = board[ny][nx];
	if (tmp == 1) {
		if (B.Dir == 2) { // 아래쪽으로 갈 때
			B.Dir = 1;
		}
		else if (B.Dir == 3) { // 왼쪽으로 갈 때
			B.Dir = 0;
		}
		return true;
	}
	else if (tmp == 2) {
		if (B.Dir == 0) { // 위쪽으로 갈 때
			B.Dir = 1;
		}
		else if (B.Dir == 3){ // 왼쪽으로 갈 때
			B.Dir = 2;
		}
		return true;
	}
	else if (tmp == 3) {
		if (B.Dir == 0) { // 위쪽으로 갈 때
			B.Dir = 3;
		}
		else if (B.Dir == 1) { // 오른쪽으로 갈 때
			B.Dir = 2;
		}
		return true;
	}
	else if (tmp == 4) {
		if (B.Dir == 1) { // 오른쪽으로 갈 때
			B.Dir = 0;
		}
		else if (B.Dir == 2) { // 아래쪽으로 갈 때
			B.Dir = 3;
		}
		return true;
	}
	return false;
}

bool isWormHole(int nx, int ny) {
	int tmp = board[ny][nx];
	if (tmp >= 6 && tmp <= 10) {
		if (wormhole[tmp][0] == make_pair(nx, ny)) {
			B.X = wormhole[tmp][1].first;
			B.Y = wormhole[tmp][1].second;
		}
		else {
			B.X = wormhole[tmp][0].first;
			B.Y = wormhole[tmp][0].second;
		}
		
		return true;
	}
	return false;
}

void move() {
	while (1) {
		int curDir = B.Dir;
		int nx = B.X + dx[curDir];
		int ny = B.Y + dy[curDir];
		if (isWall(nx, ny)) {
			B.score = B.score * 2 + 1;
			break;
		}
		else if (isBlock(nx, ny)) B.score++;
		else if (isWormHole(nx, ny)) continue;
		else if (isEnd(nx, ny)) break;
		B.X = nx;
		B.Y = ny;
	}
}

int solve() {
	int Max = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (!board[y][x]) {
				board[y][x] = -1;
				startX = x;
				startY = y;
				for (int dir = 0; dir < 4; dir++) {
					B = { x, y, dir, 0 };
					move();
					Max = max(Max, B.score);
				}
				board[y][x] = 0;
			}
		}
	}
	return Max;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		init();
		cout << '#' << t << ' ' << solve() << '\n';
	}
	return 0;
}