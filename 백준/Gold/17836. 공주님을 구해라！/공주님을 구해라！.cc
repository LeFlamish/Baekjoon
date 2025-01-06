#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct Warrior {
	int x, y, sword;
};

int N, M, T;
int board[100][100];
int visited[100][100][2];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void init() {
	cin >> N >> M >> T;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> board[y][x];
		}
	}
}

bool area(int x, int y) {
	return (x < 0 || x >= M || y < 0 || y >= N);
}

void BFS() {
	queue<Warrior> Q;
	visited[0][0][0] = 1;
	Q.push({ 0, 0, 0 });
	while (!Q.empty()) {
		Warrior cur = Q.front(); Q.pop();
		if (board[cur.y][cur.x] == 2) {
			cur.sword = 1;
			visited[cur.y][cur.x][1] = visited[cur.y][cur.x][0];
		}

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];
			if (area(nx, ny)) continue;
			if (visited[ny][nx][cur.sword]) continue;
			if (!cur.sword) {
				if (board[ny][nx] == 1) continue;
			}
			visited[ny][nx][cur.sword] = visited[cur.y][cur.x][cur.sword] + 1;
			Q.push({ nx, ny, cur.sword });
		}
	}
}

void answer() {
	if (visited[N - 1][M - 1][0] == 0 && visited[N - 1][M - 1][1] == 0) cout << "Fail";
	else if (visited[N - 1][M - 1][0] == 0) {
		if (visited[N - 1][M - 1][1] - 1 <= T) cout << visited[N - 1][M - 1][1] - 1;
		else cout << "Fail";
	}
	else if (visited[N - 1][M - 1][1] == 0) {
		if (visited[N - 1][M - 1][0] - 1 <= T) cout << visited[N - 1][M - 1][0] - 1;
		else cout << "Fail";
	}
	else {
		int ret = min(visited[N - 1][M - 1][0] - 1, visited[N - 1][M - 1][1] - 1);
		if (ret <= T) cout << ret;
		else cout << "Fail";
	}
}

void check() {
	for (int i = 0; i < 2; i++) {
		cout << "====================\n";
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				cout << visited[y][x][i];
			}
			cout << '\n';
		}
	}
	cout << "====================\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	BFS();
	answer();
	return 0;
}