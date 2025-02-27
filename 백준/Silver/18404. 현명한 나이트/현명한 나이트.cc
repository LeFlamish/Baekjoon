#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> PI;
#define X first
#define Y second

int N, M, cnt, ret[1001];
int board[501][501];
int visited[501][501];
int dx[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dy[] = { -1, 1, -2, 2, -2, 2, -1, 1 };
PI S;

void init() {
	cin >> N >> M >> S.Y >> S.X;
	for (int i = 1; i <= M; i++) {
		int x, y;
		cin >> y >> x;
		board[y][x] = i;
	}
}

inline bool OOB(int x, int y) {
	return x < 1 || x > N || y < 1 || y > N;
}

void BFS() {
	queue<PI> Q;
	visited[S.Y][S.X] = 1;
	Q.push(S);
	while (!Q.empty()) {
		PI cur = Q.front(); Q.pop();
		if (board[cur.Y][cur.X]) {
			ret[board[cur.Y][cur.X]] = visited[cur.Y][cur.X] - 1;
			cnt++;
		}
		if (cnt == M) return;
		for (int dir = 0; dir < 8; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (OOB(nx, ny)) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = visited[cur.Y][cur.X] + 1;
			Q.push({ nx, ny });
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	BFS();
	for (int i = 1; i <= M; i++) cout << ret[i] << ' ';
	return 0;
}