#include <bits/stdc++.h>
using namespace std;
int N;
int visited[100001];
vector<int> adj[100001];

void BFS() {
	queue<int> Q;
	visited[1] = true;
	Q.push(1);
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		for (int dir = 0; dir < adj[cur].size(); dir++) {
			int nxt = adj[cur][dir];
			if (visited[nxt]) continue;
			visited[nxt] = cur;
			Q.push(nxt);
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int from, to;
		cin >> from >> to;
		adj[from].push_back(to);
		adj[to].push_back(from);
	}
	BFS();
	for (int i = 2; i <= N; i++) {
		cout << visited[i] << '\n';
	}
	return 0;
}