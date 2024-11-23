#include <iostream>
#include <queue>
#include <string>
using namespace std;
typedef pair<int, int> CD;
#define X first
#define Y second

int R, C;
string board[50];
int visited[50][50];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };
CD S, E;
queue<CD> Q;

void init() {
	cin >> R >> C;
	for (int y = 0; y < R; y++) {
		cin >> board[y];
	}
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if (board[y][x] == 'S') {
				visited[y][x] = 1;
				S = make_pair(x, y);
			}
			else if (board[y][x] == 'D') E = make_pair(x, y);
		}
	}
	visited[S.Y][S.X] = 1;
	Q.push(S);
}

void check() {
	cout << "====================\n";
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			cout << board[y][x] << ' ';
		}
		cout << '\n';
	}
	cout << "====================\n";
}

void moveWater() {
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if (board[y][x] == '*') {
				board[y][x] = '-';
			}
		}
	}
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if (board[y][x] == '-') {
				board[y][x] = '*';
				for (int dir = 0; dir < 4; dir++) {
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if (nx < 0 || nx >= C || ny < 0 || ny >= R) continue;
					if (board[ny][nx] == '.') board[ny][nx] = '*';
				}
			}
		}
	}
}

bool solve() {
	while (!Q.empty()) {
		moveWater();
		int size = Q.size();
		for (int i = 0; i < size; i++) {
			CD cur = Q.front(); Q.pop();
			if (cur == E) return true;
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= C || ny < 0 || ny >= R) continue;
				if (visited[ny][nx] || board[ny][nx] == '*' || board[ny][nx] == 'X') continue;
				visited[ny][nx] = visited[cur.Y][cur.X] + 1;
				Q.push(make_pair(nx, ny));
			}
		}
	}
	return false;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	if (solve()) cout << visited[E.Y][E.X] - 1;
	else cout << "KAKTUS";
	return 0;
}