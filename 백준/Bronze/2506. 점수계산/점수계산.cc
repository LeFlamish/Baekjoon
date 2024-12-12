#include <iostream>
using namespace std;

int N, ret, score;
int arr[101];

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

void solve() {
	for (int i = 0; i < N; i++) {
		if (arr[i]) score++;
		else score = 0;
		ret += score;
	}
	cout << ret;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	solve();
	return 0;
}