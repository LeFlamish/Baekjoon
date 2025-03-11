#include <iostream>
using namespace std;
struct Belt {
	int dur;
	bool onRobot;
};

int N, K;
Belt belt[2][101];
Belt tmp[2][101];

void check() {
	cout << "====================\n";
	for (int y = 0; y < 2; y++) {
		for (int x = 1; x <= N; x++) {
			cout << belt[y][x].dur << ' ';
		}
		cout << '\n';
	}
	cout << "====================\n";
}

void init() {
	cin >> N >> K;
	for (int x = 1; x <= N; x++) cin >> belt[0][x].dur;
	for (int x = N; x >= 1; x--) cin >> belt[1][x].dur;
}

void copyToBelt() {
	for (int y = 0; y < 2; y++) {
		for (int x = 1; x <= N; x++) {
			belt[y][x] = tmp[y][x];
		}
	}
}

void rotate() {
	for (int x = 1; x < N; x++) {
		tmp[0][x + 1] = belt[0][x];
		tmp[1][x] = belt[1][x + 1];
	}
	tmp[1][N] = belt[0][N];
	tmp[0][1] = belt[1][1];
	copyToBelt();
}

void moveRobot() {
	belt[0][N].onRobot = false;
	for (int x = N - 1; x > 0; x--) {
		if (belt[0][x].onRobot && !belt[0][x + 1].onRobot && belt[0][x + 1].dur) {
			belt[0][x].onRobot = false;
			belt[0][x + 1].onRobot = true;
			belt[0][x + 1].dur--;
		}
	}
	belt[0][N].onRobot = false;
}

void putRobot() {
	if (belt[0][1].dur) {
		belt[0][1].onRobot = true;
		belt[0][1].dur--;
	}
}

bool checkEnd() {
	int cnt = 0;
	for (int y = 0; y < 2; y++) {
		for (int x = 1; x <= N; x++) {
			if (!belt[y][x].dur) cnt++;
		}
	}
	if (cnt >= K) return true;
	return false;
}

void solve() {
	int t = 0;
	while (1) {
		t++;
		rotate();
		moveRobot();
		putRobot();
		//check();
		if (checkEnd()) break;
	}
	cout << t;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	solve();
	return 0;
}