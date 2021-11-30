#include "adt.h"
#include<string.h>

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

struct avl *insertNode(struct avl *t, struct word x){
	if(t==NULL){
		t=(struct avl *)malloc(sizeof(struct avl));	
		t->data=x; t->height=1;
		t->left=t->right=NULL;
	}
	else if(strcmp(x.word,t->data.word)<0) t->left=insertNode(t->left, x);
	else if(strcmp(x.word,t->data.word)>0) t->right=insertNode(t->right, x);
	else{printf("Key alreadye exists!\n");return 0;}
	t->height = 1 + max(height(t->left),height(t->right));
	
	int diff = getDiff(t);
	if(diff>1 && strcmp(x.word,t->left->data.word)<0) return SRwithLeft(t);	
	else if(diff<-1 && strcmp(x.word,t->right->data.word)>0) return SRwithRight(t);
	else if(diff>1 && strcmp(x.word,t->left->data.word)>0) return DRwithLeft(t);
	else if(diff<-1 && strcmp(x.word,t->right->data.word)<0) return DRwithRight(t);

	return t;
}

void inorder(struct avl *t){
	if(t->left!=NULL) inorder(t->left);
	printf("%s  -  %s",t->data.word,t->data.meaning); printf("\n");
	if(t->right!=NULL) inorder(t->right);
}

struct avl *find(struct avl *t, char *word){
	if(t==NULL) return NULL;
	else if(strcmp(word,t->data.word)==0) return t;
	else if(strcmp(word,t->data.word)<0) return find(t->left, word);
	else if(strcmp(word,t->data.word)>0) return find(t->right, word);
}