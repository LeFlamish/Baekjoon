#include <iostream>
#include <cmath>
using namespace std;

long long gcd(long long a, long long b) {
	while (b != 0) {
		long long temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int a, b, c, d, X, Y;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> a >> b >> c >> d;
	Y = b * d;
	X = b * c + a * d;
	int tmp = gcd(X, Y);
	Y /= tmp;
	X /= tmp;
	cout << X << ' ' << Y;
	return 0;
}