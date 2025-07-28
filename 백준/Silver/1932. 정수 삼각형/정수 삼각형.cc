#include <iostream>
#include <algorithm>
using namespace std;

int N, ret;
int dp[500][500];
int dx[] = { -1, 0 };
int dy[] = { -1, -1 };

bool OOB(int x, int y) {
	return x < 0 || x > y;
}

void solve() {
	cin >> N;
	cin >> dp[0][0];
	for (int y = 1; y < N; y++) {
		for (int x = 0; x < y + 1; x++) {
			int tmp;
			cin >> tmp;
			for (int dir = 0; dir < 2; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (OOB(nx, ny)) continue;
				dp[y][x] = max(dp[y][x], dp[ny][nx] + tmp);
			}
		}
	}
	for (int x = 0; x < N; x++) {
		ret = max(ret, dp[N - 1][x]);
	}
	cout << ret;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	solve();
	return 0;
}