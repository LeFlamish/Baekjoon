#include <bits/stdc++.h>
#define SIZE 21
using namespace std;

int N, S, ret;
int arr[SIZE];
bool visited[SIZE];
vector<int> ans;

void solve(int start) {
	if (accumulate(ans.begin(), ans.end(), 0) == S && !ans.empty()) {
		ret++;
	}

	for (int i = start; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			ans.push_back(arr[i]);
			solve(i);
			visited[i] = false;
			ans.pop_back();
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	solve(0);
	cout << ret;
	return 0;
}