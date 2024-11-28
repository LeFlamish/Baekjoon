#include <iostream>
#include <algorithm>
using namespace std;

int K;
int arr[13];
int selected[13];

bool init() {
	cin >> K;
	if (K == 0) return false;
	for (int i = 0; i < K; i++) {
		cin >> arr[i];
	}
	return true;
}

void printArr() {
	for (int i = 0; i < 6; i++) cout << selected[i] << ' ';
	cout << '\n';
}

void select(int cnt, int k) {
	if (cnt == 6) {
		printArr();
		return;
	}

	for (int i = k; i < K; i++) {
		selected[cnt] = arr[i];
		select(cnt + 1, i + 1);
	}
}

void solve() {
	while (init()) {
		select(0, 0);
		cout << '\n';
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	solve();
	return 0;
}