#include <iostream>
using namespace std;

int H, W;
string board[100];

void init() {
	cin >> H >> W;
	for (int h = 0; h < H; h++) {
		cin >> board[h];
	}
}

void solve() {
	for (int h = 0; h < H; h++) {
		for (int w = 0; w < W; w++) {
			if (board[h][w] == 'c') cout << 0 << ' ';
			else {
				bool flag = false;
				for (int x = w - 1; x >= 0; x--) {
					if (board[h][x] == 'c') {
						cout << w - x << ' ';
						flag = true;
						break;
					}
				}
				if (!flag) cout << -1 << ' ';
			}
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