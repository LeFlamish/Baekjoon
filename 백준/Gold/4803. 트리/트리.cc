#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int, int> PI;

int N, M, ret;
vector<int> V[501];
bool visited[501];


void Clear() {
	for (int i = 1; i <= N; i++) {
		V[i].clear();
	}
}

bool init() {
	Clear();
	memset(visited, false, sizeof(visited));
	ret = 0;
	cin >> N >> M;
	if (N + M == 0) return false;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		V[x].push_back(y);
		V[y].push_back(x);
	}
	return true;
}

void BFS(int cur) {
	bool isTree = true;
	queue<PI> Q;
	visited[cur] = 1;
	Q.push(make_pair(cur, 0));
	while (!Q.empty()) {
		int cur = Q.front().first;
		int prev = Q.front().second; Q.pop();
		for (int i = 0; i < V[cur].size(); i++) {
			int next = V[cur][i];
			if (visited[next] && next != prev) {
				isTree = false;
				continue;
			}
			if (visited[next]) continue;
			visited[next] = true;
			Q.push(make_pair(next, cur));
		}
	}
	if (isTree) ret++;
}

void solve() {
	int time = 1;
	while (1) {
		if (!init()) break;
		cout << "Case " << time << ": ";
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) BFS(i);
		}
		if (ret == 0) cout << "No trees.\n";
		else if (ret == 1) cout << "There is one tree.\n";
		else {
			cout << "A forest of " << ret << " trees.\n";
		}
		time++;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	solve();
	return 0;
}