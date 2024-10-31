#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> V;
int mid, avg;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	for (int i = 0; i < 5; i++) {
		int x;
		cin >> x;
		V.push_back(x);
		avg += x;
	}
	sort(V.begin(), V.end());
	avg /= 5;
	mid = V[2];
	cout << avg << '\n' << mid;
	return 0;
}