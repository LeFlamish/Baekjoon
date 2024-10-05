#include <stdio.h>

int main(void) {
  int N;
  long long answer = 1;
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    answer *= i;
  }
  printf("%lld", answer);
  return 0;
}