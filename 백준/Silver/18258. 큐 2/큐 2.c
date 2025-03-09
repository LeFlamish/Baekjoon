#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 2000000
typedef int element;
typedef struct {
	int front, rear;
	element data[MAX];
} QueueType;

void init_queue(QueueType* Q) {
	Q->front = Q->rear = 0;
}

bool is_empty(QueueType* Q) {
	return (Q->front == Q->rear);
}

bool is_full(QueueType* Q) {
	return (Q->rear + 1) % MAX == Q->front;
}

void enqueue(QueueType* Q, element item) {
	if (is_full(Q)) return;
	Q->data[Q->rear] = item;
	Q->rear = (Q->rear + 1) % MAX;
}

void dequeue(QueueType* Q) {
	Q->front = (Q->front + 1) % MAX;
}

element front(QueueType* Q) {
	return Q->data[Q->front];
}

element back(QueueType* Q) {
	return Q->data[Q->rear - 1];
}

int N;
QueueType Q;

int main() {
	int size = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		char order[10];
		scanf("%s", order);
		if (strcmp(order, "push") == 0) {
			int x;
			scanf("%d", &x);
			enqueue(&Q, x);
			size++;
		}
		else if (strcmp(order, "front") == 0) {
			if (is_empty(&Q)) printf("-1\n");
			else {
				printf("%d\n", front(&Q));
			}
		}
		else if (strcmp(order, "back") == 0) {
			if (is_empty(&Q)) printf("-1\n");
			else {
				printf("%d\n", back(&Q));
			}
		}
		else if (strcmp(order, "size") == 0) {
			printf("%d\n", size);
		}
		else if (strcmp(order, "empty") == 0) {
			if (is_empty(&Q)) printf("1\n");
			else printf("0\n");
		}
		else if (strcmp(order, "pop") == 0) {
			if (is_empty(&Q)) printf("-1\n");
			else {
				printf("%d\n", front(&Q));
				dequeue(&Q);
				size--;
			}
		}
	}
	return 0;
}