#include <iostream>
#include <cmath>
#include <set>
using namespace std;

string positions[36];
bool visited[6][6];

bool isValidMove(int px, int py, int nx, int ny) {
    int dx = abs(nx - px);
    int dy = abs(ny - py);
    return (dx == 1 && dy == 2) || (dx == 2 && dy == 1);
}

void solve() {
    for (int i = 0; i < 36; i++) {
        cin >> positions[i];
    }

    int startX = positions[0][0] - 'A';
    int startY = positions[0][1] - '1';

    int prevX = startX, prevY = startY;

    fill(&visited[0][0], &visited[0][0] + 6 * 6, false);
    visited[startX][startY] = true;

    for (int i = 1; i < 36; i++) {
        int currX = positions[i][0] - 'A';
        int currY = positions[i][1] - '1';

        if (!isValidMove(prevX, prevY, currX, currY) || visited[currX][currY]) {
            cout << "Invalid";
            return;
        }

        visited[currX][currY] = true;
        prevX = currX;
        prevY = currY;
    }

    if (!isValidMove(prevX, prevY, startX, startY)) {
        cout << "Invalid";
        return;
    }

    cout << "Valid";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}