#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int X, ret;
vector<int> science, society;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	for (int i = 0; i < 4; i++) {
		cin >> X;
		science.push_back(X);
	}
	for (int i = 0; i < 2; i++) {
		cin >> X;
		society.push_back(X);
	}
	sort(science.begin(), science.end(), greater<>());
	sort(society.begin(), society.end(), greater<>());
	for (int i = 0; i < 3; i++) ret += science[i];
	ret += society[0];
	cout << ret;
	return 0;
}