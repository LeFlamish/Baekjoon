#include <bits/stdc++.h>
using namespace std;
int N, adj[101][101], ret[101][101];
bool visited[101];

void DFS(int here) {
	for (int i = 0; i < N; i++) {
		if (adj[here][i]) {
			if (visited[i]) continue;
			visited[i] = true;
			DFS(i);
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> adj[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		memset(visited, false, sizeof(visited));
		DFS(i);
		for (int j = 0; j < N; j++) {
			if (visited[j]) ret[i][j] = 1;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << ret[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}