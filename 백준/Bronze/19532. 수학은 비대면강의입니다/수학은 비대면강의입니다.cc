#include <iostream>
using namespace std;

int x, y, a, b, c, d, e, f;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> a >> b >> c >> d >> e >> f;
	for (int y = -999; y < 1000; y++) {
		for (int x = -999; x < 1000; x++) {
			if (a * x + b * y == c && d * x + e * y == f) {
				cout << x << ' ' << y;
				return 0;
			}
		}
	}
	return 0;
}