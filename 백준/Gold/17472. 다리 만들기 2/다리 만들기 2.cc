#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int map[11][11];
int parent[10];
bool visited[10];
int dir[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
queue<pair<int, int>> q;

struct edge {
public:
	int node[2];
	int dist;
	edge(int a, int b, int dist) {
		this->node[0] = a;
		this->node[1] = b;
		this->dist = dist;
	}
	bool operator <(edge& e) {
		return this->dist < e.dist;
	}
};

vector<edge> v;

void bfs(int x, int y, int num) {
	q.push({ x, y });
	map[y][x] = num;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
			if (map[ny][nx] == -1) {
				map[ny][nx] = num;
				q.push({ nx, ny });
			}
		}
	}
}

void move(int x, int y, int direction) {
	int sum = 0;
	int value = map[y][x];
	int nx = x;
	int ny = y;
	while (1) {
		nx += dir[direction][0];
		ny += dir[direction][1];
		if (nx < 0 || nx >= m || ny < 0 || ny >= n || map[ny][nx] == value) return;
		if (map[ny][nx] == 0)
			sum++;
		else {
			if (sum >= 2)
				v.push_back(edge(value, map[ny][nx], sum));
			return;
		}
	}
}

int get_parent(int a) {
	if (parent[a] == a)	return a;
	else return get_parent(parent[a]);
}

void union_parent(int a, int b) {
	a = get_parent(a);
	b = get_parent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

bool find(int a, int b) {
	a = get_parent(a);
	b = get_parent(b);
	if (a == b) return true;
	else return false;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				map[i][j] = -1;
		}

	int num = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (map[i][j] == -1) {
				bfs(j, i, num);
				num++;
			}
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < 4; k++)
				if (map[i][j] != 0)
					move(j, i, k);

	sort(v.begin(), v.end());

	for (int i = 0; i < 10; i++) {
		parent[i] = i;
	}

	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		if (!find(v[i].node[0], v[i].node[1])) {
			sum += v[i].dist;
			union_parent(v[i].node[0], v[i].node[1]);
		}
	}

	int p = get_parent(1);
	for (int i = 2; i < num; i++)
		if (p != get_parent(i))
			sum = 0;

	if (sum == 0)
		cout << "-1";
	else
		cout << sum;
}