#include <iostream>
using namespace std;

int total;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	for (int i = 0; i < 4; i++) {
		int tmp;
		cin >> tmp;
		total += tmp;
	}
	if (total + 300 <= 1800) cout << "Yes";
	else cout << "No";
	return 0;
}