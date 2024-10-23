#include <bits/stdc++.h>
using namespace std;

int N;
int arr[1000001];
int nge[1000001];
stack<int> S;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= N; i++) {
		while (!S.empty() && arr[S.top()] < arr[i]) {
			nge[S.top()] = arr[i];
			S.pop();
		}
		S.push(i);
	}
	while (!S.empty()) {
		nge[S.top()] = -1;
		S.pop();
	}

	for (int i = 1; i <= N; i++) cout << nge[i] << " ";
	return 0;
}