#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> PI;
#define X first
#define Y second

int N;
int board[200][200];
int visited[200][200];
int dx[] = { -1, 1, -2, 2, -1, 1 };
int dy[] = { -2, -2, 0, 0, 2, 2 };
PI S, E;

void init() {
	cin >> N;
	cin >> S.Y >> S.X >> E.Y >> E.X;
}

inline bool OOB(int x, int y) {
	return x < 0 || x >= N || y < 0 || y >= N;
}

int BFS() {
	queue<PI> Q;
	visited[S.Y][S.X] = 1;
	Q.push(S);
	while (!Q.empty()) {
		PI cur = Q.front(); Q.pop();
		if (cur == E) return visited[cur.Y][cur.X] - 1;
		for (int dir = 0; dir < 6; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (OOB(nx, ny)) continue;
			if (visited[ny][nx]) continue;
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