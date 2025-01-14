#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Arduino {
	int x, y;
	bool alive;
};

int R, C, T;
string order;
string board[100];
int cnt[100][100];
int dx[] = { 0, -1, 0, 1, -1, 0, 1, -1, 0, 1 };
int dy[] = { 0, 1, 1, 1, 0, 0, 0, -1, -1, -1 };
Arduino jongsoo;
vector<Arduino> bomb;

void check() {
	// cout << "====================\n";
	for (int y = 0; y < R; y++) {
		cout << board[y] << '\n';
	}
	// cout << "====================\n";
	/*
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			cout << cnt[y][x] << ' ';
		}
		cout << '\n';
	}
	cout << "====================\n";
	*/
}

void init() {
	cin >> R >> C;
	for (int y = 0; y < R; y++) {
		cin >> board[y];
	}
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if (board[y][x] == 'I') jongsoo = { x, y, true };
			else if (board[y][x] == 'R') {
				bomb.push_back({ x, y, true });
				cnt[y][x]++;
			}
		}
	}
	cin >> order;
	T = order.size();
}

void moveJongsoo(int t) {
	int nx = jongsoo.x + dx[order[t] - '0'];
	int ny = jongsoo.y + dy[order[t] - '0'];
	if (board[ny][nx] == 'R') jongsoo.alive = false;
	else {
		board[jongsoo.y][jongsoo.x] = '.';
		board[ny][nx] = 'I';
		jongsoo = { nx, ny, true };
	}
}

int distance(int x, int y) {
	return abs(jongsoo.x - x) + abs(jongsoo.y - y);
}

void moveCrazy() {
	for (int i = 0; i < bomb.size(); i++) {
		if (!bomb[i].alive) continue;
		Arduino cur = bomb[i];
		int Nx = cur.x, Ny = cur.y;
		int dist = distance(Nx, Ny);
		for (int dir = 1; dir <= 9; dir++) {
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];
			if (dist > distance(nx, ny)) {
				Nx = nx; Ny = ny;
				dist = distance(nx, ny);
			}
		}
		if (Nx == jongsoo.x && Ny == jongsoo.y) jongsoo.alive = false;
		cnt[cur.y][cur.x]--;
		bomb[i] = { Nx, Ny, true };
		cnt[Ny][Nx]++;
	}
}

void explosion() {
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if (cnt[y][x] == 0) board[y][x] = '.';
			else if (cnt[y][x] >= 2) {
				for (int i = 0; i < bomb.size(); i++) {
					if (bomb[i].alive && bomb[i].x == x && bomb[i].y == y) bomb[i].alive = false;
				}
				cnt[y][x] = 0;
				board[y][x] = '.';
			}
			else board[y][x] = 'R';
		}
	}
	board[jongsoo.y][jongsoo.x] = 'I';
}

void solve() {
	for (int t = 0; t < T; t++) {
		moveJongsoo(t);
		moveCrazy();
		explosion();
		if (!jongsoo.alive) {
			cout << "kraj " << t + 1;
			return;
		}
		// check();
	}
	check();
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	solve();
	return 0;
}