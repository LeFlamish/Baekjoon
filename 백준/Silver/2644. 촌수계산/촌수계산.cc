#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, x, y, M;
vector<int> V[101];
int visited[101];

void init() {
	cin >> N >> x >> y >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
}

int BFS(int n) {
	visited[n] = 1;
	queue<int> Q;
	Q.push(n);
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		if (cur == y) return visited[cur] - 1;
		int size = V[cur].size();
		for (int i = 0; i < size; i++) {
			int next = V[cur][i];
			if (visited[next]) continue;
			visited[next] = visited[cur] + 1;
			Q.push(next);
		}
	}
	return -1;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	cout << BFS(x);
	return 0;
}