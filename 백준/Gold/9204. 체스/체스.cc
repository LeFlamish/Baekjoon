#include <iostream>
#include <queue>
#include <stack>
using namespace std;
typedef pair<int, int> PI;
#define X first
#define Y second
struct Path {
	int x, y, d;
};

int T;
int board[9][9];
Path visited[9][9];
int dx[] = { 1, 1, -1, -1 };
int dy[] = { -1, 1, 1, -1 };
PI S, E;
stack<PI> path;

void init() {
	char tmp1, tmp2;
	cin >> tmp1 >> S.Y >> tmp2 >> E.Y;
	S.X = tmp1 - 'A' + 1; E.X = tmp2 - 'A' + 1;
	for (int y = 1; y < 9; y++) {
		for (int x = 1; x < 9; x++) {
			visited[y][x] = { 0, 0, 0 };
		}
	}
}

inline bool OOB(int x, int y) {
	return x < 1 || x > 8 || y < 1 || y > 8;
}

bool BFS() {
	queue<PI> Q;
	visited[S.Y][S.X] = { S.X, S.Y, 1 };
	Q.push({ S });
	while (!Q.empty()) {
		PI cur = Q.front(); Q.pop();
		if (cur == E) return true;
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X;
			int ny = cur.Y;
			while (1) {
				nx += dx[dir];
				ny += dy[dir];
				if (OOB(nx, ny)) break;
				if (visited[ny][nx].d) continue;
				visited[ny][nx] = { cur.X, cur.Y, visited[cur.Y][cur.X].d + 1 };
				Q.push({ nx, ny });
			}
		}
	}
	return false;
}

void findPath() {
	PI cur = E;
	while (1) {
		path.push(cur);
		if (cur == S) break;
		PI next = { visited[cur.Y][cur.X].x, visited[cur.Y][cur.X].y };
		cur = next;
	}
}

void solve() {
	if (BFS()) {
		findPath();
		cout << visited[E.Y][E.X].d - 1 << ' ';
		while (!path.empty()) {
			PI cur = path.top(); path.pop();
			cout << (char)(cur.X + 'A' - 1) << ' ' << cur.Y << ' ';
		}
		cout << '\n';
	}
	else cout << "Impossible\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	for (int t = 0; t < T; t++) {
		init();
		solve();
	}
	return 0;
}