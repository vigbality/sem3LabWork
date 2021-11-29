#include <stdio.h>

struct empData{
    char id;
    int salary;
};

struct heap{
    struct empData arr[100];
    int size, curr;
};

void init(struct heap *h, int size);
void display(struct heap *h);
void  insert(struct heap *h, struct empData data);
struct empData del(struct heap *h);