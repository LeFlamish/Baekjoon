#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;
#define FOR(i, N) for (int i = 0; i < N; i++)

struct State {
	int x, y;
};

int N, M, ret = INT_MAX;
int board[50][50];
int tmp[50][50];
int visited[50][50];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
vector<State> V;
State selected[10];

void debug() {
	cout << "====================\n";
	FOR(y, N) {
		FOR(x, N) {
			cout << tmp[y][x] << ' ';
		}
		cout << '\n';
	}
	cout << "--------------------\n";
	FOR(y, N) {
		FOR(x, N) {
			cout << visited[y][x] << ' ';
		}
		cout << '\n';
	}
	cout << "====================\n";
}

void init() {
	cin >> N >> M;
	FOR(y, N) {
		FOR(x, N) {
			cin >> board[y][x];
			if (board[y][x] == 2) {
				V.push_back({ x, y });
			}
		}
	}
}

inline void copyBoard() {
	FOR(y, N) {
		FOR(x, N) {
			tmp[y][x] = board[y][x];
		}
	}
	return;
}

inline void makeBoard() {
	FOR(i, M) {
		tmp[selected[i].y][selected[i].x] = 2;
	}
}

inline bool OOB(int x, int y) {
	return x < 0 || x >= N || y < 0 || y >= N;
}

int BFS() {
	memset(visited, -1, sizeof(visited));
	int Max = 0;
	queue<State> Q;
	FOR(i, M) {
		visited[selected[i].y][selected[i].x] = 0;
		Q.push(selected[i]);
	}
	while (!Q.empty()) {
		State cur = Q.front(); Q.pop();
		if (tmp[cur.y][cur.x] != 2) {
			Max = max(Max, visited[cur.y][cur.x]);
			tmp[cur.y][cur.x] = 2;
		}
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];
			if (OOB(nx, ny)) continue;
			if (visited[ny][nx] != -1 || board[ny][nx] == 1) continue;
			visited[ny][nx] = visited[cur.y][cur.x] + 1;
			Q.push({ nx, ny });
		}
	}
	return Max;
}

bool checkAll() {
	FOR(y, N) {
		FOR(x, N) {
			if (!tmp[y][x] && visited[y][x] == -1) return false;
		}
	}
	return true;
}

void solve(int cnt, int k) {
	if (cnt == M) {
		copyBoard();
		makeBoard();
		int Max = BFS();
		if (checkAll()) ret = min(Max, ret);
		//debug();
		return;
	}

	for (int i = k; i < V.size(); i++) {
		selected[cnt] = V[i];
		solve(cnt + 1, i + 1);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	solve(0, 0);
	if (ret == INT_MAX) cout << -1;
	else cout << ret;
	return 0;
}