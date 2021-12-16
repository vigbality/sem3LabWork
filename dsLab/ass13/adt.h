#include<stdio.h>

struct city{
    int dist[30][30], pred[30][30], n;
};

void create(struct city *c);
void display(struct city *c);
void floyd(struct city *c);
void displayPath(struct city *c, int s, int d);