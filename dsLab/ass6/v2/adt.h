#include<stdio.h>	
#include<stdlib.h>

struct bst{
	int data;
	struct bst *left, *right;
};

struct bst *insertNode(struct bst *t, int x);
struct bst *deleteNode(struct bst *t, int x);
void inorder(struct bst *t);
void levelorder(struct bst *t);
struct bst *find(struct bst *t, int x);
struct bst *findMin(struct bst *t);

