#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct CCTV {
	int x, y, type, dir;
};

int N, M, K, ret = INT_MAX;
int board[8][8];
int visited[8][8];
CCTV cctv[8];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void check() {
	cout << "====================\n";
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cout << visited[y][x] << ' ';
		}
		cout << '\n';
	}
	cout << "====================\n";
}

void init() {
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> board[y][x];
			if (board[y][x] >= 1 && board[y][x] <= 5) {
				cctv[K] = { x, y, board[y][x], 0 };
				K++;
			}
		}
	}
}

void copyBoard() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			visited[y][x] = board[y][x];
		}
	}
}

bool area(int x, int y) {
	return (x < 0 || x >= M || y < 0 || y >= N);
}

void process(int x, int y, int dir) {
	while (1) {
		x += dx[dir];
		y += dy[dir];
		if (area(x, y)) break;
		if (visited[y][x] == 6) break;
		visited[y][x] = 7;
	}
}

int right(int dir) {
	return (dir + 1) % 4;
}

int left(int dir) {
	return (dir + 3) % 4;
}

int back(int dir) {
	return (dir + 2) % 4;
}

void solve() {
	copyBoard();
	for (int k = 0; k < K; k++) {
		if (cctv[k].type == 1) {
			process(cctv[k].x, cctv[k].y, cctv[k].dir);
		}
		else if (cctv[k].type == 2) {
			process(cctv[k].x, cctv[k].y, cctv[k].dir);
			process(cctv[k].x, cctv[k].y, back(cctv[k].dir));
		}
		else if (cctv[k].type == 3) {
			process(cctv[k].x, cctv[k].y, cctv[k].dir);
			process(cctv[k].x, cctv[k].y, right(cctv[k].dir));
		}
		else if (cctv[k].type == 4) {
			process(cctv[k].x, cctv[k].y, cctv[k].dir);
			process(cctv[k].x, cctv[k].y, right(cctv[k].dir));
			process(cctv[k].x, cctv[k].y, left(cctv[k].dir));
		}
		else {
			process(cctv[k].x, cctv[k].y, cctv[k].dir);
			process(cctv[k].x, cctv[k].y, right(cctv[k].dir));
			process(cctv[k].x, cctv[k].y, left(cctv[k].dir));
			process(cctv[k].x, cctv[k].y, back(cctv[k].dir));
		}
	}
}

void answer() {
	int ans = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (!visited[y][x]) ans++;
		}
	}
	ret = min(ret, ans);
}

void select(int cnt) {
	if (cnt == K) {
		solve();
		answer();
		// check();
		return;
	}

	for (int dir = 0; dir < 4; dir++) {
		cctv[cnt].dir = dir;
		select(cnt + 1);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	select(0);
	cout << ret;
	return 0;
}