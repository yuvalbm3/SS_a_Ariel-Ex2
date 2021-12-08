#include <stdio.h>
#include <stdbool.h>
#define V 10
#define INF 99999

typedef struct matrix{
    int edge[V][V];
}Matrix;

void printSolution(int dist[][V]);
int printShortest(int dist[][V], int start, int target){
    if(dist[start][target]== 0)
        return -1;
    else
        return dist[start][target];
}

int floydWarshall (Matrix* dist, int start, int target){
    int copy[V][V], i, j, k;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++) {
            copy[i][j] = dist->edge[i][j];
        }
    for(int k = 0; k < V; k++){
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if (copy[k][j] == 0 || copy[i][k] == 0){
                    continue;
                }
                if(copy[i][j] == 0 && i != j){
                    copy[i][j] = copy[i][k] + copy[k][j];
                }
                else if(copy[i][j] > copy[i][k] + copy[k][j]){
                    copy[i][j] = copy[i][k] + copy[k][j];
                }
            }
        }
    }
    return printShortest(copy, start, target);
}
void printSolution(int dist[][V])
{
    printf ("The following matrix shows the shortest distances"
            " between every pair of vertices \n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

int A(Matrix* matrix) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &matrix->edge[i][j]);
        }
    }
}

int B(Matrix* matrix, int b1, int b2){
    if(b1 == b2){
        return false;
    }
    if(floydWarshall(matrix, b1, b2) == -1){
        return false;
    }else{
        return true;
    }
}
int C(Matrix* matrix, int c1, int c2){
    int a = floydWarshall(matrix, c1, c2);
    if(a == -1){
        return -1;
    } else{
        return a;
    }
}
