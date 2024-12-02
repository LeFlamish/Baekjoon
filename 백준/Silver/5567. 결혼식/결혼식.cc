#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, ret;
vector<int> V[501];
int visited[501];

void init() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		V[x].push_back(y);
		V[y].push_back(x);
	}
}

void BFS() {
	queue<int> Q;
	visited[1] = 1;
	Q.push(1);
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		int size = V[cur].size();
		for (int i = 0; i < size; i++) {
			int next = V[cur][i];
			if (visited[next]) continue;
			visited[next] = visited[cur] + 1;
			if (visited[next] > 3) continue;
			Q.push(next);
			ret++;
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	BFS();
	cout << ret;
	return 0;
}