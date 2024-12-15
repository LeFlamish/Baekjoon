#include <iostream>
#include <cstring>
using namespace std;

int T, N;
int cur[11], give[11];

void init() {
	memset(cur, 0, sizeof(cur));
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> cur[i];
	}
}

bool check() {
	for (int i = 1; i < N; i++) {
		if (cur[i] == cur[i + 1]) continue;
		else return false;
	}
	return true;
}

int solve() {
	int ret = 0;
	while (1) {
		for (int i = 1; i <= N; i++) {
			if (cur[i] & 1) cur[i]++;
			give[i] = cur[i] / 2;
		}
		if (check()) break;
		ret++;
		for (int i = 1; i < N; i++) {
			cur[i + 1] += give[i] - give[i + 1];
		}
		cur[1] += give[N] - give[1];
	}
	return ret;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	for (int t = 0; t < T; t++) {
		init();
		cout << solve() << '\n';
	}
	return 0;
}