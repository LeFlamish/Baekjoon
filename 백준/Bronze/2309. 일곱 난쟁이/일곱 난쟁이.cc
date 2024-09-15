#include <bits/stdc++.h>
#define SIZE 9
using namespace std;

int tall[SIZE], sum, tmp;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	for (int i = 0; i < 9; i++) {
		cin >> tall[i];
		sum += tall[i];
	}
	tmp = sum - 100;
	sort(tall, tall + SIZE);
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (tall[i] + tall[j] == tmp) {
				for (int k = 0; k < 9; k++) {
					if (k == i || k == j) continue;
					cout << tall[k] << '\n';
				}
				return 0;
			}
		}
	}
	return 0;
}