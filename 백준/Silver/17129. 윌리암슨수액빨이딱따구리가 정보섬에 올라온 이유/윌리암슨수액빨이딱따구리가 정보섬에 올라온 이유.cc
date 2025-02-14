#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> PI;
#define X first
#define Y second

int N, M, ret;
string board[3000];
int visited[3000][3000];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
PI start;

void init() {
	bool flag = false;
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		cin >> board[y];
		if (flag) continue;
		for (int x = 0; x < M; x++) {
			if (board[y][x] == '2') {
				start = { x, y };
				flag = true;
				break;
			}
		}
	}
}

bool OutOfBounds(int x, int y) {
	return (x < 0 || x >= M || y < 0 || y >= N);
}

int BFS() {
	queue<PI> Q;
	visited[start.Y][start.X] = 1;
	Q.push(start);
	while (!Q.empty()) {
		PI cur = Q.front(); Q.pop();
		if (board[cur.Y][cur.X] >= '3' && board[cur.Y][cur.X] <= '5') return visited[cur.Y][cur.X];
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (OutOfBounds(nx, ny)) continue;
			if (visited[ny][nx] || board[ny][nx] == '1') continue;
			visited[ny][nx] = visited[cur.Y][cur.X] + 1;
			Q.push({ nx, ny });
		}
	}
	return 0;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	ret = BFS();
	if (ret) cout << "TAK\n" << --ret;
	else cout << "NIE";
	return 0;
}