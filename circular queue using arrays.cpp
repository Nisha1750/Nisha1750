#include <stdio.h>
#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1, rear = -1;

int is_empty() {
    return front == -1;
}

int is_full() {
    return (rear + 1) % MAX_SIZE == front;
}

void enqueue(int item) {
    if (is_full()) {
        printf("Queue is full\n");
        return;
    }
    if (is_empty()) {
        front = 0;
    }
    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = item;
}

int dequeue() {
    if (is_empty()) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = queue[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
    return item;
}

int find(int item) {
    if (is_empty()) {
        printf("Queue is empty\n");
        return 0;
    }
    int i = front;
    while (i != rear) {
        if (queue[i] == item) {
            return 1;
        }
        i = (i + 1) % MAX_SIZE;
    }
    if (queue[i] == item) {
        return 1;
    }
    return 0;
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    printf("Queue after enqueueing 5 elements: ");
    int i = front;
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", queue[i]);
    printf("Finding element 3 in the queue: %s\n", find(3) ? "Found" : "Not Found");
    printf("Dequeue: %d\n", dequeue());
    printf("Dequeue: %d\n", dequeue());
    printf("Queue after dequeueing 2 elements: ");
    i = front;
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", queue[i]);
    return 0;
}
