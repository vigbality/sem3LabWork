#include<stdio.h>
struct cityAdt{
    int mat[20][20], size;
};
void create(struct cityAdt *g);
void visit(int *ptr, int v);
void BFS(struct cityAdt *g, int start);
void DFS(struct cityAdt *g, int start);