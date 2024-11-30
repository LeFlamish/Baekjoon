#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
using namespace std;

int V, E, A, B, C;
int u, v, w;
int parent[10001];
long long ans;
bool check;
vector<tuple<int, int, int>> graph;

int find_parent(int x) {
	if (parent[x] == x) return x;
	else return parent[x] = find_parent(parent[x]);
}

void union_node(int u, int v) {
	check = false;
	u = find_parent(u);
	v = find_parent(v);
	if (u == v) return;
	else {
		parent[u] = v;
		check = true;
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> V >> E;
	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < E; i++) {
		cin >> A >> B >> C;
		graph.push_back(make_tuple(C, A, B));
	}
	sort(graph.begin(), graph.end());
	for (int i = 0; i < E; i++) {
		union_node(get<1>(graph[i]), get<2>(graph[i]));
		if (check) ans += get<0>(graph[i]);
	}
	cout << ans << '\n';
	return 0;
}