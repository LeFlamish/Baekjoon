#include <iostream>
using namespace std;

int N, ret;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 1; i * i <= N; i++) {
		ret++;
	}
	cout << ret;
	return 0;
}