#include <iostream>

#define FOR(i, n) for (int i = 0; i < n; i++)

using namespace std;

string origin[8] = {
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB"
	};

int compare(string*, int, int);

int main(void) {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin >> N >> M;

	string board[50];
	FOR(i, N) {
		cin >> board[i];
	}

	int change = 64;
	int x;
	FOR(i, N - 7) {
		FOR(j, M - 7) {
			x = compare(board, i, j);
			if (x < change) change = x;
		}
	}

	cout << change;
    return 0;
}

int compare(string* myString, int a, int b) {
	int z = 0;
	FOR(i, 8) {
		FOR(j, 8) {
			if (myString[a + i][b + j] != origin[i][j]) {
				z++;
			}
		}
	}
	if (z < 64 - z) return z;
	else return 64 - z;
}
