#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int N;
int Max = INT_MIN, Min = INT_MAX;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		Max = max(tmp, Max);
		Min = min(tmp, Min);
	}
	cout << Max * Min;
	return 0;
}