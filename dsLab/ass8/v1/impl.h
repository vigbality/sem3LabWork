#include "adt.h"

int height(struct avl *t){
	if(t==NULL) return 0;
	return t->height;
}

int getDiff(struct avl *t){
	if(t==NULL) return 0;
	return height(t->left) - height(t->right);
}

int max(int a, int b){
	if(a>b) return a;
	else return b;
}

struct avl *SRwithLeft(struct avl *k2){
	struct avl *k1;
	k1=k2->left;
	k2->left=k1->right;
	k1->right=k2;
	k2->height= 1 + max(height(k2->left),height(k2->right));
	k1->height= 1 + max(height(k1->left),height(k1->right));
	return k1;	
}

struct avl *SRwithRight(struct avl *k2){
	struct avl *k1;
	k1=k2->right;
	k2->right=k1->left;
	k1->left=k2;
	k2->height= 1 + max(height(k2->left),height(k2->right));
	k1->height= 1 + max(height(k1->left),height(k1->right));
	return k1;	
}

struct avl *DRwithLeft(struct avl *k3){
	k3->left=SRwithRight(k3->left);
	return SRwithLeft(k3);	
}

struct avl *DRwithRight(struct avl *k3){
	k3->right=SRwithLeft(k3->right);
	return SRwithRight(k3);	
}

struct avl *insertNode(struct avl *t, int x){
	if(t==NULL){
		t=(struct avl *)malloc(sizeof(struct avl));
		t->data=x; t->height=1;
		t->left=t->right=NULL;
	}
	else if(x<t->data) t->left=insertNode(t->left, x);
	else if(x>t->data) t->right=insertNode(t->right, x);
	else{printf("Key alreadye exists!\n");return 0;}
	t->height = 1 + max(height(t->left),height(t->right));
	
	int diff = getDiff(t);
	if(diff>1 && x<t->left->data) return SRwithLeft(t);	
	else if(diff<-1 && x>t->right->data) return SRwithRight(t);
	else if(diff>1 && x>t->left->data) return DRwithLeft(t);
	else if(diff<-1 && x<t->right->data) return DRwithRight(t);

	return t;
}

void inorder(struct avl *t){
	if(t->left!=NULL) inorder(t->left);
	printf("%d ",t->data);
	if(t->right!=NULL) inorder(t->right);
}

void printLevel(struct avl *t, int i){
	if(i==0) printf("%d ",t->data);
	else if(i>0){
		if(t->left!=NULL) printLevel(t->left, i-1);
		printf("  ");
		if(t->right!=NULL) printLevel(t->right, i-1);
	}
}

int getHeight(struct avl *t){
	if(t==NULL) return 0;
	else{
		int h1=getHeight(t->left), h2=getHeight(t->right);
		if(h1>h2) return 1 + h1;
		else return 1 + h2;
	}	
}

void levelorder(struct avl *t){
	printf("\n*************\n");	
	for(int i=0; i<getHeight(t);i++){
		printf("\n\nLevel %d:\n\n",i);
		printLevel(t,i);
	}
	printf("\n*************\n");
}

