#include<stdio.h>

#define size 5
int visited[size], top = -1;
int adjMatrix[size][size] = {
        {0, 0, 1, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 1, 0, 0, 0},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0}
};

void DFS(int node) {
    visited[node] = 1;
    printf("%d ", node);
    for (int i = 0; i < size; i++) {
        if (!visited[i] && adjMatrix[node][i]) {
            DFS(i);
        }
    }
}

void main() {
    for (int i = 0; i < size; i++)
        visited[i] = 0;
    printf("Order is: \n");
    DFS(0);
}
