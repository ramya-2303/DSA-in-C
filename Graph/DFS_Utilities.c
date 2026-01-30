//* This program performs Depth-First Search operations on an undirected graph:
 //1. Checks if the graph is connected.
 //2. Finds a path between two vertices.
 //3. Finds all connected components.

#include <stdio.h>
#define MAX 100

int stack[MAX], top = -1;

void push(int x) { stack[++top] = x; }
int pop() { return stack[top--]; }
int isEmpty() { return top == -1; }

// DFS for connectivity
void dfs(int v, int adj[MAX][MAX], int n, int visited[]) {
    visited[v] = 1;
    for (int i = 0; i < n; i++)
        if (adj[v][i] && !visited[i])
            dfs(i, adj, n, visited);
}

// DFS for path tracking
void dfs_path(int v, int adj[MAX][MAX], int n, int visited[], int pred[]) {
    visited[v] = 1;
    for (int i = 0; i < n; i++)
        if (adj[v][i] && !visited[i]) {
            pred[i] = v;
            dfs_path(i, adj, n, visited, pred);
        }
}

// DFS for connected components
void dfs_component(int v, int adj[MAX][MAX], int n, int visited[], int comp[], int id) {
    visited[v] = 1;
    comp[v] = id;
    for (int i = 0; i < n; i++)
        if (adj[v][i] && !visited[i])
            dfs_component(i, adj, n, visited, comp, id);
}

// Initialize array to a value
void init_array(int arr[], int n, int val) {
    for (int i = 0; i < n; i++) arr[i] = val;
}

int main() {
    int adj[MAX][MAX], visited[MAX], pred[MAX], comp[MAX];
    int n, e, v1, v2, choice;

    printf("Vertices and edges: ");
    scanf("%d %d", &n, &e);

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter edges:\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &v1, &v2);
        adj[v1][v2] = adj[v2][v1] = 1;
    }

    printf("\n1. Check connectivity\n2. Find path\n3. Find components\nChoice: ");
    scanf("%d", &choice);

    if (choice == 1) {  // Connectivity
        init_array(visited, n, 0);
        dfs(0, adj, n, visited);

        int connected = 1;
        for (int i = 0; i < n; i++)
            if (!visited[i]) { connected = 0; break; }

        printf("Graph is %sconnected\n", connected ? "" : "not ");
    }
    else if (choice == 2) {  // Path
        int src, dest;
        printf("Source and destination: ");
        scanf("%d %d", &src, &dest);

        init_array(visited, n, 0);
        init_array(pred, n, -1);

        dfs_path(src, adj, n, visited, pred);

        if (!visited[dest]) {
            printf("Path does not exist\n");
        } else {
            int cur = dest;
            while (cur != src) { push(cur); cur = pred[cur]; }
            printf("Path: %d", src);
            while (!isEmpty()) printf(" -> %d", pop());
            printf("\n");
        }
    }
    else if (choice == 3) {  // Components
        init_array(visited, n, 0);
        init_array(comp, n, 0);

        int count = 0;
        for (int i = 0; i < n; i++)
            if (!visited[i]) dfs_component(i, adj, n, visited, comp, ++count);

        printf("Total components = %d\n", count);
        for (int i = 0; i < n; i++) printf("%d -> %d\n", i, comp[i]);
    }

    return 0;
}
