#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> CD;
#define X first
#define Y second

int N, M;
int board[100][100];
bool air[100][100];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void init() {
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> board[y][x];
		}
	}
}

void findAir() {
	memset(air, false, sizeof(air));
	queue<CD> Q;
	air[0][0] = true;
	Q.push(make_pair(0, 0));
	while (!Q.empty()) {
		CD cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
			if (air[ny][nx] || board[ny][nx] == 1) continue;
			air[ny][nx] = true;
			Q.push(make_pair(nx, ny));
		}
	}
}

void meltCheese() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (board[y][x] == 1) {
				int cnt = 0;
				for (int dir = 0; dir < 4; dir++) {
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
					if (air[ny][nx]) cnt++;
				}
				if (cnt >= 2) board[y][x] = 0;
			}
		}
	}
}

bool checkEnd() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (board[y][x]) return true;
		}
	}
	return false;
}

int solve() {
	int t = 0;
	while (checkEnd()) {
		findAir();
		meltCheese();
		t++;
	}
	return t;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	cout << solve();
	return 0;
}