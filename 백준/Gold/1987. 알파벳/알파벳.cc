#include <bits/stdc++.h>
using namespace std;
int T, R, C;
string s[20];

bool visited[26];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int answer;

void DFS(int x, int y, int cnt) {
    answer = max(answer, cnt);

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || nx >= C || ny < 0 || ny >= R) continue;
        if (visited[s[ny][nx] - 'A']) continue;
        visited[s[ny][nx] - 'A'] = true;
        DFS(nx, ny, cnt + 1);
        visited[s[ny][nx] - 'A'] = false;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        cin >> s[i];
    }
    visited[s[0][0] - 'A'] = true;
    DFS(0, 0, 1);
    cout << answer;
    return 0;
}