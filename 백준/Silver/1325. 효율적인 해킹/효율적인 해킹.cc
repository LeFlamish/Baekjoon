#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
vector<int> V[10001];
int ret[10001];
bool visited[10001];
vector<int> ans;

void init() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> to >> from;
		V[from].push_back(to);
	}
}

int BFS(int S) {
	int tmp = 0;
	memset(visited, false, sizeof(visited));
	visited[S] = true;
	queue<int> Q;
	Q.push(S);
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		tmp++;
		int size = V[cur].size();
		for (int i = 0; i < size; i++) {
			int next = V[cur][i];
			if (visited[next]) continue;
			visited[next] = true;
			Q.push(next);
		}
	}
	return tmp;
}

void solve() {
	int Max = 0;
	for (int i = 1; i <= N; i++) {
		ret[i] = BFS(i);
		Max = max(Max, ret[i]);
	}
	for (int i = 1; i <= N; i++) {
		if (ret[i] == Max) ans.push_back(i);
	}
	for (int i : ans) cout << i << ' ';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	solve();
	return 0;
}