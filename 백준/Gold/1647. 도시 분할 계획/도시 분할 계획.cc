#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, ret;
int parent[100001];

int getParent(int num) {
	if (num == parent[num]) return num;
	return parent[num] = getParent(parent[num]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a != b) parent[a] = b;
}

bool findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) return true;
	else return false;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	vector<pair<int, pair<int, int>>> edge(M);
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		edge[i] = { C, { A, B } };
	}
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	sort(edge.begin(), edge.end());

	int maxCost = 0;
	for (int i = 0; i < M; i++) {
		int cost = edge[i].first;
		int A = edge[i].second.first;
		int B = edge[i].second.second;
		if (!findParent(A, B)) {
			maxCost = max(maxCost, cost);
			ret += cost;
			unionParent(A, B);
		}
	}
	cout << ret - maxCost;

	return 0;
}