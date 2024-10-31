#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100001

vector<int> graph[MAX];
int N, M, R;
int ret[MAX];
int cnt = 1;
queue<int> Q;

void BFS(int start) {
	ret[start] = cnt++;
	Q.push(start);
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		int size = graph[cur].size();
		for (int i = 0; i < size; i++) {
			int next = graph[cur][i];
			if (ret[next]) continue;
			ret[next] = cnt++;
			Q.push(next);
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M >> R;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end(), greater<>());
	}
	BFS(R);
	for (int i = 1; i <= N; i++) {
		cout << ret[i] << '\n';
	}
	return 0;
}