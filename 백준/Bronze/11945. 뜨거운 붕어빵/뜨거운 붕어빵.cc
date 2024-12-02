#include <iostream>
using namespace std;

int N, M;
string board[10];

void init() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}
}

void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = M - 1; j >= 0; j--) {
			cout << board[i][j];
		}
		cout << '\n';
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	solve();
	return 0;
}