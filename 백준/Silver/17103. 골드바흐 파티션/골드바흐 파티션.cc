#include <iostream>
#include <vector>
using namespace std;
#define MAX 1000001

vector<bool> isPrime(MAX, true);

void init() {
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i < MAX; i++) {
		if (isPrime[i]) {
			for (int j = i * i; j < MAX; j += i) {
				isPrime[j] = false;
			}
		}
	}
}

int T, N, ret;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	cin >> T;
	while (T--) {
		ret = 0;
		cin >> N;
		for (int i = 2; i <= N / 2; i++) {
			if (isPrime[i] && isPrime[N - i]) ret++;
		}
		cout << ret << '\n';
	}
	return 0;
}