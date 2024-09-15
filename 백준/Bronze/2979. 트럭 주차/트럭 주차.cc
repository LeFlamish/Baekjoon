#include <bits/stdc++.h>
#define SIZE 101
using namespace std;

int A, B, C, Start, End, ret;
int parking[SIZE];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> A >> B >> C;
	for (int i = 0; i < 3; i++) {
		cin >> Start >> End;
		for (int j = Start; j < End; j++) {
			parking[j]++;
		}
	}
	for (int i = 1; i < 101; i++) {
		if (parking[i] == 1) {
			ret += A;
		}
		else if (parking[i] == 2) {
			ret += B * 2;
		}
		else if (parking[i] == 3) {
			ret += C * 3;
		}
	}
	cout << ret;
	return 0;
}