#define V 10
#include "my_mat.h"


int main() {
    Matrix *matrix = malloc(sizeof(Matrix));
    if (matrix == NULL)
        printf("error \n");
    int b1, b2;
    int c1, c2;
    char action;
    bool resB;
    int resC = 0;
    scanf("%c", &action);
    while (action != 'D') {
        if (action == 'A') {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    scanf("%d", &matrix->edge[i][j]);
                }
            }
        } else if (action == 'B') {
            scanf("%d %d", &b1, &b2);
            resB = B(matrix, b1, b2);
            if (resB == 0) {
                printf("False\n");
            } else {
                printf("True\n");
            }
        } else if (action == 'C') {
            scanf("%d %d", &c1, &c2);
            resC = C(matrix, c1, c2);
            printf("%d \n", resC);
        } else if (action == ' ') {
            &action + 1;
        }
        scanf("%c", &action);
    }
    return 0;
}