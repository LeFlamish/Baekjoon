#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> PI;
#define X first
#define Y second

int N;
int board[64][64];
bool visited[64][64];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void init() {
	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> board[y][x];
		}
	}
}

inline bool OOB(int x, int y) {
	return x < 0 || x >= N || y < 0 || y >= N;
}

bool BFS() {
	queue<PI> Q;
	visited[0][0] = true;
	Q.push({ 0, 0 });
	while (!Q.empty()) {
		PI cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X, ny = cur.Y;
			for (int i = 0; i < board[cur.Y][cur.X]; i++) {
				nx += dx[dir];
				ny += dy[dir];
			}
			if (OOB(nx, ny)) continue;
			if (visited[ny][nx] || board[ny][nx] == 0) continue;
			else if (board[ny][nx] == -1) return true;
			visited[ny][nx] = true;
			Q.push({ nx, ny });
		}
	}
	return false;
}

void solve() {
	if (BFS()) cout << "HaruHaru";
	else cout << "Hing";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	solve();
	return 0;
}