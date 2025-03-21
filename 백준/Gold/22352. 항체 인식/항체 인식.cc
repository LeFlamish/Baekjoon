#include <iostream>
#include <queue>
using namespace std;
#define FOR(i, N) for (int i = 0; i < N; i++)

struct State {
	int x, y;
};

int N, M;
int before[30][30];
int after[30][30];
bool visited[30][30];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void debug() {
	cout << "====================\n";
	FOR(y, N) {
		FOR(x, M) {
			cout << before[y][x] << ' ';
		}
		cout << '\n';
	}
	cout << "====================\n";
}

void init() {
	cin >> N >> M;
	FOR(y, N) {
		FOR(x, M) {
			cin >> before[y][x];
		}
	}
	FOR(y, N) {
		FOR(x, M) {
			cin >> after[y][x];
		}
	}
}

inline bool OOB(int x, int y) {
	return x < 0 || x >= M || y < 0 || y >= N;
}

void BFS(int x, int y) {
	queue<State> Q;
	int change = after[y][x];
	visited[y][x] = true;
	Q.push({ x, y });
	while (!Q.empty()) {
		State cur = Q.front(); Q.pop();
		FOR(dir, 4) {
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];
			if (OOB(nx, ny)) continue;
			if (visited[ny][nx] || before[ny][nx] != before[cur.y][cur.x]) continue;
			visited[ny][nx] = true;
			Q.push({ nx, ny });
		}
		before[cur.y][cur.x] = change;
	}
}

bool check() {
	FOR(y, N) {
		FOR(x, M) {
			if (before[y][x] != after[y][x]) {
				return false;
			}
		}
	}
	return true;
}

void solve() {
	FOR(y, N) {
		FOR(x, M) {
			if (before[y][x] != after[y][x]) {
				BFS(x, y);
				//debug();
				if (check()) cout << "YES";
				else cout << "NO";
				return;
			}
		}
	}
	cout << "YES";
	return;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	solve();
	return 0;
}