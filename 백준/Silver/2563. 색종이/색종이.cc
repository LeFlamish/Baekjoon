#include <iostream>
using namespace std;

int N, ret;
bool total[100][100];

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int X, Y;
		cin >> X >> Y;
		for (int y = 0; y < 10; y++) {
			for (int x = 0; x < 10; x++) {
				total[Y + y][X + x] = true;
			}
		}
	}
}

void solve() {
	for (int y = 0; y < 100; y++) {
		for (int x = 0; x < 100; x++) {
			if (total[y][x]) ret++;
		}
	}
	cout << ret;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	solve();
	return 0;
}