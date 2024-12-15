#include <iostream>
#include <string>
using namespace std;

int N;
string S, T, ret;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> S >> T;
		for (int j = 0; j < S.size(); j++) {
			if (S[j] == 'x' || S[j] == 'X') {
				ret += toupper(T[j]);
				break;
			}
		}
	}
	cout << ret;
	return 0;
}