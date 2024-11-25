#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N, K;
int visited[100001][2];
int dx[] = { -1, 1, 2 };
vector<int> V;

void init() {
	cin >> N >> K;
	memset(visited, -1, sizeof(visited));
}

void howToMove(int S) {
	if (visited[S][1] == -1) return;

	V.push_back(S);
	howToMove(visited[S][1]);
}

int BFS(int S) {
	int ret = 0;
	queue<int> Q;
	visited[S][0] = 1;
	Q.push(S);
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		if (cur == K) {
			ret = visited[K][0] - 1;
			break;
		}
		for (int dir = 0; dir < 3; dir++) {
			int nx = cur;
			if (dir == 2) nx *= 2;
			else {
				nx += dx[dir];
			}
			if (nx < 0 || nx > 100000) continue;
			if (visited[nx][0] > 0) continue;
			visited[nx][0] = visited[cur][0] + 1;
			visited[nx][1] = cur;
			Q.push(nx);
		}
	}
	howToMove(K);
	V.push_back(S);
	return ret;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	cout << BFS(N) << '\n';
	reverse(V.begin(), V.end());
	for (int i : V) {
		cout << i << ' ';
	}
	return 0;
}