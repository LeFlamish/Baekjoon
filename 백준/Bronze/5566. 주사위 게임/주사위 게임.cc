#include <iostream>
using namespace std;

int N, M, cur = 1;
int board[1001];
int dice[1001];

void init() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> board[i];
	}
	for (int i = 1; i <= M; i++) {
		cin >> dice[i];
	}
}

void solve() {
	for (int i = 1; i <= M; i++) {
		cur += dice[i];
		if (cur >= N) {
			cout << i;
			return;
		}
		cur += board[cur];
		if (cur >= N) {
			cout << i;
			return;
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	solve();
	return 0;
}