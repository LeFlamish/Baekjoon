#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
struct State {
	int x, y;
};

int N, M, X;
int board[100][100];
bool visited[100][100];

void init() {
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> board[y][x];
		}
	}
	cin >> X;
}

inline bool OOB(int x, int y) {
	return (x < 0 || x >= M || y < 0 || y >= N);
}

bool BFS() {
	if (board[0][0] != board[N - 1][M - 1]) return false;
	queue<State> Q;
	visited[0][0] = true;
	Q.push({ 0, 0 });
	while (!Q.empty()) {
		State cur = Q.front(); Q.pop();
		if (cur.x == M - 1 && cur.y == N - 1) return true;
		for (int dy = -X; dy <= X; dy++) {
			for (int dx = -X; dx <= X; dx++) {
				if (abs(dx) + abs(dy) > X || (dx == 0 && dy == 0)) continue;
				int nx = cur.x + dx;
				int ny = cur.y + dy;
				if (OOB(nx, ny)) continue;
				if (visited[ny][nx] || board[ny][nx] != board[cur.y][cur.x]) continue;
				visited[ny][nx] = true;
				Q.push({ nx, ny });
			}
		}
	}
	return false;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	if (BFS()) cout << "ALIVE";
	else cout << "DEAD";
	return 0;
}