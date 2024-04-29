#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int Position[11][11];
int answer[11];
bool selectedPlayer[11];
int Max;
int sum;

void selectPlayer(int cnt) {
    if (cnt == 11) {
        sum = accumulate(answer, answer + 11, 0);
        Max = max(sum, Max);
        return;
    }

    for (int i = 0; i < 11; i++) {
        if (Position[i][cnt] > 0 && !selectedPlayer[i]) {
            answer[cnt] = Position[i][cnt];
            selectedPlayer[i] = true;
            selectPlayer(cnt + 1);
            selectedPlayer[i] = false;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int T;
    cin >> T;

    for (int test = 0; test < T; test++) {
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 11; j++) {
                cin >> Position[i][j];
            }
        }

        Max = 0;
        selectPlayer(0);

        cout << Max << '\n';
    }

    return 0;
}
