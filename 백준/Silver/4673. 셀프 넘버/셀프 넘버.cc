#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool selfNum[10001];

int d(int n) {
	int ret = n;
	while (n != 0) {
		ret += n % 10;
		n = n / 10;
	}
	if (ret > 10000) return 2;
	return ret;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	memset(selfNum, true, sizeof(selfNum));
	for (int i = 1; i <= 10000; i++) {
		selfNum[d(i)] = false;
	}
	for (int i = 1; i <= 10000; i++) {
		if (selfNum[i]) cout << i << '\n';
	}
	return 0;
}