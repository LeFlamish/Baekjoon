#include <bits/stdc++.h>
using namespace std;

int T, N;
long long ret;
int arr[101];
bool visited[101];
int selected[2];

int GCD(int a, int b) {
	if (b == 0) return a;
	return GCD(b, a % b);
}

void Select(int cnt, int k) {
	if (cnt == 2) {
		ret += GCD(selected[0], selected[1]);
		return;
	}
	
	for (int i = k; i < N; i++) {
		selected[cnt] = arr[i];
		Select(cnt + 1, i + 1);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	for (int t = 0; t < T; t++) {
		memset(visited, false, sizeof(visited));
		ret = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		Select(0, 0);
		cout << ret << '\n';
	}
	return 0;
}