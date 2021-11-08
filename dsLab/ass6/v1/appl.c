#include "impl.h"


int main(){
	struct bst *t = (struct bst*) malloc(sizeof(struct bst)); t=NULL;
	t=insertNode(t,29);
	t=insertNode(t,23);
	t=insertNode(t,4);
	t=insertNode(t,13);
	t=insertNode(t,39);
	t=insertNode(t,31);
	t=insertNode(t,45);	
	t=insertNode(t,56);
	t=insertNode(t,49);
	inorder(t); printf("\n");
	levelorder(t);
	printf("Min: %d\n", findMin(t)->data);
	if(find(t,13)) printf("13 is FOUND\n"); else printf("NOT FOUND\n");
	if(find(t,3)) printf("3 is FOUND\n"); else printf("NOT FOUND\n");		
}
