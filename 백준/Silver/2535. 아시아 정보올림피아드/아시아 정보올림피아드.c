#include <stdio.h>

int main(void) {
  int score[100][3] = {0}, country[100] = {0}, order[100][3] = {0}, Max[100] = {0};
  int n = 0, count = 0;

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", &score[i][0], &score[i][1], &score[i][2]);
  }

  for (int i = 0; i < n; i++) {
    Max[i] = score[i][2];
  }

  for (int i = 0; i < n-1; i++) {
      for (int j = 0; j < n-i-1; j++) {
          if (Max[j] < Max[j+1]) {
              int temp = Max[j];
              Max[j] = Max[j+1];
              Max[j+1] = temp;
          }
      }
  }

  for (int i = 0; i < n; i++) {
    order[i][2] = Max[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (order[i][2] == score[j][2]) {
        order[i][0] = score[j][0];
        order[i][1] = score[j][1];
      }
    }
  }

  for (int i = 0; i < n; i++) {
    if (country[order[i][0]-1] < 2) {
      printf("%d %d\n", order[i][0], order[i][1]);
      count++;
    }
    if (count == 3) break;
    country[order[i][0]-1]++;
  }
  
  return 0;
}