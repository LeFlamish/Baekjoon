#include <iostream>
using namespace std;
typedef pair<int, int> CD;
#define X first
#define Y second

int N, M;
string board[50];
bool visited[50][50];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
bool cycle;

void init() {
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		cin >> board[y];
	}
}

bool area(int x, int y) {
	return (x < 0 || x >= M || y < 0 || y >= N);
}

void DFS(int cx, int cy, int px, int py) {
	visited[cy][cx] = true;

	for (int dir = 0; dir < 4; dir++) {
		int nx = cx + dx[dir];
		int ny = cy + dy[dir];
		if (area(nx, ny)) continue;
		if (board[ny][nx] != board[cy][cx]) continue;
		if (visited[ny][nx]) {
			if (nx == px && ny == py) continue;
			else {
				cycle = true;
				return;
			}
		}
		DFS(nx, ny, cx, cy);
	}
}

void solve() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (!visited[y][x]) DFS(x, y, -1, -1);
			
			if (cycle) {
				cout << "Yes";
				return;
			}
		}
	}
	cout << "No";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	solve();
	return 0;
}