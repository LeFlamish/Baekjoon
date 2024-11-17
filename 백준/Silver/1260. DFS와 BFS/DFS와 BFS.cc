#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1001;
int N, M, V;
bool visited[SIZE];
vector<vector<int>> graph(SIZE);

void BFS(int start) {
	visited[start] = true;
	queue<int> Q;
	Q.push(start);
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		cout << cur << ' ';
		for (int dir = 0; dir < graph[cur].size(); dir++) {
			int next = graph[cur][dir];
			if (visited[next]) continue;
			Q.push(next);
			visited[next] = true;
		}
	}
}

void DFS(int start) {
	if (visited[start]) return;

	visited[start] = true;
	cout << start << ' ';

	for (int dir = 0; dir < graph[start].size(); dir++) {
		DFS(graph[start][dir]);
	}
}

int main(void) {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	
	DFS(V);
	cout << '\n';
	memset(visited, false, sizeof(visited));
	BFS(V);

	return 0;
}