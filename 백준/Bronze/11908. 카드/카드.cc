#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, ret;
vector<int> V;

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		V.push_back(x);
	}
}

void solve() {
	sort(V.begin(), V.end());
	for (int i = 0; i < N - 1; i++) {
		ret += V[i];
	}
	cout << ret;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	solve();
	return 0;
}