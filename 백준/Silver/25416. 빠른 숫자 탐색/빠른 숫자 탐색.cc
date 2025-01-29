#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> PI;
#define X first
#define Y second
#define FOR(i, N) for (int i = 0; i < N; i++)

int board[5][5];
int visited[5][5];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
PI student;

void init() {
	FOR(y, 5) {
		FOR(x, 5) {
			cin >> board[y][x];
		}
	}
	cin >> student.Y >> student.X;
}

bool area(int x, int y) {
	return (x < 0 || x >= 5 || y < 0 || y >= 5);
}

int BFS() {
	queue<PI> Q;
	visited[student.Y][student.X] = 1;
	Q.push(student);

	while (!Q.empty()) {
		PI cur = Q.front(); Q.pop();
		if (board[cur.Y][cur.X] == 1) return visited[cur.Y][cur.X] - 1;

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (area(nx, ny)) continue;
			if (visited[ny][nx] || board[ny][nx] == -1) continue;
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
	return 0;
}