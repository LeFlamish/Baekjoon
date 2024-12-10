#include <iostream>
#include <vector>
using namespace std;

int T, N, M;
vector<int> V[1001];

void solve() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		V[x].push_back(y);
		V[y].push_back(x);
	}
	cout << N - 1 << '\n';
	V->clear();
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	for (int t = 0; t < T; t++) {
		solve();
	}
	return 0;
}