#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int T, N, M;
vector<int> V[20001];
int visited[20001];
queue<int> Q;

void init() {
	memset(visited, 0, sizeof(visited));
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		V[x].push_back(y);
		V[y].push_back(x);
	}
}

void BFS(int start) {
	visited[start] = 1;
	Q.push(start);
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		int size = V[cur].size();
		for (int i = 0; i < size; i++) {
			int next = V[cur][i];
			if (visited[next]) continue;
			if (visited[cur] == 1) visited[next] = 2;
			else if (visited[cur] == 2) visited[next] = 1;
			Q.push(next);
		}
	}
}

bool check() {
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < V[i].size(); j++) {
			if (visited[i] == visited[V[i][j]]) return false;
		}
	}
	return true;
}

void solve() {
	init();
	for (int i = 1; i <= N; i++) {
		if (visited[i] == 0) {
			BFS(i);
		}
	}
	if (check()) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	for (int t = 0; t < T; t++) {
		solve();
		for (int i = 1; i <= N; i++) {
			V[i].clear();
		}
	}
	return 0;
}