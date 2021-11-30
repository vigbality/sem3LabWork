#include "impl.h"


int main(){
	struct avl *t = (struct avl*) malloc(sizeof(struct avl)); t=NULL;
	t=insertNode(t,23);
	t=insertNode(t,12);
	t=insertNode(t,13);
	t=insertNode(t,4);
	t=insertNode(t,45);
	t=insertNode(t,54);
	printf("\n*************\n");
	inorder(t); printf("\n");
	levelorder(t);
}
