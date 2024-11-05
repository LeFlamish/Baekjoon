#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(const pair<string, int>& a, const pair<string, int>& b) {
	if (a.second != b.second) return a.second > b.second;
	if (a.first.length() != b.first.length()) return a.first.length() > b.first.length();
	return a.first < b.first;
}

int N, M;
string tmp;
map<string, int> Map;
vector<pair<string, int>> V;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (tmp.length() < M) continue;
		Map[tmp] += 1;
	}
	for (auto i : Map) {
		V.push_back(i);
	}
	sort(V.begin(), V.end(), compare);
	for (auto i : V) {
		cout << i.first << '\n';
	}
	return 0;
}