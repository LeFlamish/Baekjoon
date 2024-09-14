#include <bits/stdc++.h>
#define SIZE 1001
using namespace std;
typedef pair<int, int> CD;
#define X first
#define Y second

int R, C, ret;
string board[SIZE];
int visited[SIZE][SIZE];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
queue<CD> Jihoon;
queue<CD> Fire;

bool OutOfBound(int x, int y) {
	if (x < 0 || x >= C || y < 0 || y >= R) return true;
	return false;
}

void init() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> board[i];
	}

	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if (board[y][x] == 'J') {
				visited[y][x] = 1;
				Jihoon.push({ x, y });
			}
			if (board[y][x] == 'F') Fire.push({ x, y });
		}
	}
}

int solve() {
	while (!Jihoon.empty()) {
		int tmp = Fire.size();
		for (int i = 0; i < tmp; i++) {
			int Fcx = Fire.front().X;
			int Fcy = Fire.front().Y;
			Fire.pop();
			for (int dir = 0; dir < 4; dir++) {
				int Fnx = Fcx + dx[dir];
				int Fny = Fcy + dy[dir];
				if (OutOfBound(Fnx, Fny)) continue;
				if (board[Fny][Fnx] == '#' || board[Fny][Fnx] == 'F') continue;
				board[Fny][Fnx] = 'F';
				Fire.push({ Fnx, Fny });
			}
		}

		tmp = Jihoon.size();
		for (int i = 0; i < tmp; i++) {
			int Jcx = Jihoon.front().X;
			int Jcy = Jihoon.front().Y;
			Jihoon.pop();
			for (int dir = 0; dir < 4; dir++) {
				int Jnx = Jcx + dx[dir];
				int Jny = Jcy + dy[dir];
				if (OutOfBound(Jnx, Jny)) return visited[Jcy][Jcx];
				if (visited[Jny][Jnx] || board[Jny][Jnx] == '#' || board[Jny][Jnx] == 'F') continue;
				visited[Jny][Jnx] = visited[Jcy][Jcx] + 1;
				Jihoon.push({ Jnx, Jny });
			}
		}
	}
	return 0;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	ret = solve();
	if (ret) cout << ret;
	else cout << "IMPOSSIBLE";
	return 0;
}