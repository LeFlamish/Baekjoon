#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> CD;
#define X first
#define Y second
const int SIZE = 51;
int W, H, board[SIZE][SIZE], cnt;
bool visited[SIZE][SIZE];
int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };

void BFS(int x, int y) {
	visited[y][x] = true;
	queue<CD> Q;
	Q.push({ x, y });
	while (!Q.empty()) {
		CD cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 8; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
			if (board[ny][nx] == 0) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = true;
			Q.push({ nx, ny });
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while (true) {
		cnt = 0;
		memset(board, 0, sizeof(board));
		memset(visited, false, sizeof(visited));
		cin >> W >> H;
		if (W == 0 && H == 0) break;
		for (int h = 0; h < H; h++) {
			for (int w = 0; w < W; w++) {
				cin >> board[h][w];
			}
		}

		for (int h = 0; h < H; h++) {
			for (int w = 0; w < W; w++) {
				if (!visited[h][w] && board[h][w] == 1) {
					BFS(w, h);
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}