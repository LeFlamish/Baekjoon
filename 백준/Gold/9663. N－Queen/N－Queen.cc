#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> col;
int answer = 0;

bool is_valid(int row, int c) {
    for (int i = 0; i < row; ++i) {
        if (col[i] == c || abs(i - row) == abs(col[i] - c)) {
            return false;
        }
    }
    return true;
}

void n_queen(int row) {
    if (row == N) {
        answer++;
        return;
    }

    for (int c = 0; c < N; ++c) {
        if (is_valid(row, c)) {
            col[row] = c;
            n_queen(row + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    col.resize(N);

    n_queen(0);
    
    cout << answer << "\n";

    return 0;
}
