#include <iostream>
#include <string>
#include <stack>

#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;

int main(void) {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;

	FOR(i, N) {
		string myString;
		cin >> myString;

		stack<char> myStack;
		
		int x = 1;
		FOR(i, myString.size()) {
			if (myString[i] == '(') myStack.push(1);

			else {
				if (!(myStack.empty())) {
					myStack.pop();
				}
				else {
					x = 0;
					break;
				}
			}
		}

		if (x == 1) {
			if (myStack.empty()) cout << "YES\n";
			else cout << "NO\n";
		}
		else cout << "NO\n";
	}
}