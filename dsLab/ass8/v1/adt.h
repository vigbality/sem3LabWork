#include<stdio.h>	
#include<stdlib.h>

struct avl{
	int data, height;
	struct avl *left, *right;
};
int height(struct avl *t);
int getDiff(struct avl *t);
int max(int a, int b);
struct avl *SRwithLeft(struct avl *k2);
struct avl *SRwithright(struct avl *k2);
struct avl *DRwithLeft(struct avl *k3);
struct avl *DRwithRight(struct avl *k3);
struct avl *insertNode(struct avl *t, int x);
void inorder(struct avl *t);
void levelorder(struct avl *t);
