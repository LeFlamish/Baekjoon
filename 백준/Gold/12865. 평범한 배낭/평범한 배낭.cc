#include <bits/stdc++.h>
using namespace std;
int N, K;
int item[101][2]; // 무게 | 가치
int DP[101][100001];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> item[i][0] >> item[i][1];
    }
    for (int w = 1; w <= K; w++) {
        for (int i = 1; i <= N; i++) {
            if (item[i][0] <= w) DP[i][w] = max(DP[i - 1][w - item[i][0]] + item[i][1], DP[i - 1][w]);
            else DP[i][w] = DP[i - 1][w];
        }
    }
    cout << DP[N][K];
    return 0;
}