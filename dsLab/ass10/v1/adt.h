#include<stdio.h>
struct cityAdt{
    int mat[20][20], size;
};
void create(struct cityAdt *g);
void visit(int *ptr, int v);
void BFS(struct cityAdt *g);
void DFS(struct cityAdt *g);