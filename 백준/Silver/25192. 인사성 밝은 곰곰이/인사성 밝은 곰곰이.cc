#include <iostream>
#include <string>
#include <set>
using namespace std;

int N, ret;
set<string> S;
bool flag;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		if (str == "ENTER") {
			flag = true;
			S.clear();
		}
		else {
			if (flag) {
				if (S.find(str) == S.end()) {
					ret++;
					S.insert(str);
				}
			}
		}
	}
	cout << ret;
	return 0;
}