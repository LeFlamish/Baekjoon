#include <iostream>
#include <queue>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;
typedef pair<int, int> CD;
#define X first
#define Y second
struct Shark {
	int X, Y;
	int Size = 2;
	int Eat;
	int Total;
};

int N;
int board[20][20];
int visited[20][20];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };
vector<CD> fish;
Shark shark;

bool compare(const CD& A, const CD& B) {
	if (A.Y == B.Y) return A.X < B.X;
	return A.Y < B.Y;
}

void init() {
	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> board[y][x];
			if (board[y][x] == 9) {
				board[y][x] = 0;
				shark.X = x;
				shark.Y = y;
			}
		}
	}
}

void updateShark() {
	sort(fish.begin(), fish.end(), compare);
	int x = fish[0].X;
	int y = fish[0].Y;
	board[y][x] = 0;
	shark.X = x;
	shark.Y = y;
	shark.Eat++;
	if (shark.Eat == shark.Size) {
		shark.Size++;
		shark.Eat = 0;
	}
	shark.Total += visited[y][x] - 1;
	fish.clear();
}

bool eatFish() {
	memset(visited, 0, sizeof(visited));
	int flag = INT_MAX;
	bool canEat = false;
	visited[shark.Y][shark.X] = 1;
	queue<CD> Q;
	Q.push(make_pair(shark.X, shark.Y));
	while (!Q.empty()) {
		CD cur = Q.front(); Q.pop();
		if (visited[cur.Y][cur.X] > flag) break;
		if (board[cur.Y][cur.X] > 0 && board[cur.Y][cur.X] < shark.Size) {
			canEat = true;
			fish.push_back(cur);
			flag = visited[cur.Y][cur.X];
		}
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (visited[ny][nx] > 0 || board[ny][nx] > shark.Size) continue;
			visited[ny][nx] = visited[cur.Y][cur.X] + 1;
			Q.push(make_pair(nx, ny));
		}
	}
	return canEat;
}

void solve() {
	while (eatFish()) {
		updateShark();
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	solve();
	cout << shark.Total;
	return 0;
}