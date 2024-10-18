#include <iostream>
using namespace std;

int N;
int arr[1001];
int DP[1001];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	int ret = 0;
	for (int i = 1; i <= N; i++) {
		DP[i] = 1;
		for (int j = i - 1; j >= 1; j--) {
			if (arr[j] < arr[i]) {
				DP[i] = max(DP[i], DP[j] + 1);
			}
		}
		ret = max(DP[i], ret);
	}
	cout << ret;
	return 0;
}