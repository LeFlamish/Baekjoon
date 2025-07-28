#include <iostream>
#include <cstring>
using namespace std;

int T, N;
int sticker[2][100000];
int dp[2][100000];

void init() {
	memset(sticker, 0, sizeof(sticker));
	memset(dp, 0, sizeof(dp));
	cin >> N;
	for (int y = 0; y < 2; y++) {
		for (int x = 0; x < N; x++) {
			cin >> sticker[y][x];
		}
	}
	dp[0][0] = sticker[0][0];
	dp[1][0] = sticker[1][0];
	dp[0][1] = sticker[0][1] + dp[1][0];
	dp[1][1] = sticker[1][1] + dp[0][0];
}

void solve() {
	for (int i = 2; i < N; i++) {
		dp[0][i] = sticker[0][i] + max(dp[1][i - 2], dp[1][i - 1]);
		dp[1][i] = sticker[1][i] + max(dp[0][i - 2], dp[0][i - 1]);
	}
	cout << max(dp[0][N - 1], dp[1][N - 1]) << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	for (int t = 0; t < T; t++) {
		init();
		solve();
	}
	return 0;
}