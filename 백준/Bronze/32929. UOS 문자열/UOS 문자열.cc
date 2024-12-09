#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int x;
	char arr[4] = {'S', 'U', 'O' };
	cin >> x;
	cout << arr[x % 3];
	return 0;
}