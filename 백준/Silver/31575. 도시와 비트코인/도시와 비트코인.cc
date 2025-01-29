#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> PI;
#define X first
#define Y second
#define FOR(i, n) for(int i = 0; i < n; i++)

int N, M;
int board[300][300];
bool visited[300][300];
int dx[] = { 1, 0 };
int dy[] = { 0, 1 };

void init() {
	cin >> N >> M;
	FOR(y, M) {
		FOR(x, N) {
			cin >> board[y][x];
		}
	}
}

bool area(int x, int y) {
	return (x >= N || y >= M);
}

bool BFS() {
	queue<PI> Q;
	visited[0][0] = true;
	Q.push({ 0, 0 });
	while (!Q.empty()) {
		PI cur = Q.front(); Q.pop();
		if (cur.X == N - 1 && cur.Y == M - 1) return true;

		for (int dir = 0; dir < 2; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (area(nx, ny)) continue;
			if (visited[ny][nx] || !board[ny][nx]) continue;
			visited[ny][nx] = true;
			Q.push({ nx, ny });
		}
	}
	return false;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	if (BFS()) cout << "Yes";
	else cout << "No";
	return 0;
}