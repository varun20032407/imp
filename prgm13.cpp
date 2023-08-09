#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_NODES 100

// Structure to represent a graph node and its weight
struct Node {
    int vertex;
    int weight;
    struct Node *next;
};

// Structure to represent a graph
struct Graph {
    struct Node *adjList[MAX_NODES];
};

// Initialize a graph
void initGraph(struct Graph *graph, int numNodes) {
    for (int i = 0; i < numNodes; ++i) {
        graph->adjList[i] = NULL;
    }
}

// Add an edge to the graph
void addEdge(struct Graph *graph, int src, int dest, int weight) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = dest;
    newNode->weight = weight;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

// Dijkstra's shortest path algorithm
void dijkstra(struct Graph *graph, int numNodes, int startNode, int endNode) {
    int dist[numNodes];
    bool visited[numNodes];

    for (int i = 0; i < numNodes; ++i) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    dist[startNode] = 0;

    for (int count = 0; count < numNodes - 1; ++count) {
        int u = -1;
        for (int i = 0; i < numNodes; ++i) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }

        visited[u] = true;
        struct Node *neighbor = graph->adjList[u];
        while (neighbor != NULL) {
            if (dist[u] + neighbor->weight < dist[neighbor->vertex]) {
                dist[neighbor->vertex] = dist[u] + neighbor->weight;
            }
            neighbor = neighbor->next;
        }
    }

    if (dist[endNode] == INT_MAX) {
        printf("No path from node %d to node %d\n", startNode, endNode);
    } else {
        printf("Shortest path from node %d to node %d: %d\n", startNode, endNode, dist[endNode]);
    }
}

int main() {
    int numNodes, numEdges;

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    struct Graph graph;
    initGraph(&graph, numNodes);

    printf("Enter the edges (source, destination, weight):\n");
    for (int i = 0; i < numEdges; ++i) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(&graph, src, dest, weight);
    }

    int startNode, endNode;
    printf("Enter the start node: ");
    scanf("%d", &startNode);
    printf("Enter the end node: ");
    scanf("%d", &endNode);

    dijkstra(&graph, numNodes, startNode, endNode);

    return 0;
}

