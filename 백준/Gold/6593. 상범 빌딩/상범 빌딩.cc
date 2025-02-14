#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
struct State {
	int x, y, z;
};

int L, R, C;
string board[30][30];
int visited[30][30][30];
int dx[] = { 1, 0, -1, 0, 0, 0 };
int dy[] = { 0, 1, 0, -1, 0, 0 };
int dz[] = { 0, 0, 0, 0, 1, -1 };
State S, E;

void check() {
	cout << "====================\n";
	for (int z = 0; z < L; z++) {
		for (int y = 0; y < R; y++) {
			for (int x = 0; x < C; x++) {
				cout << visited[z][y][x] << ' ';
			}
			cout << '\n';
		}
		cout << "\n\n";
	}
	cout << "====================\n";
}

bool init() {
	cin >> L >> R >> C;
	if (L + R + C == 0) return false;
	memset(visited, 0, sizeof(visited));
	int flag = 0;
	for (int z = 0; z < L; z++) {
		for (int y = 0; y < R; y++) {
			cin >> board[z][y];
			if (flag == 2) continue;
			for (int x = 0; x < C; x++) {
				if (board[z][y][x] == 'S') {
					S = { x, y, z };
					flag++;
				}
				else if (board[z][y][x] == 'E') {
					E = { x, y, z };
					flag++;
				}
			}
		}
		cin;
	}
	return true;
}

inline bool OOB(int x, int y, int z) {
	return (x < 0 || x >= C || y < 0 || y >= R || z < 0 || z >= L);
}

bool BFS(State S) {
	queue<State> Q;
	visited[S.z][S.y][S.x] = 1;
	Q.push(S);
	while (!Q.empty()) {
		State cur = Q.front(); Q.pop();
		if (board[cur.z][cur.y][cur.x] == 'E') return true;
		for (int dir = 0; dir < 6; dir++) {
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];
			int nz = cur.z + dz[dir];
			if (OOB(nx, ny, nz)) continue;
			if (visited[nz][ny][nx] || board[nz][ny][nx] == '#') continue;
			visited[nz][ny][nx] = visited[cur.z][cur.y][cur.x] + 1;
			Q.push({ nx, ny, nz });
		}
	}
	return false;
}

void solve() {
	while (1) {
		if (!init()) break;
		if (BFS(S)) cout << "Escaped in " << visited[E.z][E.y][E.x] - 1 << " minute(s).\n";
		else cout << "Trapped!\n";
		// check();
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	solve();
	return 0;
}