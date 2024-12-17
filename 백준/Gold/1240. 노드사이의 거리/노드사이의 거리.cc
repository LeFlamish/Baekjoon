#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
struct Edge {
	int to;
	int w;
};

int N, M, ret;
vector<Edge> V[1001];
bool visited[1001];

void init() {
	cin >> N >> M;
	for (int i = 1; i < N; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		Edge e = { y, w };
		V[x].push_back(e);
		e = { x, w };
		V[y].push_back(e);
	}
}

void DFS(int cur, int target, int sum) {
	visited[cur] = true;
	if (cur == target) {
		ret = sum;
		return;
	}

	for (int i = 0; i < V[cur].size(); i++) {
		int next = V[cur][i].to;
		int dist = V[cur][i].w;
		if (visited[next]) continue;
		DFS(next, target, sum + dist);
	}
	visited[cur] = false;
}

void solve() {
	for (int i = 0; i < M; i++) {
		memset(visited, false, sizeof(visited));
		int x, y;
		cin >> x >> y;
		DFS(x, y, 0);
		cout << ret << '\n';
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	solve();
	return 0;
}