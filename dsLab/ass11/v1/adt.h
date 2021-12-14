#include<stdio.h>

struct nadt
{
    int size;
    int arr[100];
};

void init(struct nadt *n, int size);
void insertElements(struct nadt *n, int x[]);
int lSearch(struct nadt *n, int key);
int bSearch(struct nadt *n, int key);
void display(struct nadt *n);


