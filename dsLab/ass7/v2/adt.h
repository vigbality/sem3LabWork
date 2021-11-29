#include<stdio.h>	
#include<stdlib.h>


struct word{
	char *word;
	char *meaning;
};



struct avl{
	struct word data;	
	int height;
	struct avl *left, *right;
};
int height(struct avl *t);
int getDiff(struct avl *t);
int max(int a, int b);
struct avl *SRwithLeft(struct avl *k2);
struct avl *SRwithright(struct avl *k2);
struct avl *DRwithLeft(struct avl *k3);
struct avl *DRwithRight(struct avl *k3);
struct avl *insertNode(struct avl *t, struct word x);
//struct bst *deleteNode(struct bst *t, int x);
void inorder(struct avl *t);
struct avl *find(struct avl *t, char *word);
//void levelorder(struct avl *t);
//struct bst *find(struct bst *t, int x);
//struct bst *findMin(struct bst *t);

