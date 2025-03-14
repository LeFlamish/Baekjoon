#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> CD;
#define X first
#define Y second
const int SIZE = 101;
int N, board[SIZE][SIZE], Max = INT_MIN, Min = INT_MAX, cnt, temp;
bool visited[SIZE][SIZE];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

void BFS(int x, int y, int h) {
	queue<CD> Q;
	visited[y][x] = true;
	Q.push({ x, y });
	while (!Q.empty()) {
		CD cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (board[ny][nx] <= h) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = true;
			Q.push({ nx, ny });
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			Max = max(board[i][j], Max);
			Min = min(board[i][j], Min);
		}
	}

	for (int h = Min - 1; h <= Max; h++) {
		temp = 0;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (board[i][j] > h && !visited[i][j]) {
					BFS(j, i, h);
					temp++;
				}
			}
		}
		cnt = max(cnt, temp);
	}
	cout << cnt;
	return 0;
}