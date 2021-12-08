//
// Created by yuval on 02/12/2021.
//

#ifndef MY_MAT_H
#define MY_MAT_H
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#define V 10
#define INF 99999

typedef struct Matrix{
    int edge[V][V];
}Matrix;

int Dijkstra(Matrix* graph, int start, int target);
int A(Matrix* matrix);
int B(Matrix* matrix, int b1, int b2);
int C(Matrix* matrix, int c1, int c2);
int D();
int helpC(Matrix* graph, int start, int target);

#endif //MY_MAT_H
