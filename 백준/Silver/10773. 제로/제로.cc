#include <iostream>
#include <stack>

#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;

int main(void) {
	cin.tie(0)->sync_with_stdio(0);
	
	int K;
	cin >> K;

	int count = 0;
	stack<int> myStack;
	FOR(i, K) {
		int x;
		cin >> x;
		if (x != 0) {
			myStack.push(x);
			count++;
		}
		else {
			myStack.pop();
			count--;
		}
	}

	int sum = 0;
	FOR(i, count) {
		sum += myStack.top();
		myStack.pop();
	}

	cout << sum;

	return 0;
}	