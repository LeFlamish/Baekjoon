#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> CD;
#define X first
#define Y second

int C, R;
int board[100][100];
bool meltingAir[100][100];
int wasCheese[100][100];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };

void init() {
	cin >> R >> C;
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			cin >> board[y][x];
		}
	}
}

void checkAir() {
	memset(meltingAir, false, sizeof(meltingAir));
	queue<CD> Q;
	meltingAir[0][0] = true;
	Q.push(make_pair(0, 0));
	while (!Q.empty()) {
		CD cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= C || ny < 0 || ny >= R) continue;
			if (meltingAir[ny][nx] || board[ny][nx] != 0) continue;
			meltingAir[ny][nx] = true;
			Q.push(make_pair(nx, ny));
		}
	}
}

void meltingCheese(int t) {
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if (meltingAir[y][x]) {
				for (int dir = 0; dir < 4; dir++) {
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if (nx < 0 || nx >= C || ny < 0 || ny >= R) continue;
					if (board[ny][nx] == 1) {
						board[ny][nx] = 0;
						wasCheese[ny][nx] = t;
					}
				}
			}
		}
	}
}

bool checkEmpty() {
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if (board[y][x] == 1) return false;
		}
	}
	return true;
}

void solve() {
	int t = 0;
	int cnt = 0;
	while (1) {
		t++;
		checkAir();
		meltingCheese(t);
		if (checkEmpty()) break;
	}
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if (wasCheese[y][x] == t) cnt++;
		}
	}
	cout << t << '\n' << cnt;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	solve();
	return 0;
}