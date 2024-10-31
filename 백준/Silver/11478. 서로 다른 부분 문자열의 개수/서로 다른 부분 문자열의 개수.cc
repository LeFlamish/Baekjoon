#include <iostream>
#include <set>
#include <string>
using namespace std;

string str;
set<string> S;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> str;
	int len = str.length();
	for (int i = 0; i < len; i++) {
		string tmp = "";
		for (int j = i; j < len; j++) {
			tmp += str[j];
			S.insert(tmp);
		}
	}
	cout << S.size();
	return 0;
}