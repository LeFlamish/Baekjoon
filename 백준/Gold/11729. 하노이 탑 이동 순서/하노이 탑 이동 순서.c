#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int N, ret;

void hanoiTower(int from, int tmp, int to, int n) {
	if (n == 1) printf("%d %d\n", from, to);
	else {
		hanoiTower(from, to, tmp, n - 1);
		printf("%d %d\n", from, to);
		hanoiTower(tmp, from, to, n - 1);
	}
}

int main() {
	scanf("%d", &N);
	ret = pow(2, N) - 1;
	printf("%d\n", ret);
	hanoiTower(1, 2, 3, N);
	return 0;
}