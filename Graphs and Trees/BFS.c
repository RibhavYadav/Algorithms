#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define size 5
int q[size], fr = -1, rear = -1, visited[size];
int adjMatrix[size][size] = {
        {0, 0, 1, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 1, 0, 0, 0},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0}
};

bool isEmpty() {
    return fr == -1 || rear == -1;
}


void enqueue(int elm) {
    if (rear == size - 1) {
        return;
    } else {
        if (fr == -1) {
            fr = 0;
        }
        q[++rear] = elm;
    }
}

int dequeue() {
    int elm;
    if (isEmpty()) {
        return -1;
    } else {
        elm = q[fr++];
        if (fr > rear) {
            fr = rear = -1;
        }
    }
    return elm;
}


void BFS(int node) {
    enqueue(node);
    visited[node] = 1;
    while (!isEmpty()) {
        int elm = dequeue();
        printf("%d ", elm);
        for (int i = 0; i < size; i++) {
            if (!visited[i] && adjMatrix[elm][i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}


void main() {
    BFS(0);
}
