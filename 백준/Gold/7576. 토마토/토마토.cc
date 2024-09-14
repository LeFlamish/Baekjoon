#include <bits/stdc++.h>
#define SIZE 1001
using namespace std;

int N, M;
int board[SIZE][SIZE];
int visited[SIZE][SIZE];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
queue<pair<int, int>> Q;

void init() {
    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) {
                visited[i][j] = 1;
                Q.push({ j, i });
            }
        }
    }
}

void BFS() {
    while (!Q.empty()) {
        int cx = Q.front().first;
        int cy = Q.front().second;
        Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
            if (board[ny][nx] == -1 || visited[ny][nx] != 0) continue;
            visited[ny][nx] = visited[cy][cx] + 1;
            Q.push({ nx, ny });
        }
    }
}

int answer() {
    int ret = 0;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (board[y][x] == 0 && visited[y][x] == 0) return -1;
            ret = max(ret, visited[y][x]);
        }
    }
    return ret - 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    init();
    BFS();
    cout << answer();
    return 0;
}