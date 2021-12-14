#include<stdio.h>

struct nadt
{
    int size;
    int arr[100];
};

void init(struct nadt *n, int size);
void insertElements(struct nadt *n, int x[]);
void selSort(struct nadt *n);
void shellSort(struct nadt *n);
void display(struct nadt *n);


