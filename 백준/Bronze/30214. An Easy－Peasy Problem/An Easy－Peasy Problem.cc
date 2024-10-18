#include <iostream>
using namespace std;

int A, B;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> A >> B;
	if (A >= (B + 1) / 2) cout << 'E';
	else cout << 'H';
	return 0;
}