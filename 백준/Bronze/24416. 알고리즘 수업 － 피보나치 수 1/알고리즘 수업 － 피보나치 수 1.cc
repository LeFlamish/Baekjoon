#include <iostream>
using namespace std;

int N, ret1, ret2;
int arr[41];

int recursion(int n) {
	if (n == 1 || n == 2) {
		ret1++;
		return 1;
	}
	return recursion(n - 1) + recursion(n - 2);
}

int dp(int n) {
	arr[1] = arr[2] = 1;
	for (int i = 3; i <= n; i++) {
		ret2++;
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	return arr[n];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	recursion(N);
	dp(N);
	cout << ret1 << ' ' << ret2;
	return 0;
}