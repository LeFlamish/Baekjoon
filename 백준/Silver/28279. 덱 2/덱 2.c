#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 1000002
typedef int element;
typedef struct {
    int front, rear, size;
    element* data;
} DequeType;

void init_deque(DequeType* D) {
    D->front = D->rear = D->size = 0;
    D->data = (element*)malloc(MAX * sizeof(element));
}

bool is_empty(DequeType* D) {
    return (D->front == D->rear);
}

bool is_full(DequeType* D) {
    return (D->front == (D->rear + 1) % MAX);
}

element front(DequeType* D) {
    if (!is_empty(D)) {
        return D->data[D->front];
    }
    return -1; // 에러 처리를 위해 -1 반환
}

element rear(DequeType* D) {
    if (!is_empty(D)) {
        return D->data[(D->rear - 1 + MAX) % MAX];
    }
    return -1; // 에러 처리를 위해 -1 반환
}

void push_front(DequeType* D, element item) {
    if (!is_full(D)) {
        D->size++;
        D->front = (D->front - 1 + MAX) % MAX;
        D->data[D->front] = item;
    }
}

element pop_front(DequeType* D) {
    if (!is_empty(D)) {
        D->size--;
        element tmp = front(D);
        D->front = (D->front + 1) % MAX;  // front를 모듈로 연산으로 업데이트
        return tmp;
    }
    return -1;  // 비어있는 경우 -1 반환
}

void push_back(DequeType* D, element item) {
    if (!is_full(D)) {
        D->size++;
        D->data[D->rear] = item;
        D->rear = (D->rear + 1) % MAX;
    }
}

element pop_back(DequeType* D) {
    if (!is_empty(D)) {
        D->size--;
        D->rear = (D->rear - 1 + MAX) % MAX;  // rear를 모듈로 연산으로 업데이트
        return D->data[D->rear];
    }
    return -1;  // 비어있는 경우 -1 반환
}

int N, order;
DequeType D;

int main() {
    init_deque(&D);
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &order);
        if (order == 1) {
            int x;
            scanf("%d", &x);
            push_front(&D, x);
        }
        else if (order == 2) {
            int x;
            scanf("%d", &x);
            push_back(&D, x);
        }
        else if (order == 3) {
            printf("%d\n", pop_front(&D));
        }
        else if (order == 4) {
            printf("%d\n", pop_back(&D));
        }
        else if (order == 5) {
            printf("%d\n", D.size);
        }
        else if (order == 6) {
            printf("%d\n", is_empty(&D) ? 1 : 0);
        }
        else if (order == 7) {
            printf("%d\n", front(&D));
        }
        else if (order == 8) {
            printf("%d\n", rear(&D));
        }
    }

    free(D.data);
    return 0;
}