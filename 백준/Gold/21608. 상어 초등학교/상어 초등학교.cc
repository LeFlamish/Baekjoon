#include <bits/stdc++.h>
#define SIZE 21
using namespace std;

int N;
int board[SIZE][SIZE];
int dx[] = { 0, -1, 1, 0 };
int dy[] = { -1, 0, 0, 1 };
int seq[401];
int like[401][4];
int satisfy[] = { 0, 1, 10, 100, 1000 };

void init();
void setSeat();
int getScore();
int getSatisfy(int x, int y, int studNum);
int getEmpty(int x, int y);

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	setSeat();
	cout << getScore();
	return 0;
}

void init() {
	cin >> N;
	for (int i = 0; i < N * N; i++) {
		cin >> seq[i];
		for (int j = 0; j < 4; j++) {
			cin >> like[seq[i]][j];
		}
	}
}

void setSeat() {
	for (int i = 0; i < N * N; i++) {
		int nx = -1, ny = -1, likeMax = -1, emptyMax = -1;

		for (int y = 1; y <= N; y++) {
			for (int x = 1; x <= N; x++) {
				if (board[y][x] != 0) continue;

				int likeCount = getSatisfy(x, y, seq[i]);
				int emptyCount = getEmpty(x, y);

				// 좋아하는 학생 수가 많은 자리를 우선 선택
				if (likeCount > likeMax ||
					(likeCount == likeMax && emptyCount > emptyMax) ||
					(likeCount == likeMax && emptyCount == emptyMax &&
						(ny > y || (ny == y && nx > x)))) {
					nx = x;
					ny = y;
					likeMax = likeCount;
					emptyMax = emptyCount;
				}
			}
		}

		// 선택된 자리로 학생 배치
		board[ny][nx] = seq[i];
	}
}

int getScore() {
	int ret = 0;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			int cnt = 0;
			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
				for (int i = 0; i < 4; i++) {
					if (board[ny][nx] == like[board[y][x]][i]) cnt++;
				}
			}
			ret += satisfy[cnt];
		}
	}
	return ret;
}

int getSatisfy(int x, int y, int studNum) {
	int cnt = 0;
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
		for (int i = 0; i < 4; i++) {
			if (like[studNum][i] == board[ny][nx]) cnt++;
		}
	}
	return cnt;
}

int getEmpty(int x, int y) {
	int cnt = 0;
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
		if (board[ny][nx] == 0) cnt++;
	}
	return cnt;
}