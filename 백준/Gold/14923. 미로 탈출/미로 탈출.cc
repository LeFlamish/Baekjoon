#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;
typedef pair<int, int> CD;
#define X first
#define Y second
#define MP(a, b) make_pair(a, b)

struct Human {
	int x, y, useMagic;
};

int N, M, Ex, Ey;
int board[1001][1001];
int visited[1001][1001][2];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
Human H, tmp;

void check() {
	cout << "====================\n";
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			cout << visited[y][x][0] << ' ';
		}
		cout << '\n';
	}
	cout << "====================\n";
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			cout << visited[y][x][1] << ' ';
		}
		cout << '\n';
	}
	cout << "====================\n";
}

void init() {
	cin >> N >> M >> H.y >> H.x >> Ey >> Ex;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			cin >> board[y][x];
		}
	}
}

bool area(int x, int y) {
	return (x < 1 || x > M || y < 1 || y > N);
}

void BFS() {
	queue<Human> Q;
	visited[H.y][H.x][2] = 1;
	Q.push(H);
	while (!Q.empty()) {
		Human cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];
			if (area(nx, ny)) continue;
			if (board[ny][nx] == 1) {
				if (cur.useMagic) continue;
				if (visited[ny][nx][1]) continue;
				tmp = { nx, ny, 1 };
				visited[ny][nx][1] = visited[cur.y][cur.x][cur.useMagic] + 1;
				Q.push(tmp);
			}
			else {
				if (visited[ny][nx][cur.useMagic]) continue;
				visited[ny][nx][cur.useMagic] = visited[cur.y][cur.x][cur.useMagic] + 1;
				tmp = { nx, ny, cur.useMagic };
				Q.push(tmp);
			}
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	BFS();
	// check();
	if (visited[Ey][Ex][0] == 0 && visited[Ey][Ex][1] == 0) cout << -1;
	else {
		if (visited[Ey][Ex][0] == 0) {
			cout << visited[Ey][Ex][1];
		}
		else if (visited[Ey][Ex][1] == 0) {
			cout << visited[Ey][Ex][0];
		}
		else {
			cout << min(visited[Ey][Ex][0], visited[Ey][Ex][1]);
		}
	}
	return 0;
}