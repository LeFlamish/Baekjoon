#include <iostream>
#include <queue>
using namespace std;
#define FOR(i, N) for (int i = 1; i <= N; i++)

struct State {
	int x, y;
};

int N, K, S, X, Y;
int board[201][201];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
queue<State> virus[1001];

void debug() {
	cout << "====================\n";
	FOR(y, N) {
		FOR(x, N) {
			cout << board[y][x] << ' ';
		}
		cout << '\n';
	}
	cout << "====================\n";
}

void init() {
	cin >> N >> K;
	FOR(y, N) {
		FOR(x, N) {
			cin >> board[y][x];
			if (board[y][x]) virus[board[y][x]].push({ x, y });
		}
	}
	cin >> S >> Y >> X;
}

inline bool OOB(int x, int y) {
	return x < 1 || x > N || y < 1 || y > N;
}

void moveVirus() {
	FOR(k, K) {
		int size = virus[k].size();
		FOR(i, size) {
			State cur = virus[k].front(); virus[k].pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.x + dx[dir];
				int ny = cur.y + dy[dir];
				if (OOB(nx, ny)) continue;
				if (board[ny][nx]) continue;
				board[ny][nx] = k;
				virus[k].push({ nx, ny });
			}
		}
	}
}

void solve() {
	FOR(t, S) {
		moveVirus();
		//debug();
	}
	cout << board[Y][X];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	solve();
	return 0;
}