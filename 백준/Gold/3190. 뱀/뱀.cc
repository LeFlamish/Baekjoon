#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> CD;
#define X first
#define Y second

const int SIZE = 101;

int N, K, L;
int board[SIZE][SIZE];
int curdir; // 0 : 우, 1 : 하, 2 : 좌, 3 : 상
CD Head = { 1, 1 };
int Time;
vector<pair<int, char>> order;

queue<CD> snake;
bool move(int curdir) {
    int nx = Head.X, ny = Head.Y;
    Time++;
    if (curdir == 3) ny--;
    else if (curdir == 1) ny++;
    else if (curdir == 2) nx--;
    else nx++;
    if (nx < 1 || nx > N || ny < 1 || ny > N || board[ny][nx] == 2)
        return true;
    snake.push({ nx, ny });
    if (board[ny][nx] == 0) {
        CD tail = snake.front();
        snake.pop();
        board[tail.Y][tail.X] = 0;
    }
    board[ny][nx] = 2;
    Head = { nx, ny };
    return false;
}

int main(void) {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> y >> x; // y와 x를 반대로 입력받음
        board[y][x] = 1;
    }
    cin >> L;
    order.push_back({ 0, 'D' });
    for (int i = 0; i < L; i++) {
        int cnt;
        char dir;
        cin >> cnt >> dir;
        order.push_back({ cnt, dir });
    }

    bool flag = false;
    curdir = 0;
    snake.push({ 1, 1 });
    int idx = 0;
    for (Time = 0; ; Time++) {
        for (int i = 1; i <= L; i++) {
            int cnt = order[i].X - order[i-1].X;
            char dir = order[i].Y;

            for (int j = 0; j < cnt; j++) {
                if (move(curdir)) {
                    cout << Time;
                    return 0;
                }
            }

            if (dir == 'D') curdir = (curdir + 1) % 4;
            else curdir = (curdir + 3) % 4;
        }
        while (1) {
            if (move(curdir)) {
                cout << Time;
                return 0;
            }
        }
    }

    return 0;
}