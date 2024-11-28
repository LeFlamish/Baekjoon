#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int N, ret = INT_MIN;
int arr[8];
int selected[8];
bool visited[8];

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

int calculate() {
	int tmp = 0;
	for (int i = 0; i < N - 1; i++) {
		tmp += abs(selected[i] - selected[i + 1]);
	}
	return tmp;
}

void select(int cnt) {
	if (cnt == N) {
		ret = max(ret, calculate());
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			selected[cnt] = arr[i];
			select(cnt + 1);
			visited[i] = false;
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	select(0);
	cout << ret;
	return 0;
}