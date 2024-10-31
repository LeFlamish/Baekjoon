#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> X, Y;

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		X.push_back(x);
		Y.push_back(y);
	}
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	cout << (X[N - 1] - X[0]) * (Y[N - 1] - Y[0]);
	return 0;
}