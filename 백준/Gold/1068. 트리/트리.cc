#include <iostream>
#include <vector>
using namespace std;

int N, target, root, ret;
vector<int> V[50];
bool visited[50];

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int parent;
		cin >> parent;
		if (parent == -1) {
			root = i;
			continue;
		}
		V[parent].push_back(i);
	}
	cin >> target;
	V[target].clear();
}

void DFS(int cur) {
	bool flag = true;
	visited[cur] = true;
	if (cur == target) return;

	for (int i = 0; i < V[cur].size(); i++) {
		int next = V[cur][i];
		if (visited[next] || next == target) continue;
		flag = false;
		DFS(next);
	}

	if (flag) {
		ret++;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	DFS(root);
	cout << ret;
	return 0;
}