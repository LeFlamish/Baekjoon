#include <iostream>
#include <cstring>
using namespace std;
#define R 0
#define S 1
#define P 2

int T, N;
string robot[11];
bool RSP[3];
bool isWin[11];

void init() {
	memset(RSP, false, sizeof(RSP));
	memset(isWin, true, sizeof(isWin));

	cin >> N;
	for (int n = 1; n <= N; n++) {
		cin >> robot[n];
	}
}

void solve() {
    for (int i = 0; i < robot[1].size(); i++) {
        memset(RSP, false, sizeof(RSP));

        for (int n = 1; n <= N; n++) {
            if (!isWin[n]) continue;
            if (robot[n][i] == 'R') RSP[R] = true;
            else if (robot[n][i] == 'S') RSP[S] = true;
            else if (robot[n][i] == 'P') RSP[P] = true;
        }

        if (RSP[R] && RSP[S] && RSP[P]) continue;
        if (RSP[R] && RSP[S]) {
            for (int n = 1; n <= N; n++) {
                if (isWin[n] && robot[n][i] == 'S') isWin[n] = false;
            }
        }
        else if (RSP[R] && RSP[P]) {
            for (int n = 1; n <= N; n++) {
                if (isWin[n] && robot[n][i] == 'R') isWin[n] = false;
            }
        }
        else if (RSP[S] && RSP[P]) {
            for (int n = 1; n <= N; n++) {
                if (isWin[n] && robot[n][i] == 'P') isWin[n] = false;
            }
        }
    }

	int cnt = 0, ret;
	for (int n = 1; n <= N; n++) {
		if (isWin[n]) {
			cnt++;
			ret = n;
		}
	}
	
	if (cnt == 1) cout << ret << '\n';
	else cout << 0 << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	for (int t = 0; t < T; t++) {
		init();
		solve();
	}
	return 0;
}