#include <iostream>
#include <set>
using namespace std;

int T, K;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	for (int t = 0; t < T; t++) {
		multiset<int> MS;
		cin >> K;
		for (int k = 0; k < K; k++) {
			char o;
			int n;
			cin >> o >> n;

			if (o == 'I') MS.insert(n);
			else {
				if (MS.empty()) continue;
				if (n == 1) {
					auto iter = MS.end();
					iter--;
					MS.erase(iter);
				}
				else {
					MS.erase(MS.begin());
				}
			}
		}
		if (MS.empty()) cout << "EMPTY\n";
		else {
			auto iter = MS.end();
			iter--;
			cout << *iter << ' ' << *MS.begin() << '\n';
		}
	}
	return 0;
}