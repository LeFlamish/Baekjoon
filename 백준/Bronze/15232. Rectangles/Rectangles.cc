#include <iostream>
using namespace std;

int R, C;

int main() {
	cin >> R >> C;
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			cout << '*';
		}
		cout << '\n';
	}
	return 0;
}