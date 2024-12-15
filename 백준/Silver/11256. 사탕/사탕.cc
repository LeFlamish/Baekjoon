#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, J, N, ret;
vector<int> V;

void init() {
	ret = 0;
	V.clear();
	cin >> J >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		V.push_back(x * y);
	}
	sort(V.begin(), V.end(), greater<>());
}

void solve() {
	while (1) {
		J -= V[0]; V.erase(V.begin());
		ret++;
		if (J <= 0) break;
	}
	cout << ret << '\n';
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