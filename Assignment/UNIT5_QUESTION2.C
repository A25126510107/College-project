#include <stdio.h>

#define INF 999

int main() {
    int graph[10][10], distance[10], visited[10];
    int n, source, i, j, count, min, next;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter weighted adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter source vertex: ");
    scanf("%d", &source);

    for (i = 0; i < n; i++) {
        distance[i] = graph[source][i];
        visited[i] = 0;
    }

    distance[source] = 0;
    visited[source] = 1;

    for (count = 1; count < n; count++) {
        min = INF;
        next = -1;

        for (i = 0; i < n; i++) {
            if (!visited[i] && distance[i] < min) {
                min = distance[i];
                next = i;
            }
        }

        if (next == -1)
            break;

        visited[next] = 1;

        for (i = 0; i < n; i++) {
            if (!visited[i] &&
                distance[next] + graph[next][i] < distance[i]) {
                distance[i] = distance[next] + graph[next][i];
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", source);

    for (i = 0; i < n; i++)
        printf("To %d = %d\n", i, distance[i]);

    return 0;
}