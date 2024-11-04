#include <iostream>
using namespace std;

int N, ret;

bool isPrime(int n) {
	if (n == 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while (1) {
		ret = 0;
		cin >> N;
		if (N == 0) break;
		for (int i = N + 1; i <= 2 * N; i++) {
			if (isPrime(i)) ret++;
		}
		cout << ret << '\n';
	}
	return 0;
}