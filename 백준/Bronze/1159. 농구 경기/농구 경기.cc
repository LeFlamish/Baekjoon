#include <bits/stdc++.h>
using namespace std;

int N, alphabet[26];
string str;
bool flag;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		alphabet[str[0] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] > 4) {
			cout << char('a' + i);
			flag = true;
		}
	}
	if (!flag) cout << "PREDAJA";
	return 0;
}