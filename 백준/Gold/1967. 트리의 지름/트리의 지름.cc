#include <iostream>
#include <vector>
using namespace std;
struct Edge {
	int to;
	int w;
};

int N, start, Max;
vector<Edge> V[10001];
bool visited[10001];

void init() {
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int P, C, W;
		cin >> P >> C >> W;
		Edge e = { C, W };
		V[P].push_back(e);
		e = { P, W };
		V[C].push_back(e);
	}
}

void DFS(int cur, int sum) {
	bool flag = true;
	visited[cur] = true;

	for (int i = 0; i < V[cur].size(); i++) {
		int next = V[cur][i].to;
		int dist = V[cur][i].w;
		if (visited[next]) continue;
		flag = false;
		DFS(next, sum + dist);
	}

	if (flag) {
		if (Max < sum) {
			start = cur;
			Max = sum;
		}
	}
	visited[cur] = false;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	DFS(1, 0);
	DFS(start, 0);
	cout << Max;
	return 0;
}