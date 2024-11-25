#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, K, X;
vector<int> V[300001];
int visited[300001];
vector<int> ret;

void init() {
	cin >> N >> M >> K >> X;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		V[x].push_back(y);
	}
}

void BFS(int S) {
	visited[S] = 1;
	queue<int> Q;
	Q.push(S);
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		if (visited[cur] - 1 == K) {
			ret.push_back(cur);
			continue;
		}
		int size = V[cur].size();
		for (int i = 0; i < size; i++) {
			int nx = V[cur][i];
			if (visited[nx]) continue;
			visited[nx] = visited[cur] + 1;
			Q.push(nx);
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	BFS(X);
	sort(ret.begin(), ret.end());
	if (ret.size()) {
		for (int i : ret) {
			cout << i << '\n';
		}
	}
	else cout << -1;
	return 0;
}