#include "adt.h"


struct bst *insertNode(struct bst *t, int x){
	if(t==NULL){
		t=(struct bst *)malloc(sizeof(struct bst));
		t->data=x;
		t->left=t->right=NULL;
	}
	else if(x<t->data) t->left=insertNode(t->left, x);
	else if(x>t->data) t->right=insertNode(t->right, x);
	return t;
}


struct bst *find(struct bst *t, int x){
	if(t==NULL) return NULL;
	else if(x==t->data) return t;
	else if(x<t->data) return find(t->left, x);
	else if(x>t->data) return find(t->right, x);
}

struct bst *findMin(struct bst *t){
	if(t==NULL) return NULL;
	while(t->left!=NULL){
		return findMin(t->left);
	}
	return t;
}


struct bst *deleteNode(struct bst *t, int x){
	struct bst *temp;
	if(x<t->data) t->left=deleteNode(t->left, x);
	else if(x>t->data) t->right =deleteNode(t->right, x);
	else if(t->left && t->right){
		temp=findMin(t->right);
		t->data=temp->data;
		t->right=deleteNode(t->right,temp->data);
	}
	else{
		if(t->right==NULL) t=t->left;
		else if(t->left==NULL) t=t->right;
		else t=NULL;
	}
	free(temp);temp=NULL;
	return t;
}


void inorder(struct bst *t){
	if(t->left!=NULL) inorder(t->left);
	printf("%d ",t->data);
	if(t->right!=NULL) inorder(t->right);
}

void inorderArr(struct bst *t, int *arr, int *i){
	if(t->left!=NULL) inorderArr(t->left,arr,i);
	arr[(*i)++]=t->data;
	if(t->right!=NULL) inorderArr(t->right,arr,i);
}

void printLevel(struct bst *t, int i){
	if(i==0) printf("%d ",t->data);
	else if(i>0){
		if(t->left!=NULL) printLevel(t->left, i-1);
		printf("  ");
		if(t->right!=NULL) printLevel(t->right, i-1);
	}
}

void getLevelCount(struct bst *t, int i, int *count){
	if(i==0) (*count)++;
	else if(i>0){
		if(t->left!=NULL) getLevelCount(t->left, i-1,count);
		if(t->right!=NULL) getLevelCount(t->right, i-1,count);
	}
}

int getHeight(struct bst *t){
	if(t==NULL) return 0;
	else{
		int h1=getHeight(t->left), h2=getHeight(t->right);
		if(h1>h2) return 1 + h1;
		else return 1 + h2;
	}	
}

void levelorder(struct bst *t){
	printf("\n*************\n");	
	for(int i=0; i<getHeight(t);i++){
		printf("\n\nLevel %d:\n\n",i);
		printLevel(t,i);
	}
	printf("\n*************\n");
}

