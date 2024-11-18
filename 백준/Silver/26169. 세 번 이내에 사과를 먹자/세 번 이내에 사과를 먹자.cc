#include <iostream>
using namespace std;
typedef pair<int, int> CD;
#define X first
#define Y second

int ret;
int board[5][5];
CD start;
bool visited[5][5];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };

void init() {
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {
            cin >> board[y][x];
        }
    }
    cin >> start.Y >> start.X;
}

bool DFS(CD cur, int cnt, int apple) {
    visited[cur.Y][cur.X] = true;

    // 종료 조건: 3칸 이동 완료
    if (cnt == 3) {
        if (apple > 1) {
            ret = 1;
            return true; // 조건 만족 시 탐색 종료
        }
        visited[cur.Y][cur.X] = false;
        return false;
    }

    // 4방향 탐색
    for (int dir = 0; dir < 4; dir++) {
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];

        // 범위 및 방문 여부 확인
        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
        if (visited[ny][nx] || board[ny][nx] == -1) continue;

        // 다음 칸으로 이동
        if (DFS({ nx, ny }, cnt + 1, apple + (board[ny][nx] == 1))) {
            return true; // 조건 만족 시 바로 종료
        }
    }

    // 백트래킹: 방문 해제
    visited[cur.Y][cur.X] = false;
    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    init();
    DFS(start, 0, 0);
    cout << ret;
    return 0;
}