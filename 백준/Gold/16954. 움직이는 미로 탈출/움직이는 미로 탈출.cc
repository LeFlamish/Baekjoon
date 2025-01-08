#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> CD;
#define X first
#define Y second

string board[8];
bool visited[8][8];
int dx[] = { 0, 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[] = { 0, 0, 1, 1, 1, 0, -1, -1, -1 };
queue<CD> Q;

void check(int cx, int cy) {
	cout << "====================\n";
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			if (x == cx && y == cy) cout << '*';
			else cout << board[y][x];
		}
		cout << '\n';
	}
	cout << "====================\n";
}

void init() {
	for (int y = 0; y < 8; y++) {
		cin >> board[y];
	}
}

bool area(int x, int y) {
	return (x < 0 || x >= 8 || y < 0 || y >= 8);
}

void moveDown() {
	for (int y = 7; y >= 0; y--) {
		for (int x = 0; x < 8; x++) {
			if (board[y][x] == '#') {
				board[y][x] = '.';
				if (y + 1 < 8) {
					board[y + 1][x] = '#';
				}
			}
		}
	}
}

bool solve() {
	visited[7][0] = true;
	Q.push({ 0, 7 });
	while (!Q.empty()) {
		int size = Q.size();
		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < size; i++) {
			CD cur = Q.front(); Q.pop();
			int cx = cur.X, cy = cur.Y;

			if (board[cy][cx] == '#') continue;
			if (cx == 7 && cy == 0) return true;

			for (int dir = 0; dir < 9; dir++) {
				int nx = cx + dx[dir];
				int ny = cy + dy[dir];
				if (area(nx, ny) || board[ny][nx] == '#' || visited[ny][nx]) continue;
				visited[ny][nx] = true;
				Q.push({ nx, ny });
			}
		}
		moveDown();
	}
	return false;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	if (solve()) cout << 1;
	else cout << 0;
	return 0;
}