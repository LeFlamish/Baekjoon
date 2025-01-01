#include <iostream>
#include <algorithm>


using namespace std;

int answer[10];
int num[10];
bool selected[10];
int N, M;

void Select(int k, int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; i++) {
            cout << answer[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = k; i <= N; i++) {
        if (num[i] != num[i - 1] || selected[i - 1]) {
            answer[cnt] = num[i];
            selected[i] = true;
            Select(i, cnt + 1);
            selected[i] = false;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> num[i];
    }
    sort(num + 1, num + N + 1);
    
    Select(1, 0);

    return 0;
}
