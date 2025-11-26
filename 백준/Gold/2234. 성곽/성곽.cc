#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

struct Position {
	int x, y;
};

int N, M, RoomCnt, MaxRoomArea, MaxRoomCnt;
int board[50][50];
bool visited[50][50];
queue<Position> Q;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

void init() {
	cin >> N >> M;
	for (int y = 0; y < M; y++) {
		for (int x = 0; x < N; x++) {
			cin >> board[y][x];
		}
	}
}

bool OOB(int x, int y) {
	return x < 0 || x >= N || y < 0 || y >= M;
}

void checkRoom() {
	for (int y = 0; y < M; y++) {
		for (int x = 0; x < N; x++) {
			if (visited[y][x]) continue;
			RoomCnt++;
			int area = 0;
			visited[y][x] = true;
			Q.push({ x, y });
			while (!Q.empty()) {
				Position cur = Q.front(); Q.pop();
				area++;
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.x + dx[dir];
					int ny = cur.y + dy[dir];
					if (OOB(nx, ny)) continue;
					if (visited[ny][nx] || (board[cur.y][cur.x] & (int)pow(2, dir))) continue;
					visited[ny][nx] = true;
					Q.push({ nx, ny });
				}
			}
			MaxRoomArea = max(MaxRoomArea, area);
		}
	}
	memset(visited, 0, sizeof(visited));
	cout << RoomCnt << '\n' << MaxRoomArea << '\n';
}

void maxRoom() {
	for (int y = 0; y < M; y++) {
		for (int x = 0; x < N; x++) {
			for (int i = 0; i < 4; i++) {
				int wall = pow(2, i);
				if (board[y][x] & wall) {
					memset(visited, 0, sizeof(visited));
					board[y][x] -= wall;
					Q.push({ x, y });
					visited[y][x] = true;
					int cnt = 0;
					while (!Q.empty()) {
						Position cur = Q.front(); Q.pop();
						cnt++;
						for (int dir = 0; dir < 4; dir++) {
							int nx = cur.x + dx[dir];
							int ny = cur.y + dy[dir];
							if (OOB(nx, ny)) continue;
							if (visited[ny][nx] || (board[cur.y][cur.x] & (int)pow(2, dir))) continue;
							visited[ny][nx] = true;
							Q.push({ nx, ny });
						}
					}
					board[y][x] += wall;
					MaxRoomCnt = max(MaxRoomCnt, cnt);
				}
			}
		}
	}
	cout << MaxRoomCnt;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	checkRoom();
	maxRoom();
	return 0;
}