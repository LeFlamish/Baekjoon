#include <iostream>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

#define X first
#define Y second

char map[5][5];
bool Select[25];
int answer;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool MoreThanFour() {
    int cnt = 0;
    for (int i = 0; i < 25; i++) {
        if (Select[i] == true) {
            int x = i / 5;
            int y = i % 5;
            if (map[x][y] == 'S') cnt++;
        }
    }
    if (cnt >= 4) return true;
    else return false;
}

bool Adjacency() {
    queue<pair<int, int>> myQueue;
    bool CheckSelect[5][5];
    bool QueueSelect[5][5];
    bool CheckAnswer = false;

    memset(QueueSelect, false, sizeof(QueueSelect));
    memset(CheckSelect, false, sizeof(CheckSelect));

    int tmp = 0;
    for (int i = 0; i < 25; i++) {
        if (Select[i] == true) {
            int x = i / 5;
            int y = i % 5;
            CheckSelect[x][y] = true;

            if (tmp == 0) {
                myQueue.push(make_pair(x, y));
                QueueSelect[x][y] = true;
                tmp++;
            }
        }
    }

    int cnt = 1;
    while (myQueue.empty() == 0) {
        int x = myQueue.front().X;
        int y = myQueue.front().Y;
        myQueue.pop();

        if (cnt == 7) {
            CheckAnswer = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
            if (CheckSelect[nx][ny] == true && QueueSelect[nx][ny] == false) {
                QueueSelect[nx][ny] = true;
                myQueue.push(make_pair(nx, ny));
                cnt++;
            }
        }
    }

    if (CheckAnswer == true) return true;
    return false;
}

void DFS(int index, int cnt) {
    if (cnt == 7) {
        if (MoreThanFour() == true) {
            if (Adjacency() == true) answer++;
        }
        return;
    }

    for (int i = index; i < 25; i++) {
        if (Select[i] == true) continue;
        Select[i] = true;
        DFS(i, cnt + 1);
        Select[i] = false;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> map[i][j];
        }
    }

    DFS(0, 0);
    cout << answer;

    return 0;
}
