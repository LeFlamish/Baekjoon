#include <iostream>
#include <algorithm>
using namespace std;

int board[501][501];
int dx[][4] = {
    {0, 1, 2, 3},
    {0, 0, 0, 0},
    {0, 1, 0, 1},
    {0, -1, -1, -1},
    {0, -1, -1, -1},
    {0, 1, 1, 1},
    {0, 1, 1, 1},
    {0, 0, -1, -2},
    {0, 0, 1, 2},
    {0, 0, -1, -2},
    {0, 0, 1, 2},
    {0, 0, -1, -1},
    {0, 0, 1, 1},
    {0, 0, -1, -1},
    {0, 0, 1, 1},
    {0, -1, -1, -2},
    {0, -1, -1, -2},
    {0, 1, 1, 2},
    {0, 1, 1, 2},
    {0, -1, 0, 1},
    {0, -1, 0, 1},
    {0, 0, 1, 0},
    {0, 0, -1, 0}
};
int dy[][4] = { 
    {0, 0, 0, 0},
    {0, 1, 2, 3},
    {0, 0, 1, 1},
    {0, 0, -1, -2},
    {0, 0, 1, 2},
    {0, 0, -1, -2},
    {0, 0, 1, 2},
    {0, -1, -1, -1},
    {0, -1, -1, -1},
    {0, 1, 1, 1},
    {0, 1, 1, 1},
    {0, -1, -1, -2},
    {0, -1, -1, -2},
    {0, 1, 1, 2},
    {0, 1, 1, 2},
    {0, 0, -1, -1},
    {0, 0, 1, 1},
    {0, 0, -1, -1},
    {0, 0, 1, 1},
    {0, 0, 1, 0},
    {0, 0, -1, 0},
    {0, -1, 0, 1},
    {0, -1, 0, 1}
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> board[i][j];
        }
    }
    
    int Max = 0;
    int sum = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            for (int k = 0; k < 23; k++) {
                sum = 0;
                for (int dir = 0; dir < 4; dir++) {
                    if (i + dy[k][dir] < 1 || i + dy[k][dir] > N || j + dx[k][dir] < 1 || j + dx[k][dir] > M) break;
                    sum += board[i + dy[k][dir]][j + dx[k][dir]];
                }
                Max = max(sum, Max);
            }
        }
    }

    cout << Max;

    return 0;
}