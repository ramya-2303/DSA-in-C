//implementing Depth First Search traversal technique using C language
#include <stdio.h>
#define MAX 100

void dfs(int src, int adjMat[][MAX], int n, int *visited) {
    printf("%d ", src);
    visited[src] = 1;
    for (int j = 0; j < n; j++) {
        if (adjMat[src][j] == 1 && visited[j] == 0) {
            dfs(j, adjMat, n, visited);
        }
    }
}

void DFS(int adjMat[][MAX], int n) {
    int visited[MAX];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            dfs(i, adjMat, n, visited);
        }
    }
}

int main() {
    int Mat[MAX][MAX];
    int n, e, v1, v2;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            Mat[i][j] = 0;

    for (int i = 0; i < e; i++) {
        scanf("%d %d", &v1, &v2);
        Mat[v1][v2] = Mat[v2][v1] = 1;
    }

    printf("DFS Traversal:\n");
    DFS(Mat, n);

    return 0;
}
