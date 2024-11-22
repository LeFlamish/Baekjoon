#include <iostream>
#include <vector>
using namespace std;

int N;
vector<char> V[26];

void init() {
	cin >> N;
	char A, B, C;
	for (int i = 0; i < N; i++) {
		cin >> A >> B >> C;
		V[A - 'A'].push_back(B);
		V[A - 'A'].push_back(C);
	}
}

void preorder(char cur) {
	if (cur != '.') {
		cout << cur;
		preorder(V[cur - 'A'][0]);
		preorder(V[cur - 'A'][1]);
	}
	return;
}

void inorder(char cur) {
	if (cur != '.') {
		inorder(V[cur - 'A'][0]);
		cout << cur;
		inorder(V[cur - 'A'][1]);
	}
	return;
}

void postorder(char cur) {
	if (cur != '.') {
		postorder(V[cur - 'A'][0]);
		postorder(V[cur - 'A'][1]);
		cout << cur;
	}
	return;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	preorder('A');
	cout << '\n';
	inorder('A');
	cout << '\n';
	postorder('A');
	return 0;
}