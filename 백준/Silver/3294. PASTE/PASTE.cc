#include <iostream>
#include <list>
using namespace std;

int N, K, S, E, T;
list<int> L;

void init() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		L.push_back(i);
	}
}

void solve() {
	for (int k = 0; k < K; k++) {
		cin >> S >> E >> T;
		list<int> tmp;
		auto it = L.begin();
		advance(it, S - 1);
		auto end_it = it;
		advance(end_it, E - S + 1);
		tmp.splice(tmp.begin(), L, it, end_it);
		auto insert_it = L.begin();
		if (T > 0) {
			advance(insert_it, T);
		}
		L.splice(insert_it, tmp);
	}
	int cnt = 0;
	for (int i : L) {
		cout << i << '\n';
		cnt++;
		if (cnt == 10) break;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	solve();
	return 0;
}