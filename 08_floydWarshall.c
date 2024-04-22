#include <stdio.h>
#include <conio.h>

#define V 4 // Number of vertices in the graph
#define INF 9999 // Infinity

// Function to print the solution matrix
void printSolution(int dist[][V]) {
    printf("The following matrix shows the shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}

// Floyd Warshall algorithm
void floydWarshall(int graph[][V]) {
    int dist[V][V];
    int i, j, k;
    // Initialize the solution matrix
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Update dist[][] if vertex k is on the shortest path from i to j
    for (k = 0; k < V; k++) {
        // Pick all vertices as source one by one
        for (i = 0; i < V; i++) {
            // Pick all vertices as destination for the above picked source
            for (j = 0; j < V; j++) {
                // If vertex k is on the shortest path from i to j,
                // then update the value of dist[i][j]
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the shortest distance matrix
    printSolution(dist);
}

int main() {
    // Example graph represented as an adjacency matrix
    int graph[V][V] = {{0, 3, 6, 8},
                       {3, 0, 2, 4},
                       {6, 2, 0, 1},
                       {8, 4, 1, 0}};
    clrscr(); // Clear the screen
    // Run Floyd Warshall algorithm
    floydWarshall(graph);
    getch(); // Wait for a key press before exiting
    return 0;
}
