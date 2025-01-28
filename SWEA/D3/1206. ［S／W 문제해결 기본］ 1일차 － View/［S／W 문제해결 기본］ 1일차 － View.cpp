#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int T, N, Max, ret;
int building[1000];

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> building[i];
}

void solve() {
	ret = 0;
	for (int i = 2; i < N - 2; i++) {
		Max = INT_MIN;
		for (int gap = -2; gap < 3; gap++) {
			if (gap == 0) continue;
			Max = max(Max, building[i + gap]);
		}
		ret += max(0, building[i] - Max);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	for (int t = 1; t <= 10; t++) {
		init();
		cout << "#" << t << ' ';
		solve();
		cout << ret << '\n';
	}
	return 0;
}