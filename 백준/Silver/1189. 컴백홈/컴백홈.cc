#include <iostream>
using namespace std;
typedef pair<int, int> CD;
#define X first
#define Y second

int R, C, K, ret;
string board[5];
bool visited[5][5];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void init() {
	cin >> R >> C >> K;
	for (int y = 0; y < R; y++) {
		cin >> board[y];
	}
}

bool area(int x, int y) {
	return (x < 0 || x >= C || y < 0 || y >= R);
}

void DFS(CD cur, int cnt) {
	if (cnt == K) {
		if (cur.X == C - 1 && cur.Y == 0) ret++;
		return;
	}

	visited[cur.Y][cur.X] = true;

	for (int dir = 0; dir < 4; dir++) {
		int nx = cur.X + dx[dir];
		int ny = cur.Y + dy[dir];
		if (area(nx, ny)) continue;
		if (visited[ny][nx] || board[ny][nx] == 'T') continue;
		DFS(make_pair(nx, ny), cnt + 1);
	}

	visited[cur.Y][cur.X] = false;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	DFS(make_pair(0, R - 1), 1);
	cout << ret;
	return 0;
}