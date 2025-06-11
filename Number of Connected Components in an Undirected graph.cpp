#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 2000  // Adjust based on problem constraints

// Adjacency list structure
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// DFS function
void dfs(Node* graph[], bool visited[], int v) {
    visited[v] = true;
    Node* temp = graph[v];
    while (temp) {
        if (!visited[temp->vertex]) {
            dfs(graph, visited, temp->vertex);
        }
        temp = temp->next;
    }
}

// Main function to count components
int countComponents(int n, int edges[][2], int edgesSize) {
    Node* graph[MAX_NODES] = {NULL};
    bool visited[MAX_NODES] = {false};

    // Build graph
    for (int i = 0; i < edgesSize; i++) {
        int a = edges[i][0];
        int b = edges[i][1];

        Node* newNodeA = createNode(b);
        newNodeA->next = graph[a];
        graph[a] = newNodeA;

        Node* newNodeB = createNode(a);
        newNodeB->next = graph[b];
        graph[b] = newNodeB;
    }

    // Count connected components
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(graph, visited, i);
            count++;
        }
    }

    return count;
}

// Example usage
int main() {
    int n = 5;
    int edges[][2] = {{0, 1}, {1, 2}, {3, 4}};
    int edgesSize = sizeof(edges) / sizeof(edges[0]);

    int result = countComponents(n, edges, edgesSize);
    printf("Number of connected components: %d\n", result);

    return 0;
}

