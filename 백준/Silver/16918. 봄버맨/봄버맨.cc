#include <iostream>
#include <algorithm>
using namespace std;

int R, C, N;
string board[200]; // 실제 보드
int plant[200][200]; // 폭탄을 심은 시점 저장
bool isexplode[200][200]; // 이번 턴에 터지는 폭탄들
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void init() {
	for (int y = 0; y < R; y++) {
		fill(plant[y], plant[y] + C, -1);
	}
	cin >> R >> C >> N;
	for (int y = 0; y < R; y++) { // 보드 입력
		cin >> board[y];
	}
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if (board[y][x] == 'O') plant[y][x] = 0; // 폭탄이 있으면 심은 시점은 0이므로 0 저장.
		}
	}
}

void printBoard() {
	for (int y = 0; y < R; y++) {
		cout << board[y] << '\n';
	}
}

bool area(int x, int y) {
	return (x < 0 || x >= C || y < 0 || y >= R);
}

void install(int T) {
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if (board[y][x] == '.') {
				board[y][x] = 'O';
				plant[y][x] = T;
			}
		}
	}
}

void explosion(int turn) {
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if (board[y][x] == 'O' && turn - plant[y][x] == 3) { // 현재 위치에 폭탄이 있고, 3초가 지났다면
				plant[y][x] = -1;
				board[y][x] = '.';
				isexplode[y][x] = true; // isexplode 배열을 추가해서 폭발할 걸 따로 저장하는 이유? 반례 생각해보기.
			}
		}
	}
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if (isexplode[y][x]) {
				isexplode[y][x] = false;
				for (int dir = 0; dir < 4; dir++) {
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if (area(nx, ny)) continue;
					board[ny][nx] = '.';
					plant[ny][nx] = -1;
				}
			}
		}
	}
}

void solve(int T) {
	for (int t = 2; t <= T; t++) {
		install(t);
		explosion(t);
	}
	printBoard();
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	solve(N);
	return 0;
}