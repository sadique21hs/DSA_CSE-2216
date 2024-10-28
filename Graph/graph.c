#include <stdio.h>

int main() {
    int no_of_vertex;
    int graph[100][100] = {0}; 

    printf("Enter the number of vertices: ");
    scanf("%d", &no_of_vertex);

    
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < no_of_vertex; i++) {
        for (int j = 0; j < no_of_vertex; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    
    printf("The adjacency matrix is:\n");
    for (int i = 0; i < no_of_vertex; i++) {
        for (int j = 0; j < no_of_vertex; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n"); 
    }

    return 0;
}
