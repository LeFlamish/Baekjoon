#include <iostream>
using namespace std;
typedef long double ld;

int T;
ld A, B;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cout << fixed;
	cout.precision(2);

	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> A >> B;
		cout << "The height of the triangle is " << (2 * A) / B << " units\n";
	}
	return 0;
}