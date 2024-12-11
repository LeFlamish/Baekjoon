#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
struct Edge {
    int to; //인접 정점의 번호
    long long w; //가중치
    Edge(int to, long long w) : to(to), w(w) {}
};

int N, selected, dist;
vector<Edge> V[100001];
bool visited[100001];

void init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        while (1) {
            int t, w;
            cin >> t;
            if (t == -1) break;
            cin >> w;
            V[n].push_back(Edge(t, w));
        }
    }
}

void DFS(int cur, int cnt) {
    visited[cur] = true;
    if (dist < cnt) {
        dist = cnt;
        selected = cur;
    }

    for (int i = 0; i < V[cur].size(); i++) {
        int next = V[cur][i].to;
        int cost = V[cur][i].w;
        if (visited[next]) continue;
        DFS(next, cnt + cost);
    }
    visited[cur] = false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    init();
    DFS(1, 0);
    memset(visited, false, sizeof(visited));
    DFS(selected, 0);
    cout << dist;
    return 0;
}