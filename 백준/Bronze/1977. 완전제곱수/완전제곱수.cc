#include <iostream>
#include <algorithm>
using namespace std;

int M, N, ret, Min = 10000;
bool flag;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> M >> N;
	for (int i = 1; i <= 100; i++) {
		if (i * i >= M && i * i <= N) {
			ret += i * i;
			Min = min(i * i, Min);
		}
		else if (i * i > N) break;
	}
	if (ret != 0) cout << ret << '\n' << Min;
	else cout << -1;
	return 0;
}