#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> PI;
#define X first
#define Y second

int N, M, K;
int board[1000][1000];
int visited[1000][1000];
int dx[2][6] = { { 1, 0, -1, -1, -1, 0 }, { 1, 1, 0, -1, 0, 1 } };
int dy[2][6] = { { 0, 1, 1, 0, -1, -1 }, { 0, 1, 1, 0, -1, -1 } };

void check() {
	cout << "====================\n";
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cout << board[y][x] << ' ';
		}
		cout << '\n';
	}
	cout << "--------------------\n";
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cout << visited[y][x] << ' ';
		}
		cout << '\n';
	}
	cout << "====================\n";
}

void init() {
	cin >> N >> M >> K;
	for (int k = 0; k < K; k++) {
		int x, y;
		cin >> y >> x;
		board[y][x] = 1;
	}
}

inline bool OOB(int x, int y) {
	return x < 0 || x >= M || y < 0 || y >= N;
}

int BFS() {
	queue<PI> Q;
	visited[0][0] = 1;
	Q.push({ 0, 0 });
	while (!Q.empty()) {
		PI cur = Q.front(); Q.pop();
		if (cur.X == M - 1 && cur.Y == N - 1) return visited[N - 1][M - 1] - 1;
		int isOdd = (cur.Y & 1);
		for (int dir = 0; dir < 6; dir++) {
			int nx = cur.X + dx[isOdd][dir];
			int ny = cur.Y + dy[isOdd][dir];
			if (OOB(nx, ny)) continue;
			if (visited[ny][nx] || board[ny][nx]) continue;
			visited[ny][nx] = visited[cur.Y][cur.X] + 1;
			Q.push({ nx, ny });
		}
	}
	return -1;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	cout << BFS();
	// check();
	return 0;
}