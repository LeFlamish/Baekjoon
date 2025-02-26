#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 1000;
char building[MAX][MAX];
int fire[MAX][MAX];
int dist[MAX][MAX];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs_fire(int H, int W) {
    queue<pair<int, int>> q;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (building[i][j] == '*') {
                q.push({i, j});
                fire[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (building[nx][ny] == '#' || fire[nx][ny] != -1) continue;

            fire[nx][ny] = fire[x][y] + 1;
            q.push({nx, ny});
        }
    }
}

int bfs_escape(int H, int W, int start_x, int start_y) {
    queue<pair<int, int>> q;
    q.push({start_x, start_y});
    dist[start_x][start_y] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == 0 || x == H - 1 || y == 0 || y == W - 1) {
            return dist[x][y] + 1;
        }

        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (building[nx][ny] == '#' || dist[nx][ny] != -1) continue;
            if (fire[nx][ny] != -1 && dist[x][y] + 1 >= fire[nx][ny]) continue;

            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }

    return -1; // 탈출 불가능한 경우
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int W, H;
        cin >> W >> H;

        memset(fire, -1, sizeof(fire));
        memset(dist, -1, sizeof(dist));

        int start_x, start_y;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                cin >> building[i][j];
                if (building[i][j] == '@') {
                    start_x = i;
                    start_y = j;
                }
            }
        }

        bfs_fire(H, W);
        int result = bfs_escape(H, W, start_x, start_y);
        if (result == -1) {
            cout << "IMPOSSIBLE\n";
        } else {
            cout << result << "\n";
        }
    }

    return 0;
}
