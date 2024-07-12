#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> CD;
#define X first
#define Y second
const int SIZE = 101;
int N, M, K, board[SIZE][SIZE], cnt;
bool visited[SIZE][SIZE];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
vector<int> ret;

int BFS(int x, int y) {
	int temp = 1;
	visited[y][x] = true;
	queue<CD> Q;
	Q.push({ x, y });
	while (!Q.empty()) {
		CD cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (visited[ny][nx]) continue;
			if (board[ny][nx]) continue;
			visited[ny][nx] = true;
			Q.push({ nx, ny });
			temp++;
		}
	}
	return temp;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> M >> N >> K;
	for (int k = 0; k < K; k++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int i = b; i < d; i++) {
			for (int j = a; j < c; j++) {
				board[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 0 && !visited[i][j]) {
				ret.push_back(BFS(j, i));
				cnt++;
			}
		}
	}
	sort(ret.begin(), ret.end());
	cout << cnt << '\n';
	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << ' ';
	}
	return 0;
}

// 내 풀이 (BFS)
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> CD;
#define X first
#define Y second
const int SIZE = 101;
int N, M, K, board[SIZE][SIZE], cnt;
bool visited[SIZE][SIZE];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
vector<int> ret;

int BFS(int x, int y) {
	int temp = 1;
	visited[y][x] = true;
	queue<CD> Q;
	Q.push({ x, y });
	while (!Q.empty()) {
		CD cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (visited[ny][nx]) continue;
			if (board[ny][nx]) continue;
			visited[ny][nx] = true;
			Q.push({ nx, ny });
			temp++;
		}
	}
	return temp;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> M >> N >> K;
	for (int k = 0; k < K; k++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int i = b; i < d; i++) {
			for (int j = a; j < c; j++) {
				board[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 0 && !visited[i][j]) {
				ret.push_back(BFS(j, i));
				cnt++;
			}
		}
	}
	sort(ret.begin(), ret.end());
	cout << cnt << '\n';
	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << ' ';
	}
	return 0;
}
