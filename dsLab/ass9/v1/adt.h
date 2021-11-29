#include <stdio.h>
struct heap{
    int arr[100], size, curr;
};

void init(struct heap *h, int size);
void display(struct heap *h);
void  insert(struct heap *h, int data);
int del(struct heap *h);